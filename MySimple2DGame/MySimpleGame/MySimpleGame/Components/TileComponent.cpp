#include "../PCH.h"
#include "TileComponent.h"
#include "../EntityManager.h"
#include "../AssetManager.h"


TileComponent::TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTileId)
{
    texture = Game::assetManager->GetTexture(assetTileId);
    sourceRectangle.x = sourceRectX;
    sourceRectangle.y = sourceRectY;
    sourceRectangle.w = tileSize;
    sourceRectangle.h = tileSize;

    destinationRectangle.x = x;
    destinationRectangle.y = y;
    destinationRectangle.w = tileSize * tileScale;
    destinationRectangle.h = tileSize * tileScale;

    position.x = static_cast<float>(x);
    position.y = static_cast<float>(y);

}

TileComponent::~TileComponent()
{
    SDL_DestroyTexture(texture);
}

void TileComponent::Update(float deltaTime)
{
    destinationRectangle.x =static_cast<int>(position.x - Game::camera.x);
    destinationRectangle.y = static_cast<int>(position.y - Game::camera.y);
}

void TileComponent::Render()
{
    TextureManager::Draw(texture, sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
}
