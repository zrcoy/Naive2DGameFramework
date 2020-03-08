#include "../PCH.h"

#include "ProjectileEmitterComponent.h"

ProjectileEmitterComponent::ProjectileEmitterComponent(int speed, int angleDeg, int range, bool shouldLoop)
{

    this->speed = speed;
    this->range = range;
    this->shouldLoop = shouldLoop;
    this->angleRad = glm::radians(static_cast<float>(angleDeg));
}



void ProjectileEmitterComponent::Initialize()
{

    transform = owner->GetComponent<TransformComponent>();
    origin = glm::vec2(transform->position.x, transform->position.y);
    transform->velocity = glm::vec2(glm::cos(angleRad) * speed, glm::sin(angleRad) * speed);
}

//void ProjectileEmitterComponent::SetShooter(Entity* s)
//{
//    this->shooter = s;
//    if (shooter->collisionMask == CollisionMask::PLAYER)
//    {
//        isPlayer = true;
//    }
//
//    transform->velocity = isPlayer ? vec2(0, 0) : vec2(cos(angleRad) * speed, sin(angleRad) * speed);
//}

//void ProjectileEmitterComponent::spawnProjectile()
//{
//    
//    Direction dir = shooter->GetComponent<TransformComponent>()->shootingDirection;
//    // check static first
//    if (dir == Direction::STATIC)
//    {
//        transform->velocity = vec2(0, 0);
//        return;
//    }
//
//    float angleDeg = 0.0f;
//    if (dir == Direction::DOWN)
//    {
//        angleDeg = 90.0f;
//    }
//    else if (dir == Direction::UP)
//    {
//        angleDeg = 270.0f;
//    }
//    else if (dir == Direction::LEFT)
//    {
//        angleDeg = 180.0f;
//    }
//    else if (dir == Direction::RIGHT)
//    {
//        angleDeg = 0.0f;
//    }
//    angleRad = glm::radians(angleDeg);
//    transform->velocity = vec2(cos(angleRad) * speed, sin(angleRad) * speed);
//
//}

void ProjectileEmitterComponent::Update(float deltaTime)
{
    //if (shooter)
    //{
    //    TransformComponent* shooterTransform = shooter->GetComponent<TransformComponent>();
    //    
    //    if (shooter->layer == LayerType::PLAYER_LAYER)
    //    {
    //        origin = vec2(shooterTransform->position.x + shooterTransform->width / 2 * shooterTransform->scale
    //            , shooterTransform->position.y + shooterTransform->height / 2 * shooterTransform->scale);
    //        if (shooterTransform->shootingDirection != Direction::STATIC)
    //        {
    //            spawnProjectile();
    //        }
    //        else
    //        {
    //            transform->position = origin;
    //        }
    //    }
    //    //deal with the case when reach the end of the shooting range
    //    if (glm::distance(transform->position, shooterTransform->shootingOrigin) > range)
    //    {
    //        if (shouldLoop)
    //        {
    //            transform->position.x = origin.x;
    //            transform->position.y = origin.y;
    //        }

    //        else
    //        {
    //            if (isPlayer)
    //            {
    //                transform->position = origin;
    //                
    //                transform->velocity = vec2(0, 0);
    //                shooterTransform->shootingDirection = Direction::STATIC;
    //            }
    //            else
    //            {
    //                this->owner->Destroy();
    //            }
    //        }
    //    }
    //}
    //int bp = 0;
    if (glm::distance(transform->position, origin) > range) {
        if (shouldLoop) {
            transform->position.x = origin.x;
            transform->position.y = origin.y;
        }
        else {
            owner->Destroy();
        }
    }
}

