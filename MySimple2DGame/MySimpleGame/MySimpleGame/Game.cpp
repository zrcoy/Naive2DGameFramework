#include "PCH.h"
#include <iostream>
#include "Game.h"
#include "AssetManager.h"
#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/KeyboardControlComponent.h"
#include "Map.h"
#include "Components/ColliderComponent.h"
#include "Components/TextLabelComponent.h"
#include "Components/ProjectileEmitterComponent.h"
#include "Components/TweeningComponent.h"
#include "EntityManager.h"


extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#ifdef _WIN32
#pragma comment(lib,"../../Libraries/lua-5.3.5_Win32_dllw6_lib/liblua53.a")
#endif


EntityManager* Game::manager = new EntityManager();
SDL_Renderer* Game::renderer;
AssetManager* Game::assetManager = new AssetManager(manager);
SDL_Event Game::event;
Map* map;
SDL_Rect Game::camera = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
Game::Game() {
    this->isRunning = false;
    this->player = nullptr;
    /*std::string cmd = "a=7+11";

    lua_State* L = luaL_newstate();

    int r = luaL_dostring(L, cmd.c_str());

    if (r == LUA_OK)
    {
        lua_getglobal(L, "a");
        if (lua_isnumber(L, -1))
        {
            float a_in_cpp = (float)lua_tonumber(L, -1);
            std::cout << "a_in_cpp = " << a_in_cpp << std::endl;
        }
    }
    else
    {
        std::string errormsg = lua_tostring(L, -1);
        std::cout << errormsg << std::endl;
    }

    system("pause");
    lua_close(L);*/

}

Game::~Game() {
}

bool Game::IsRunning() const {
    return this->isRunning;
}



void Game::Initialize(int width, int height) {


    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
    if (TTF_Init() != 0)
    {
        std::cerr << "Error initializing SDL TTF" << std::endl;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    LoadLevel(1);

    isRunning = true;
    return;
}

void Game::ProcessInput() {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT: {
        isRunning = false;
        break;
    }
    case SDL_KEYDOWN: {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
            isRunning = false;
        }
    }
    default: {
        break;
    }
    }
}

