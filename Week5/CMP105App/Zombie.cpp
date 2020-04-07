#include "Zombie.h"

Zombie::Zombie()
{
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));

	walk.setFrameSpeed(1.f / 10.f);
}

Zombie::~Zombie()
{

}

void Zombie::update(float dt)
{

	setTextureRect(walk.getCurrentFrame());
	walk.animate(dt);
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		walk.setFrameSpeed(1.f / 10.f);
		setVelocity(0, -100);
		move(velocity * dt);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		walk.setFrameSpeed(1.f / 10.f);
		setVelocity(0, 100);
		move(velocity * dt);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		walk.setFrameSpeed(1.f / 10.f);
		setVelocity(-100, 0);
		move(velocity * dt);
		walk.setFlipped(true);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		walk.setFrameSpeed(1.f / 10.f);
		setVelocity(100, 0);
		move(velocity * dt);
		walk.setFlipped(false);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
}