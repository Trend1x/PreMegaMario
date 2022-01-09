#include "Scene.h"
#include "GameEngine.h"


Scene::Scene()
{

}

Scene::Scene(GameEngine* gameEngine)
{
	m_game = gameEngine;
}

void Scene::setPaused(bool paused)
{
	m_paused = paused;
}

size_t Scene::width() const
{
	return m_game->window().getSize().x;
}

size_t Scene::height() const
{
	return m_game->window().getSize().y;
}

size_t Scene::currentFrame() const
{
	return m_currentFrame;
}

void Scene::simulate(int count)
{
	for (int i = 0; i < count; i++)
	{
		update();
	}
}

void Scene::doAction(const Action& action)
{
	sDoAction(action);
}


void Scene::registerAction(const int key, const std::string& action)
{
	m_actionMap[key] = action;
}

std::map<int, std::string> Scene::getActionMap()
{ 
	return m_actionMap; 
}


