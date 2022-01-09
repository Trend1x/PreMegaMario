#include "Entity.h"

Entity::Entity(const std::string& tag, size_t id)
	:m_tag(tag), 
	 m_id(id), 
	 m_components(CTransform(), CLifespan(0, 0), CInput(),  CBoundingBox(), CAnimation(), CGraity(), CState())
{

}

size_t Entity::id() const
{ 
	return m_id; 
}

const std::string& Entity::tag() const
{ 
	return m_tag; 
}

bool Entity::isActive() const
{ 
	return m_active; 
}

void Entity::destroy() 
{
	m_active = false;
}