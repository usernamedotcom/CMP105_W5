#include "Mario.h"

Mario::Mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));

	swim.addFrame(sf::IntRect(0, 21, 16, 21));
	swim.addFrame(sf::IntRect(16, 21, 16, 21));
	swim.addFrame(sf::IntRect(32, 21, 16, 21));

	crouch.addFrame(sf::IntRect(0, 41, 16, 20));
	crouch.addFrame(sf::IntRect(16, 20, 16, 20));

	walk.setFrameSpeed(1.f / 10.f);
	swim.setFrameSpeed(1.f / 10.f);
	crouch.setFrameSpeed(1.f / 10.f);
}

Mario::~Mario()
{

}
void Mario::update(float dt)
{


	setTextureRect(crouch.getCurrentFrame());
	crouch.animate(dt);
}

void Mario::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		setVelocity(0, -100);
		move(velocity * dt);
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		setVelocity(0, 100);
		move(velocity * dt);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		setVelocity(-100, 0);
		move(velocity * dt);
		walk.setFlipped(true);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		setVelocity(100, 0);
		move(velocity * dt);
		walk.setFlipped(false);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}

}