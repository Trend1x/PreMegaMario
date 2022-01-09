#include "GameEngine.h"
#include "Action.h"
#include "Scene_Menu.h"
#include "Scene_Play.h"

GameEngine::GameEngine(const std::string& path)
{
	init(path);
}

void GameEngine::changeScene(const std::string& sceneName, std::shared_ptr<Scene> scene, bool endCurrentScene)
{
	if (scene) 
	{
		m_sceneMap[sceneName] = scene;
	}
	else
	{
		if (m_sceneMap.find(sceneName) == m_sceneMap.end())
		{
			std::cerr << "Warning: Scene does not exist: " << sceneName << std::endl;
			return;
		}
	}

	if (endCurrentScene)
	{
		m_sceneMap.erase(m_sceneMap.find(m_currentScene));
	}

	m_currentScene = sceneName;
	
}

void GameEngine::init(const std::string& path)
{
	m_assets.loadFromFile(path);

	m_window.create(sf::VideoMode(1280, 768), "Definitely Not Mario");
	m_window.setFramerateLimit(60);

	changeScene("Menu", std::make_shared<Scene_Menu>(this));

}

void GameEngine::update()
{
	if (!isRunning()) { return; }
	
	if (m_sceneMap.empty()) { return; }

	sUserInput();
	currentScene()->simulate(m_simulationSpeed);
	currentScene()->sRender();
	m_window.display();
}

void GameEngine::sUserInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			quit();
		}

		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
		{
			auto actionMap = currentScene()->getActionMap();
			//if the current scene does not have an action asssociated with this key, skip the event
			if (actionMap.find(event.key.code) == actionMap.end()){	continue; }

			//determine start or end action by whether it was key press or release
			const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";

			//look up the action and send the action to the scene
			currentScene()->doAction(Action(actionMap.at(event.key.code), actionType));
			
		}
	}
}

std::shared_ptr<Scene> GameEngine::currentScene()
{
	return m_sceneMap[m_currentScene];
}

bool GameEngine::isRunning()
{
	return m_running && m_window.isOpen();
}

const Assets& GameEngine::assets()
{
	return m_assets;
}

sf::RenderWindow& GameEngine::window()
{
	return m_window;
}

void GameEngine::quit()
{
	m_running = false;
}

void GameEngine::run()
{
	while (m_running)
	{ 
		update();
	}
}