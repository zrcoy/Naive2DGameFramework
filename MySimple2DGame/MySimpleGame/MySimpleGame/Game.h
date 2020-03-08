#pragma once

#include "PCH.h"
#include "Entity.h"
#include "Component.h"
#include "EntityManager.h"
#include "sol.hpp"

class AssetManager;

class Game {
private:
    bool isRunning;
    SDL_Window* window;
    
public:
    static EntityManager* manager;
    static SDL_Renderer* renderer;
    static AssetManager* assetManager;
    static SDL_Event event;
    static SDL_Rect camera;
    Entity* player;
    Game();
    ~Game();
    int ticksLastFrame = 0;
    bool IsRunning() const;
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    void LoadLevel(int levelNumber);
    void HandleCameraMovement();
    void CheckCollisions();
    void ProcessingGameOver();
    void ProcessingNextLevel();
    
};
