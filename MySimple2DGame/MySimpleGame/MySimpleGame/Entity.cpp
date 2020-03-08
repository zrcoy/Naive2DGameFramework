#include "Entity.h"
#include "Component.h"
#include "Game.h"



Entity::Entity(EntityManager& manager) :manager(manager)
{
    this->isActive = true;
}

Entity::Entity(EntityManager& manager, std::string name, LayerType layer_, CollisionMask mask_) : manager(manager), name(name), layer(layer_), collisionMask(mask_)
{
    this->isActive = true;
}

Entity::~Entity()
{
 
}

void Entity::ClearData()
{
    components.clear();
    componentTypeMap.clear();
}


void Entity::Update(float deltaTime)
{
    for (auto& component : components)
    {
        component->Update(deltaTime);
    }
}

void Entity::Render()
{
    for (auto& component : components)
    {
        component->Render();
    }
}

void Entity::Destroy()
{
    this->isActive = false;
}

bool Entity::IsActive() const
{
    return isActive;
}

void Entity::ListAllComponents() const
{
    for (auto& mapElement : componentTypeMap)
    {
        std::cout << "Component<" << mapElement.first->name() << std::endl;
    }
}


