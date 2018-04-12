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
#include"ParticleSystem.h"
#include"Globals.h"


int main()
{
	// create the window
	RenderWindow window(VideoMode(512, 512), "Particles");

	//begining number of particles
	int prt = 1000;

	// create the particle system
	ParticleSystem particles(prt);

	// create a clock to track the elapsed time
	Clock clock;


	//Loading Roboto Font
	Font font;
	font.loadFromFile("Font/DS-DIGIB.ttf");
	if (!font.loadFromFile("Font/DS-DIGIB.ttf"))
	{
		return 0;
	}

	//Textures
	t1.loadFromFile("images/explosions/type_B.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/explosions/type_C.png");
	t4.loadFromFile("images/rock.png");
	t5.loadFromFile("images/fire_blue.png");
	t6.loadFromFile("images/rock_small.png");
	
	t1.setSmooth(true);
	t2.setSmooth(true);

	//Setting the background sprite
	Sprite background(t2);

	//Animations
	Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
	Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
	Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
	Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
	Animation sExplosion_ship(t1, 0, 0, 192, 192, 64, 0.5);

	//Text for Number of Particles
	sf::Text pText;
	pText.setFont(font);
	pText.setCharacterSize(40);
	pText.setPosition(125, 10);
	pText.setFillColor(Color::Red);
	pText.setOutlineThickness(3);
	pText.setOutlineColor(Color::Black);
	pText.setString("Particles: ");


	// run the main loop
	while (window.isOpen())
	{
		// handle events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// make the particle system emitter follow the mouse
		Vector2i mouse = Mouse::getPosition(window);
		if (Mouse::isButtonPressed(sf::Mouse::Left))
		{
			particles.setEmitter(window.mapPixelToCoords(mouse));
		}
		
		//particles.setEmitter(250);

		// update it
		Time elapsed = clock.restart();
		particles.update(elapsed);

		//Updating the Particle display
		stringstream sS;
		sS << prt;
		pText.setString("Particles: " + sS.str());

		// draw it
		window.clear();
		window.draw(particles);
		window.draw(pText);
		window.display();
	}

	return 0;
}
