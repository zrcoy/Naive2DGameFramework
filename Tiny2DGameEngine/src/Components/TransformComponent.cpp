#include "TransformComponent.h"
#include "../Game.h"

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s):width(w),height(h),scale(s)
{
    position = vec2(posX, posY);
    velocity = vec2(velX, velY);
    forwardDirection = Direction::DOWN;
    shootingDirection = Direction::STATIC;
    shootingOrigin = position + vec2(width/2*scale,height/2*scale);
}

void TransformComponent::Initialize()
{
}

void TransformComponent::Update(float deltaTime)
{
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void TransformComponent::Render()
{
    int bp = 0;
}
