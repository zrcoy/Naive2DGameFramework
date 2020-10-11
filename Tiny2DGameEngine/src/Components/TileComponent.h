#pragma once

#include <SDL.h>
#include <string>
#include "../Component.h"

class TileComponent:public Component
{
public:
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    vec2 position;

    TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTileId);
    ~TileComponent();


    void Update(float deltaTime) override;

    void Render() override;
};
