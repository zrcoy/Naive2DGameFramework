#include "ColliderComponent.h"
#include "../TextureManager.h"
#include "../AssetManager.h"

ColliderComponent::ColliderComponent(std::string colliderTag, int x, int y, int width, int height, bool turnOnCollidingBox)
{
    this->colliderTag = colliderTag;
    this->colliderRect = { x,y,width,height };
    this->turnOnCollidingBox = turnOnCollidingBox;
}

void ColliderComponent::Initialize()
{
    if (owner->HasComponent<TransformComponent>())
    {
        transform = owner->GetComponent<TransformComponent>();
        sourceRect = { 0,0,transform->width,transform->height };
        destinationRect = { colliderRect.x,colliderRect.y,colliderRect.w,colliderRect.h };
    }
}

void ColliderComponent::Update(float deltaTime)
{
    colliderRect.x = static_cast<int>(transform->position.x);
    colliderRect.y = static_cast<int>(transform->position.y);
    colliderRect.w = transform->width * transform->scale;
    colliderRect.h = transform->height * transform->scale;
    destinationRect.x = colliderRect.x - Game::camera.x;
    destinationRect.y = colliderRect.y - Game::camera.y;
}

void ColliderComponent::Render()
{
    if (turnOnCollidingBox)
    {
        TextureManager::Draw(Game::assetManager->GetTexture("BoundingBox-Texture"), sourceRect, destinationRect, SDL_FLIP_NONE);
    }
}
