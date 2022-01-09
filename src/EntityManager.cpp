#include "EntityManager.h"

EntityManager::EntityManager()
{
}

void EntityManager::update()
{
	for (auto &e : m_toAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->tag()].push_back(e);
	}
	m_toAdd.clear();

	//remove dead entities from the vector of all entities
	removeDeadEntities(m_entities);

	//remove dead entities from each vector in the entity map
	//C++17 way of iterating through [key,value] pairs in a map
	for (auto& [tag,entityVec] : m_entityMap)
	{
		removeDeadEntities(entityVec);
	}

}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
	//TODO: remove all dead entities from the input vector
	//		this is called by the update() function
	EntityVec::iterator new_end;

	new_end = remove_if(vec.begin(), vec.end(), [](ptr<Entity>& e) { return !e->isActive(); });
	vec.erase(new_end, vec.end());
}



std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++));
	
	m_toAdd.push_back(e);

	return e;
}

EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
	return m_entityMap[tag];
}


