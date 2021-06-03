#include "SFML/Graphics.hpp"

#include "ScreenManager.h"
#include "Input.h"
#include "GeneralVariables.h"

#include "Level.h"

//Initalise GeneralVariables static variables.
sf::Font GeneralVariables::font_;

void main()
{
	// Create window
	sf::Vector2u window_size(800, 800);
	sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Deck Building Game");

	//Initialise font variable.
	GeneralVariables::font_.loadFromFile("fonts/consola.ttf");

	//Initialise Clock Object.
	sf::Clock clock;

	//Initialise Input Object.
	Input input;

	//Initialise Screen Manager Object.
	ScreenManager screen;

	//Initialise Screens.
	Level level(&window, &input, &screen);

	// Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setSize(window_size);
				window.setView(sf::View(sf::FloatRect(0.f, 0.f,
					(float)event.size.width, (float)event.size.height)));
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				//update input class
				input.setMousePosition(event.mouseMove.x,
					event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(false);
				}
				break;
			default:
				// don't Hand_le other events
				break;
			}
		}

		float dt = clock.restart().asSeconds();

		switch (screen.getCurrentScreen()) {
		case screen.LEVEL:
			if (!level.Update(dt)) {
				return;
			}
			level.Render();
			break;
		}
	}
}