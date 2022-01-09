#pragma once

#include "Common.h"
#include "EntityManager.h"
#include "Action.h"

class GameEngine;

class Scene
{ 
protected:
	GameEngine* m_game;
	EntityManager m_entityManager;
	size_t m_currentFrame = 0; 
	std::map<int, std::string> m_actionMap;
	bool m_paused = false;
	bool m_hasEnded = false;

public:
	virtual void update() = 0; 
	virtual void sDoAction(const Action& action) = 0;
	virtual void sRender() = 0;


	Scene();
	Scene(GameEngine* gameEngine);
	void simulate(int );
	void doAction(const Action& action);
	std::map<int, std::string> getActionMap();
	void registerAction(const int key, const std::string & action);
	void setPaused(bool paused);
	size_t width() const;
	size_t height() const;
	size_t currentFrame() const;

};

