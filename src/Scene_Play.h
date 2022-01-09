#pragma once
#include "Scene.h"

class Scene_Play : public Scene
{

public:
	Scene_Play(GameEngine* gameEngine, const std::string& levelPath);
	void update() override;
	void sDoAction(const Action& action) override;
	void sRender() override;
	void onEnd();

	//Systems
	void sAnimation();
	void drawLine(const Vec2& p1, const Vec2& p2);
	void sMovement();
	void sLifeSpan();
	//void sEnemySpawner();
	void sCollision();

	//void sDebug();

private:
	struct PlayerConfig
	{
		float X, Y, CX, CY, SPEED, MAXSPEED, JUMP, GRAVITY;
		std::string WEAPON;
	};

protected:
	ptr<Entity> m_player;
	std::string m_levelPath;
	PlayerConfig m_playerConfig;
	bool m_drawTextures = true;
	bool m_drawCollision = false;
	bool m_drawGrid = false;
	const Vec2	m_gridSize = { 64, 64 };
	sf::Text m_gridText;

	void init(const std::string & path);
	Vec2 gridToMidPixel(float gridX, float gridY, ptr<Entity> entity);
	void loadLevel(const std::string& filename);

	void spawnPlayer();

	void spawnBullet(ptr<Entity> entity);




};

