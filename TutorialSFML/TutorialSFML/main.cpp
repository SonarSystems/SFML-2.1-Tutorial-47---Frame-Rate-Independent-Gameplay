#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	window.setFramerateLimit(15);

	sf::Sprite sprite;

	sf::Texture texture;

	if (!texture.loadFromFile("Paddle Large.png"))
	{
		// handle error
	}

	sprite.setTexture(texture);

	sf::Clock clock;
	

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

			}
		}

		sf::Time time = clock.getElapsedTime();

		sprite.move(sf::Vector2f(0, 0.5 * time.asMilliseconds()));

		clock.restart().asMilliseconds();

		window.clear();

		window.draw(sprite);

		window.display();
	}
}