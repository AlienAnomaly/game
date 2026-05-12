#pragma once

#include <unordered_map>
#include <typeindex>

#include "vec2.h"
#include "component.h"

namespace bliss::ecs
{
	class Entity
	{
	public:
		Entity();
		~Entity() = default;

	private:
		std::unordered_map<std::type_index, std::shared_ptr<ecs::Component>> m_Components;

	public:
		template <typename T, typename ...Args>
		std::shared_ptr<T> AddComponent(Args&&... args)
		{
			auto iter = m_Components.find(typeid(T));
			if (iter != m_Components.end() && iter->second != nullptr)
			{	
				return std::static_pointer_cast<T>(iter->second);
			} 

			auto comp = std::make_shared<T>(std::forward<Args>(args)...);
			m_Components[typeid(T)] = comp;

			return comp;
		}

		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			auto iter = m_Components.find(typeid(T));
			if (iter == m_Components.end() || iter->second == nullptr)
			{	
				return nullptr;
			}

			return std::static_pointer_cast<T>(iter->second);
		}

		template <typename T>
		bool HasComponent() const
		{
			return m_Components.find(typeid(T)) != m_Components.end();
		}

		template <typename T>
		void RemoveComponent()
		{
			m_Components.erase(typeid(T));
		}
	};
}