void Game::Update() {
    // Wait until 16ms has ellapsed since the last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME));

    // Delta time is the difference in ticks from last frame converted to secomds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    // Clamp deltaTime to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    // Sets the new ticks for the current frame to be used in the next pass
    ticksLastFrame = SDL_GetTicks();

    manager->Update(deltaTime);

    HandleCameraMovement();

    CheckCollisions();
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    if (manager->HasNoEntities())
    {
        return;
    }
    manager->Render();

    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    assetManager->ClearData();
    manager->ClearData();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//Entity& player = manager.AddEntity("chopper", PLAYER_LAYER, CollisionMask::PLAYER);
void Game::LoadLevel(int levelNumber)
{
    ////load asset first
    //assetManager->AddTexture("tank-image", std::string("assets/images/tank-big-right.png").c_str());
    //assetManager->AddTexture("chopper-image", std::string("assets/images/chopper-spritesheet.png").c_str());
    //assetManager->AddTexture("radar-image", std::string("assets/images/radar.png").c_str());
    //assetManager->AddTexture("jungle-tiletexture", std::string("assets/tilemaps/jungle.png").c_str());
    //assetManager->AddTexture("BoundingBox_Texture", std::string("assets/images/collision-texture.png").c_str());
    //assetManager->AddTexture("heliport_image", std::string("assets/images/heliport.png").c_str());
    //assetManager->AddTexture("projectile_image", std::string("assets/images/bullet-enemy.png").c_str());
    //assetManager->AddFont("charriot-font", std::string("assets/fonts/charriot.ttf").c_str(), 14);

    //map = new Map("jungle-tiletexture", 2, 32);
    //map->LoadMap("assets/tilemaps/jungle.map", 25, 20);


    ////add entities
    ////tank
    //Entity& tankEntity = manager.AddEntity("tank", ENEMY_LAYER, CollisionMask::ENEMY);
    //tankEntity.AddComponent<TransformComponent>(150, 495, 20, 20, 32, 32, 1);
    //tankEntity.AddComponent<SpriteComponent>("tank-image");
    //tankEntity.AddComponent<ColliderComponent>("enemy", 150, 495, 32, 32, true);

    ////projectile
    //Entity& projectile = manager.AddEntity("projectile", PROJECTILE_LAYER, CollisionMask::PROJECTILE);
    //projectile.AddComponent<TransformComponent>(150 + 16, 495 + 16, 0, 0, 4, 4, 1);
    //projectile.AddComponent<SpriteComponent>("projectile_image");
    //projectile.AddComponent<ColliderComponent>("projectile", 150 + 16, 496 + 16, 4, 4, false);
    //projectile.AddComponent<ProjectileEmitterComponent>(50, 270, 200, true);

    ////chopper
    //player.AddComponent<TransformComponent>(240, 106, 0, 0, 32, 32, 1);
    //player.AddComponent<SpriteComponent>("chopper-image", 2, 90, true, false);
    //player.AddComponent<KeyboardControlComponent>("up", "right", "down", "left", "space");
    //player.AddComponent<ColliderComponent>("player", 240, 106, 32, 32, true);


    ////radar
    //Entity& radarEntity = manager.AddEntity("Radar", UI_LAYER, CollisionMask::UI_ELEMENT);
    //radarEntity.AddComponent<TransformComponent>(720, 15, 0, 0, 64, 64, 1);
    //radarEntity.AddComponent<SpriteComponent>("radar-image", 8, 150, false, true);

    ////next level helicopter sign
    //Entity& heliportEntity = manager.AddEntity("HeliportSign", OBSTACLE_LAYER, CollisionMask::LEVEL_COMPLETE);
    //heliportEntity.AddComponent<TransformComponent>(470, 420, 0, 0, 32, 32, 1);
    //heliportEntity.AddComponent<SpriteComponent>("heliport_image");
    //heliportEntity.AddComponent<ColliderComponent>("level_complete", 470, 420, 32, 32, true);


    ////label
    //Entity& labelLevelName = manager.AddEntity("LabelLevelName", UI_LAYER, CollisionMask::UI_ELEMENT);
    //labelLevelName.AddComponent<TextLabelComponent>(10, 10, "First Level...", "charriot-font", WHITE_COLOR);

    /***********************************/
    /* Load asset from lua config file */
    /***********************************/

    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

    //Register functions can be used in lua
    lua.set_function("bounce_ease_InOut", TweenFunc_BounceEaseInOut);

    std::string levelName = "Level" + std::to_string(levelNumber);
    lua.script_file("assets/scripts/" + levelName + ".lua");

    sol::table levelData_Sol = lua[levelName];
    sol::table levelAssets_Sol = levelData_Sol["assets"];
    unsigned int assetIndex = 0;
    while (true)
    {
        sol::optional<sol::table> existAssetIndexNode = levelAssets_Sol[assetIndex];
        if (existAssetIndexNode == sol::nullopt)
        {
            break;
        }
        else
        {
            sol::table asset_Sol = levelAssets_Sol[assetIndex];
            std::string assetType = asset_Sol["type"];
            std::string assetId = asset_Sol["id"];
            std::string assetFilePath = asset_Sol["file"];
            if (assetType.compare("texture") == 0)
            {
                assetManager->AddTexture(assetId, assetFilePath.c_str());

            }
            if (assetType.compare("font") == 0)
            {
                assetManager->AddFont(assetId, assetFilePath.c_str(), static_cast<int>(asset_Sol["fontSize"]));
            }
        }
        assetIndex++;
    }


    /**********************************/
    /* Load map from lua config file  */
    /**********************************/
    sol::table map_Sol = levelData_Sol["map"];
    std::string mapId = map_Sol["textureAssetId"];
    std::string mapFile = map_Sol["file"];
    map = new Map(mapId, static_cast<int>(map_Sol["scale"]), static_cast<int>(map_Sol["tileSize"]));
    map->LoadMap(mapFile, static_cast<int>(map_Sol["mapSizeX"]), static_cast<int>(map_Sol["mapSizeY"]));



    /***************************************/
    /* Load entities from lua config file  */
    /***************************************/
    //Entity& player = manager.AddEntity("chopper", PLAYER_LAYER, CollisionMask::PLAYER);
    sol::table entities_Sol = levelData_Sol["entities"];
    unsigned int entitiesIndex = 0;
    while (true)
    {
        sol::optional<sol::table> existEntityNode = entities_Sol[entitiesIndex];
        if (existEntityNode == sol::nullopt)
        {
            break;
        }
        else
        {
            // add entity
            sol::table entity = entities_Sol[entitiesIndex];
            std::string name = entity["name"];
            LayerType layer = static_cast<LayerType>(static_cast<int>(entity["layer"]));
            CollisionMask mask = static_cast<CollisionMask>(static_cast<int>(entity["mask"]));
            Entity& newEntity = manager->AddEntity(name, layer, mask);


            // add transform component
            sol::optional<sol::table> existTransformCompNode = entity["components"]["transform"];
            if (existTransformCompNode != sol::nullopt)
            {
                newEntity.AddComponent<TransformComponent>(
                    static_cast<int>(entity["components"]["transform"]["position"]["x"]),
                    static_cast<int>(entity["components"]["transform"]["position"]["y"]),
                    static_cast<int>(entity["components"]["transform"]["velocity"]["x"]),
                    static_cast<int>(entity["components"]["transform"]["velocity"]["y"]),
                    static_cast<int>(entity["components"]["transform"]["width"]),
                    static_cast<int>(entity["components"]["transform"]["height"]),
                    static_cast<int>(entity["components"]["transform"]["scale"])
                    );
            }


            // add transform component

            sol::optional<sol::table> existSpriteCompNode = entity["components"]["sprite"];
            if (existSpriteCompNode != sol::nullopt)
            {
                bool isAnimated = entity["components"]["sprite"]["animated"];
                bool isFixed = entity["components"]["sprite"]["fixed"];
                std::string textureAssetId = entity["components"]["sprite"]["textureAssetId"];
                // if this texture is animated
                if (isAnimated)
                {
                    newEntity.AddComponent<SpriteComponent>(
                        textureAssetId,
                        static_cast<int>(entity["components"]["sprite"]["frameCount"]),
                        static_cast<int>(entity["components"]["sprite"]["animationSpeed"]),
                        static_cast<bool>(entity["components"]["sprite"]["hasDirections"]),
                        isFixed
                        );
                }
                else
                {
                    newEntity.AddComponent<SpriteComponent>(textureAssetId, isFixed);
                }
            }


            // add keyboard component
            sol::optional<sol::table> existKeyboardCompNode = entity["components"]["input"]["keyboard"];
            if (existKeyboardCompNode != sol::nullopt)
            {
                newEntity.AddComponent<KeyboardControlComponent>(
                    entity["components"]["input"]["keyboard"]["up"],
                    entity["components"]["input"]["keyboard"]["right"],
                    entity["components"]["input"]["keyboard"]["down"],
                    entity["components"]["input"]["keyboard"]["left"],
                    entity["components"]["input"]["keyboard"]["shoot"]
                    );

            }

            //add collider component
            sol::optional<sol::table> existColliderCompNode = entity["components"]["collider"];
            if (existColliderCompNode != sol::nullopt)
            {
                newEntity.AddComponent<ColliderComponent>(
                    entity["components"]["collider"]["tag"],
                    static_cast<int>(entity["components"]["transform"]["position"]["x"]),
                    static_cast<int>(entity["components"]["transform"]["position"]["y"]),
                    static_cast<int>(entity["components"]["transform"]["width"]),
                    static_cast<int>(entity["components"]["transform"]["height"]),
                    static_cast<bool>(entity["components"]["collider"]["turnOn"])
                    );
            }


            //add projectile
            sol::optional<sol::table> existProjectileNode = entity["components"]["projectileEmitter"];
            if (existProjectileNode != sol::nullopt)
            {
                //create projectile entity
                CollisionMask mask = static_cast<CollisionMask>(entity["components"]["projectileEmitter"]["mask"]);
                Entity& projectile = manager->AddEntity("projectile", LayerType::PROJECTILE_LAYER, mask);
                int parentPosX = entity["components"]["transform"]["position"]["x"];
                int parentPosY = entity["components"]["transform"]["position"]["y"];
                int parentWidth = entity["components"]["transform"]["width"];
                int parentHeight = entity["components"]["transform"]["height"];
                int parentScale = entity["components"]["transform"]["scale"];
                int projectileWidth = entity["components"]["projectileEmitter"]["width"];
                int projectileHeight = entity["components"]["projectileEmitter"]["height"];
                // spawn the projectile on the medium point of the parent
                projectile.AddComponent<TransformComponent>(
                    parentPosX + parentWidth / 2 * parentScale,
                    parentPosY + parentHeight / 2 * parentScale,
                    0,
                    0,
                    projectileWidth,
                    projectileHeight,
                    1
                    );

                projectile.AddComponent<SpriteComponent>(entity["components"]["projectileEmitter"]["textureAssetId"], false);

                projectile.AddComponent<ColliderComponent>(
                    "Projectile",
                    parentPosX + parentWidth / 2 * parentScale,
                    parentPosY + parentHeight / 2 * parentScale,
                    projectileWidth,
                    projectileHeight,
                    false
                    );

                projectile.AddComponent<ProjectileEmitterComponent>(
                    static_cast<int>(entity["components"]["projectileEmitter"]["speed"]),
                    static_cast<int>(entity["components"]["projectileEmitter"]["angle"]),
                    static_cast<int>(entity["components"]["projectileEmitter"]["range"]),
                    static_cast<bool>(entity["components"]["projectileEmitter"]["shouldLoop"])
                    );
            }


            // add text labels
            sol::optional<sol::table> existTextLabelNode = entity["components"]["textLabel"];
            if (existTextLabelNode != sol::nullopt)
            {
                Entity& levelLabel = manager->AddEntity(
                    entity["name"],
                    static_cast<LayerType>(entity["layer"]),
                    static_cast<CollisionMask>(entity["mask"])
                );

                SDL_Color fontColor = {
                    static_cast<Uint8>(entity["components"]["textLabel"]["colorR"]),
                    static_cast<Uint8>(entity["components"]["textLabel"]["colorG"]),
                    static_cast<Uint8>(entity["components"]["textLabel"]["colorB"]),
                    static_cast<Uint8>(entity["components"]["textLabel"]["colorAlpha"])
                };

                levelLabel.AddComponent<TextLabelComponent>(
                    static_cast<int>(entity["components"]["textLabel"]["position"]["x"]),
                    static_cast<int>(entity["components"]["textLabel"]["position"]["y"]),
                    entity["components"]["textLabel"]["text"],
                    entity["components"]["textLabel"]["fontFamily"],
                    fontColor
                    );
            }


            // add tweening components
            sol::optional<sol::table> existTweenNode = entity["components"]["tween"];
            if (existTweenNode != sol::nullopt)
            {
                unsigned int index = 0;
                TweeningComponent& tweenComp = newEntity.AddComponent<TweeningComponent>();
                while (true)
                {
                    sol::optional<sol::table> existTweenObjNode = entity["components"]["tween"][index];
                    if (existTweenObjNode == sol::nullopt)
                        break;
                    else 
                    {
                        tweenComp.AddTweenObj(
                            entity["components"]["tween"][index]["func"],
                            entity["components"]["tween"][index]["target"],
                            static_cast<float>(entity["components"]["tween"][index]["range"]),
                            static_cast<float>(entity["components"]["tween"][index]["totalTime"])
                        );
                    }
                    index++;
                }
               

            }


        }//end of else statement
        entitiesIndex++;
    }// end of while loop

    //tweening test
    //manager->GetEntityByName("player")->AddComponent<TweeningComponent>();
    //manager->GetEntityByName("player")->GetComponent<TweeningComponent>()->AddTweenObj(TweenFunc_BounceEaseInOut, "width", 50.0f, 1.0f);
}

void Game::HandleCameraMovement()
{
    player = manager->GetEntityByName("player");
    if (player)
    {
        TransformComponent* mainPlayerTransform = player->GetComponent<TransformComponent>();

        camera.x = static_cast<int>(mainPlayerTransform->position.x - (WINDOW_WIDTH / 2));
        camera.y = static_cast<int>(mainPlayerTransform->position.y - (WINDOW_HEIGHT / 2));

        camera.x = camera.x < 0 ? 0 : camera.x;
        camera.y = camera.y < 0 ? 0 : camera.y;
        camera.x = camera.x > camera.w ? camera.w : camera.x;
        camera.y = camera.y > camera.h ? camera.h : camera.y;
    }

}


void Game::CheckCollisions()
{
    CollisionType collisionType = manager->CheckEntityCollisions();
    if (collisionType == PLAYER_ENEMY_COLLISION)
    {
        ProcessingGameOver();
        //manager->GetEntityByName("tank1")->GetComponent<TweeningComponent>()->ResetAllTimer();
    }
    if (collisionType == PLAYER_PEOJECTILE_COLLISION)
    {
        manager->GetEntityByName("player")->GetComponent<TweeningComponent>()->TriggerTweenObjByTarget("width");
        manager->GetEntityByName("player")->GetComponent<TweeningComponent>()->TriggerTweenObjByTarget("height");
        
    }
    if (collisionType == PLAYER_LEVEL_COMPLETE_COLLISION)
    {
        ProcessingNextLevel();
    }
    if (collisionType == ENEMY_PROJECTILE_COLLISION)
    {
        int bp = 0;
        //manager->GetEntityByName("player")->Destroy();
    }
}

void Game::ProcessingGameOver()
{
    std::cout << "Game Over!" << std::endl;
    isRunning = false;
}

void Game::ProcessingNextLevel()
{
    std::cout << "Next Level!" << std::endl;
    isRunning = false;
}


