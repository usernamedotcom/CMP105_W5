#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	ZombieTest.setInput(in);
	testMario.setInput(in);

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading font\n";
	}
	information.setFont(font);
	information.setString("this text is above");
	information.setPosition(250, 0);
	information.setCharacterSize(24);
	information.setFillColor(sf::Color::Red);

	// initialise game objects
	ZombieText.loadFromFile("gfx/animZombie.png");
	ZombieTest.setSize(sf::Vector2f(55, 108));
	ZombieTest.setPosition(500, 500);
	ZombieTest.setTexture(&ZombieText);

	MarioText.loadFromFile("gfx/MarioSheetT.png");
	testMario.setSize(sf::Vector2f(16, 21));
	testMario.setPosition(200, 200);
	testMario.setTexture(&MarioText);

	transparent.loadFromFile("gfx/transparent.png");
	cursour.setTexture(&transparent);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
}

// Update game objects
void Level::update(float dt)
{
	ZombieTest.update(dt);
	ZombieTest.handleInput(dt);
	testMario.update(dt);
	testMario.handleInput(dt);

	cursour.setPosition(input->getMouseX() - 12, input->getMouseY() - 12);
	cursour.setRadius(20);


	sf::Vector2u pos = window->getSize();
	int posx = window->getSize().x;
	int posy = window->getSize().y;

	coverup.setSize(sf::Vector2f(pos) - ((sf::Vector2f(0, posy / 1.1) - sf::Vector2f(0, MoveHiddenY - (posy / 6.75)))));
	coverup.setPosition(sf::Vector2f(pos) - sf::Vector2f(pos));
	coverup.setFillColor(sf::Color::Black);

	coverleft.setSize(sf::Vector2f(pos) - (sf::Vector2f(posx / 1.3, 0) - sf::Vector2f(MoveHiddenX - (posx / 3.63), 0)));
	coverleft.setPosition(sf::Vector2f(pos) - sf::Vector2f(pos));
	coverleft.setFillColor(sf::Color::Black);

	coverdown.setSize((sf::Vector2f(pos)) - ((sf::Vector2f(pos) + sf::Vector2f(posx, posy / 1.3)) - sf::Vector2f(0, MoveHiddenY - (posy / 6.75))));
	coverdown.setPosition(sf::Vector2f(pos));
	coverdown.setFillColor(sf::Color::Black);

	coverright.setSize(sf::Vector2f(pos) - ((sf::Vector2f(pos) + sf::Vector2f(posx / 1.5, posy)) - sf::Vector2f(MoveHiddenX - (posx / 3.63), 0)));
	coverright.setPosition(sf::Vector2f(pos));
	coverright.setFillColor(sf::Color::Black);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		MoveHiddenX = input->getMouseX();
		MoveHiddenY = input->getMouseY();
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ZombieTest);
	window->draw(testMario);
	window->draw(coverup);
	window->draw(coverdown);
	window->draw(coverleft);
	window->draw(coverright);
	window->draw(information);
	//window->draw(cursour);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}