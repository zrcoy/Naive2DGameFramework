#pragma once
#include <vector>
#include <string>
#include <map>
#include <typeinfo>
#include <iostream>
#include "Constants.h"
class EntityManager;
class Component;
//#include "Components/TransformComponent.h"

class Entity
{
protected:
    EntityManager& manager;
    bool isActive;
    std::vector<Component*> components;
    std::map<const std::type_info*,Component*> componentTypeMap;
public:
    std::string name;
    LayerType layer;
    CollisionMask collisionMask;
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name,LayerType layer,CollisionMask mask);
    ~Entity();
    void ClearData();
    virtual void Update(float deltaTime);
    virtual void Render();
    void Destroy();
    bool IsActive() const;
    void ListAllComponents() const;
    
    /*void check()
    {
        for (auto& c : componentTypeMap)
        {
            if(*c.first == typeid(TransformComponent))
        }
    }*/

    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... args)
    {
        T* newComponent = new T(std::forward<TArgs>(args)...);
        newComponent->owner = this;
        components.emplace_back(newComponent);
        componentTypeMap[&typeid(*newComponent)] = newComponent;
        newComponent->Initialize();
        return *newComponent;
    }

    

    template <typename T>
    T* GetComponent()
    {
        return static_cast<T*>(componentTypeMap[&typeid(T)]);
    }



    template <typename T>
    bool HasComponent() const {
        return componentTypeMap.count(&typeid(T));
    }

};

