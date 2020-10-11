#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include "../FontManager.h"
#include "../EntityManager.h"
#include "../Game.h"
#include "../AssetManager.h"


class TextLabelComponent :public Component
{
private:
    SDL_Rect position;
    std::string text;
    std::string fontFamily;
    SDL_Color color;
    SDL_Texture* texture;
public:
    TextLabelComponent(int x, int y, std::string text, std::string fontFamily, const SDL_Color color);
    void SetLabelText(std::string text, std::string fontFamily);
    void Render() override;


};