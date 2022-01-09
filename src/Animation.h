#pragma once
 
#include "Common.h"

class Animation
{
public:
	Animation();
	Animation(const std::string& name, const sf::Texture& t);
	Animation(const std::string& name, const sf::Texture& t, size_t cellCount, size_t speed);


	void update();
	bool hasEnded() const;
	const std::string& getName()const ;
	const Vec2& getSize() const;
	sf::Sprite& getSprite();


private:
	sf::Sprite m_sprite;
	size_t m_cellCount = 1;
	size_t m_currentFrame = 0;
	size_t m_speed = 0;
	Vec2 m_size = {1, 1};
	std::string m_name = "none";

};