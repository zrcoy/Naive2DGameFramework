#include "TweenObj.h"

TweenObj::TweenObj(std::string tg, myTweenFunc t, float r, float tt)
    :target(tg),
    tweenFunc(t),
    range(r),
    totalTime(tt),
    timeElapsed(0),
    trigger(false)
{

}

void TweenObj::Initialize(SpriteComponent* s)
{
    sprite = s;
    if (target.compare("width") == 0)
        startValue = sprite->destinationRectangle.w;
    else if (target.compare("height") == 0)
        startValue = sprite->destinationRectangle.h;

}

void TweenObj::Update(float deltaTime)
{
    if (trigger)
    {
        if (target.compare("width") == 0)
            sprite->destinationRectangle.w = tweenFunc(startValue, range, timeElapsed, totalTime);
        if (target.compare("height") == 0)
            sprite->destinationRectangle.h = tweenFunc(startValue, range, timeElapsed, totalTime);
    }
    if (timeElapsed > totalTime)
    {
        trigger = false;
        timeElapsed = 0;
        sprite->ResetSize();
    }
    timeElapsed += deltaTime;
}
