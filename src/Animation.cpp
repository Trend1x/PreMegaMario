#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(const std::string& name, const sf::Texture& t)
	: Animation(name, t, 1, 0)
{
}

Animation::Animation(const std::string& name, const sf::Texture& t, size_t cellCount, size_t speed)
	: m_name(name), m_sprite(t), m_cellCount(cellCount), m_currentFrame(0), m_speed(speed)
{
	m_size = Vec2((float)t.getSize().x / m_cellCount, (float)t.getSize().y);
	m_sprite.setOrigin(m_size.x / 2.0f, m_size.y / 2.0f);
	m_sprite.setTextureRect(sf::IntRect(std::floor(m_currentFrame) * m_size.x, 0, m_size.x, m_size.y));
}

//updates the current animation to show the next frame, depending on its speed
//animation loops whien it reaches the end
void Animation::update()
{
	//add the speed variable to the current frame
	//TODO: 1) calculate the correct frame of animation to play based on the currentFrame and speed
	//		2) set the texture rectangle properly (see constructor for sample)
}

const Vec2& Animation::getSize() const
{
	return m_size;
}

const std::string& Animation::getName() const
{
	return m_name;
}

sf::Sprite& Animation::getSprite()
{
	return m_sprite;
}

bool Animation::hasEnded() const
{
	return false;
}



