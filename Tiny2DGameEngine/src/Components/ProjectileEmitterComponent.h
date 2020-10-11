#pragma once

#include "../EntityManager.h"
#include "TransformComponent.h"

class ProjectileEmitterComponent :public Component
{
private:
    TransformComponent* transform ;
    vec2 origin;
    int speed;
    int range;
    float angleRad;
    bool shouldLoop;
    bool isPlayer;
    Entity* shooter;
public:
    ProjectileEmitterComponent(int speed, int angleDeg, int range, bool shouldLoop);
    void Update(float deltaTime) override;
    void Initialize() override;
    void SetShooter(Entity* s);
    void spawnProjectile();
};
