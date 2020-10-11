#include "../PCH.h"
#include "SpriteComponent.h"
#include "../Game.h"
#include "TweeningComponent.h"

SpriteComponent::SpriteComponent(std::string textureId, bool isFixed)
{
    isAnimated = false;
    this->isFixed = isFixed;
    SetTexture(textureId);
}

SpriteComponent::SpriteComponent(std::string id, int numFrames, int animationSpeed, bool hasDirections, bool isFixed)
{
    isAnimated = true;
    this->numFrames = numFrames;
    this->animationSpeed = animationSpeed;
    this->isFixed = isFixed;
    if (hasDirections)
    {
        Animation downAnimation = Animation(0, numFrames, animationSpeed);
        Animation rightAnimation = Animation(1, numFrames, animationSpeed);
        Animation leftAnimation = Animation(2, numFrames, animationSpeed);
        Animation upAnimation = Animation(3, numFrames, animationSpeed);

        animations.emplace("DownAnimation", downAnimation);
        animations.emplace("RightAnimation", rightAnimation);
        animations.emplace("LeftAnimation", leftAnimation);
        animations.emplace("UpAnimation", upAnimation);


        this->animationIndex = 0;
        this->currentAnimationName = "DownAnimation";
    }
    else
    {
        Animation singleAnimation = Animation(0, numFrames, animationSpeed);
        animations.emplace("SingleAnimation", singleAnimation);
        this->animationIndex = 0;
        this->currentAnimationName = "SingleAnimation";
    }

    Play(this->currentAnimationName);
    SetTexture(id);
}

void SpriteComponent::SetTexture(std::string assetTextureId)
{
    texture = Game::assetManager->GetTexture(assetTextureId);
}

void SpriteComponent::Initialize()
{
    transform = owner->GetComponent<TransformComponent>();
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = transform->width;
    sourceRectangle.h = transform->height;
    destinationRectangle.w = static_cast<float>(transform->width * transform->scale);
    destinationRectangle.h = static_cast<float>(transform->height * transform->scale);
    originWidth = destinationRectangle.w;
    originHeight = destinationRectangle.h;
}

void SpriteComponent::ResetSize()
{
    destinationRectangle.w = originWidth;
    destinationRectangle.h = originHeight;
}

void SpriteComponent::Update(float deltaTime)
{
    if (isAnimated)
    {
        sourceRectangle.x = (sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames));
    }
    sourceRectangle.y = animationIndex * transform->height;

    destinationRectangle.x = transform->position.x - (isFixed ? 0 : Game::camera.x);
    destinationRectangle.y = transform->position.y - (isFixed ? 0 : Game::camera.y);
    
}

void SpriteComponent::Render()
{
    TextureManager::Draw(texture, sourceRectangle, destinationRectangle, spriteFlip);
}

void SpriteComponent::Play(std::string animationName)
{
    numFrames = animations[animationName].numFrames;
    animationIndex = animations[animationName].index;
    animationSpeed = animations[animationName].animationSpeed;
    currentAnimationName = animationName;
}
