#pragma once

#include "../Game.h"
#include "../Component.h"
#include "TransformComponent.h"


class ColliderComponent :public Component
{
public:
    std::string colliderTag;
    SDL_Rect colliderRect;
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;
    TransformComponent* transform;
    bool turnOnCollidingBox;

    ColliderComponent(std::string colliderTag, int x, int y, int width, int height, bool turnOnCollidingBox);
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render() override;
};
