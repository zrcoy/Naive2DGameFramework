#pragma once

#include "../Game.h"
#include "../EntityManager.h"
#include "../Components/TransformComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/ProjectileEmitterComponent.h"

class KeyboardControlComponent :public Component
{
    public:
        std::string upKey;
        std::string downKey;
        std::string rightKey;
        std::string leftKey;
        std::string shootKey;
        TransformComponent* transform;
        SpriteComponent* sprite;
        ProjectileEmitterComponent* projectileEmitter;
        KeyboardControlComponent();
        KeyboardControlComponent(std::string upKey, std::string rightKey, std::string downKey, std::string leftKey, std::string shootKey);
        std::string GetSDLKeyStringCode(std::string key);

        void Initialize() override;

        void Update(float deltaTime) override;

        void Render();
};
