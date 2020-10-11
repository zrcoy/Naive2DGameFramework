#include <iostream>
#include <fstream>
#include "Map.h"
#include "Game.h"
#include "Components/TileComponent.h"
#include "myHelperFuncs.h"



Map::Map(std::string textureId, int scale, int tileSize)
{
    this->textureId = textureId;
    this->scale = scale;
    this->tileSize = tileSize;
}

Map::~Map()
{
}

void Map::LoadMap(std::string filePath, int mapSizeX, int mapSizeY)
{
    std::fstream mapFile;
    mapFile.open(filePath);
    for (int y = 0; y < mapSizeY; y++)
    {
        for (int x = 0; x < mapSizeX; x++)
        {
            char ch;
            mapFile.get(ch);
            int sourceRectY = myAtoi_s(&ch) * tileSize;
            mapFile.get(ch);
            int sourceRectX = myAtoi_s(&ch) * tileSize;
            AddTile(sourceRectX, sourceRectY, x * (scale * tileSize), y * (scale * tileSize));
            mapFile.ignore();
        }
    }
    mapFile.close();
}

void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y)
{
    Entity& newTile = Game::manager->AddEntity("Tile",TILEMAP_LAYER,CollisionMask::TILE);
    newTile.AddComponent<TileComponent>(sourceRectX, sourceRectY, x, y,tileSize, scale, textureId);
}
