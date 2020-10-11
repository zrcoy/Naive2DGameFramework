#pragma once

#include <SDL.h>
#include "../TextureManager.h"
#include "../AssetManager.h"
#include "TransformComponent.h"
#include "../Animation.h"


class SpriteComponent :public Component
{
    friend struct TweenObj;
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_FRect destinationRectangle;
    bool isAnimated;
    int numFrames;
    int animationSpeed;
    bool isFixed;
    float originWidth;
    float originHeight;
    std::map<std::string, Animation> animations;
    std::string currentAnimationName;
    unsigned int animationIndex = 0;


public:
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
    SpriteComponent(std::string textureId, bool isFixed);
    SpriteComponent(std::string id, int numFrames, int animationSpeed, bool hasDirections, bool isFixed);

    void SetTexture(std::string assetTextureId);

    void Initialize() override;

    void Update(float deltaTime) override;

    void Render() override;

    void Play(std::string animationName);

    void ResetSize();
};
