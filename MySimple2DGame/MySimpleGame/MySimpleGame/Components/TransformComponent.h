#pragma once
#include "../PCH.h"
#include "../EntityManager.h"


class TransformComponent :public Component
{
public:
    vec2 position;
    vec2 velocity;
    int width;
    int height;
    int scale;
    Direction forwardDirection;
    Direction shootingDirection;
    vec2 shootingOrigin;

    TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s);

    void Initialize() override;

    void Update(float deltaTime) override;

    void Render() override;
};