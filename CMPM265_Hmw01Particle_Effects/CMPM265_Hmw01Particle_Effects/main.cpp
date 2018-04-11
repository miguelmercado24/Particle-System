//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include"Particle.h"
#include"Particle System.h"


int main()
{
	// create the window
	RenderWindow window(VideoMode(512, 512), "Particles");

	// create the particle system
	ParticleSystem particles(1000);

	// create a clock to track the elapsed time
	Clock clock;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// make the particle system emitter follow the mouse
		Vector2i mouse = Mouse::getPosition(window);
		particles.setEmitter(window.mapPixelToCoords(mouse));

		// update it
		Time elapsed = clock.restart();
		particles.update(elapsed);

		// draw it
		window.clear();
		window.draw(particles);
		window.display();
	}

	return 0;
}
