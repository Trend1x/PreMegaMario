#pragma once
#include "Scene.h"

class Scene_Menu : public Scene
{
public:
	Scene_Menu(GameEngine* gameEngine);

	void update() override;
	void sRender() override;
	void sDoAction(const Action& action) override;
	void onEnd();

	//Systems


private:
	
	std::vector<std::string>	m_menuStrings;
	std::vector<std::string>	m_levelPaths;
	std::string					m_title;
	sf::Text					m_menuText;
	size_t						m_selectedMenuIndex = 0;

	void init();

};

