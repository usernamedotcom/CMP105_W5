#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Zombie.h"
#include "Mario.h"
#include <string>
#include <iostream>


class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	int MoveHiddenX = 0;
	int MoveHiddenY = 0;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	//level objects 
	sf::Texture ZombieText;
	sf::Texture MarioText;
	sf::Texture ZekeText;
	sf::Texture transparent;
	Zombie ZombieTest;
	Mario testMario;
	sf::CircleShape cursour;
	sf::RectangleShape coverup;
	sf::RectangleShape coverdown;
	sf::RectangleShape coverright;
	sf::RectangleShape coverleft;
	sf::Font font;
	sf::Text information;
};