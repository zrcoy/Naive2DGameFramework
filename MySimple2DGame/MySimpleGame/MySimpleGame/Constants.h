#pragma once
#include <SDL.h>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

const float PI = 3.14159265359f;

enum CollisionMask
{
    UI_ELEMENT = 0,
    PLAYER = 1,
    ENEMY = 2,
    PROJECTILE_ENEMY = 4,
    VEGETATION = 8,
    LEVEL_COMPLETE = 16,
    TILE = 32,
    PROJECTILE_PLAYER = 64,
};

enum CollisionType
{
    NO_COLLISION = 0,
    PLAYER_ENEMY_COLLISION = PLAYER | ENEMY,//0001|0010 = 0011
    PLAYER_PEOJECTILE_COLLISION = PLAYER | PROJECTILE_ENEMY,//player only care about projectile hit from enemy
    ENEMY_PROJECTILE_COLLISION = ENEMY | PROJECTILE_PLAYER,
    PLAYER_VEGETATION_COLLISION = PLAYER | VEGETATION,
    PLAYER_LEVEL_COMPLETE_COLLISION = PLAYER | LEVEL_COMPLETE
};



enum LayerType {
    TILEMAP_LAYER = 0,
    VEGETATION_LAYER = 1,
    ENEMY_LAYER = 2,
    OBSTACLE_LAYER = 3,
    PROJECTILE_LAYER = 4,
    PLAYER_LAYER = 5,
    UI_LAYER = 6,
};

enum Direction {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    STATIC = 4
};

const unsigned int NUM_LAYERS = 7;

const SDL_Color WHITE_COLOR = { 255,255,255,255 };
const SDL_Color GREEN_COLOR = { 255,255,255,255 };
