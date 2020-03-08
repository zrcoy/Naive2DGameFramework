#pragma once
#include "Components/SpriteComponent.h"


struct TweenObj
{
    myTweenFunc tweenFunc;
    float range;
    float totalTime;
    float timeElapsed;
    bool trigger;
    float startValue;
    SpriteComponent* sprite;
    std::string target;

    TweenObj(std::string tg, myTweenFunc t, float r, float tt);
    void Initialize(SpriteComponent* s);
    void Update(float deltaTime);
    
};
