#include "EntityManager.h"
#include "Components/ColliderComponent.h"
#include "Collision.h"

void EntityManager::ClearData()
{
    for (auto& entity : entities)
    {
        entity->ClearData();
    }
    entities.clear();
}

void EntityManager::Update(float deltaTime)
{
    for (auto& entity : entities)
    {
        entity->Update(deltaTime);
    }
    DestroyInactiveEntities();
}

void EntityManager::DestroyInactiveEntities()
{
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        if (!entities[i]->IsActive())
        {
            entities.erase(entities.begin() + i);
        }
    }
}

void EntityManager::Render()
{
    for (int layerNum = 0; layerNum < NUM_LAYERS; layerNum++)
    {
        for (auto& entity : GetEntitiesByLayer(static_cast<LayerType>(layerNum)))
        {
            entity->Render();
        }
    }
}

bool EntityManager::HasNoEntities()
{
    return entities.size() == 0;
}

Entity& EntityManager::AddEntity(std::string const& entityName, LayerType layer, CollisionMask mask)
{
    Entity* entity = new Entity(*this, entityName, layer,mask);
    entities.emplace_back(entity);
    return *entity;
}

Entity* EntityManager::GetEntityByName(std::string name)
{
    for (auto& entity : entities)
    {
        if (entity->name.compare(name) == 0)
        {
            return entity;
        }
    }
    return nullptr;
}

std::vector<Entity*> EntityManager::GetEntities() const
{
    return entities;
}

std::vector<Entity*> EntityManager::GetEntitiesByLayer(LayerType layerNum) const
{
    std::vector<Entity*> selectedEntities;
    for (auto& entity : entities)
    {
        if (entity->layer == layerNum)
        {
            selectedEntities.emplace_back(entity);
        }
    }
    return selectedEntities;
}

unsigned int EntityManager::GetEntityCount()
{
    return entities.size();
}

void EntityManager::ListAllEntities() const
{
    unsigned int i = 0;
    for (auto& entity : entities)
    {
        std::cout << "Entity[" << i << "]: " << entity->name << std::endl;
        entity->ListAllComponents();
        i++;
    }
}

CollisionType EntityManager::CheckEntityCollisions() const
{
    // todo: improve performance by doing spacial patitioning collision check
    for (unsigned int i = 0; i < entities.size() - 1; i++)
    {
        auto& thisEntity = entities[i];
        if (thisEntity->name == "player")
        {
            int bp = 0;
        }
        if (thisEntity->HasComponent<ColliderComponent>())
        {
            ColliderComponent* thisCollider = thisEntity->GetComponent<ColliderComponent>();
            for (unsigned int j = i + 1; j < entities.size(); j++)
            {
                auto& thatEntity = entities[j];
                if (thatEntity->name == "tank1")
                {
                    int bp = 0;
                }
                if (thatEntity->HasComponent<ColliderComponent>() && thisEntity->collisionMask!=thatEntity->collisionMask)
                {
                    ColliderComponent* thatCollider = thatEntity->GetComponent<ColliderComponent>();
                    
                    if (Collision::CheckRectangleCollision(thisCollider->colliderRect, thatCollider->colliderRect))
                    {
                        return static_cast<CollisionType>(thisEntity->collisionMask |thatEntity->collisionMask);
                    }
                }
            }
        }

    }
    return NO_COLLISION;
}
