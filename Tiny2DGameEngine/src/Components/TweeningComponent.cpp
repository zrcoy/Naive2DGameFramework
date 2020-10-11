#include "TweeningComponent.h"

TweeningComponent::TweeningComponent()
{
    transform = nullptr;
    sprite = nullptr;
}

void TweeningComponent::Initialize()
{
    if (owner->HasComponent<TransformComponent>())
    {
        transform = owner->GetComponent<TransformComponent>();
    }
    if (owner->HasComponent<SpriteComponent>())
    {
        sprite = owner->GetComponent<SpriteComponent>();
    }
    
}

void TweeningComponent::ResetTimerByTarget(std::string target)
{

    tweenObjs[target]->timeElapsed = 0.0f;
}

void TweeningComponent::ResetAllTimer()
{
    for (auto& tween : tweenObjs)
    {
        tween.second->timeElapsed = 0.0f;
    }
}

void TweeningComponent::AddTweenObj(std::string tweenFunc, std::string target, float range, float totalTime)
{

    tweenObjs.emplace(target, new TweenObj(target, GetTweenFunc(tweenFunc), range, totalTime));
    tweenObjs[target]->Initialize(sprite);
}

myTweenFunc TweeningComponent::GetTweenFunc(std::string funcName)
{
    if (funcName.compare("BounceEaseInOut") == 0)
    {
        return TweenFunc_BounceEaseInOut;
    }
    else if (funcName.compare("ElasticEaseInOut") == 0)
    {
        return TweenFunc_ElasticEaseInOut;
    }
    else
    {
        return TweenFunc_Linear;//default onw
    }
}

TweenObj& TweeningComponent::GetTweenObjByTarget(std::string target)
{
    return *tweenObjs[target];
}

void TweeningComponent::TriggerTweenObjByTarget(std::string target)
{
    tweenObjs[target]->trigger = true;
}

void TweeningComponent::Update(float deltaTime)
{
    for (auto& t : tweenObjs)
    {
        t.second->Update(deltaTime);
    }
}
