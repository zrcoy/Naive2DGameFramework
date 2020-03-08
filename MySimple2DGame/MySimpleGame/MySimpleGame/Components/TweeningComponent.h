#pragma once

#include "../Game.h"
#include "../TweenFuncs.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "../TweenObj.h"



class TweeningComponent : public Component
{
private:
    std::map<std::string, TweenObj*> tweenObjs;
    TransformComponent* transform;
    SpriteComponent* sprite;
public:
    TweeningComponent();
    void Update(float deltaTime) override;
    void Initialize() override;
    void ResetTimerByTarget(std::string target);
    void ResetAllTimer();
    void AddTweenObj(std::string tweenFunc, std::string target, float range, float totalTime);
    TweenObj& GetTweenObjByTarget(std::string target);
    void TriggerTweenObjByTarget(std::string target);
    myTweenFunc GetTweenFunc(std::string funcName);
};
