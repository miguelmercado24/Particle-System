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
#include"ParticleManager.h"


int main()
{

	//// create the particle system
	ParticleManager systems(prt);

	// create a clock to track the elapsed time
	Clock clock;

	//Loading Roboto Font
	Font font;
	font.loadFromFile("Font/DS-DIGIB.ttf");
	if (!font.loadFromFile("Font/DS-DIGIB.ttf"))
	{
		return 0;
	}

	//set the texture for the particles
	systems.setSystemsText();

	//Text for Number of Particles
	pText.setFont(font);
	pText.setCharacterSize(40);
	pText.setPosition(525, 10);
	pText.setFillColor(Color::Red);
	pText.setOutlineThickness(3);
	pText.setOutlineColor(Color::Black);
	pText.setString("Particles: ");

	//Text for Liner System
	lText.setFont(font);
	lText.setCharacterSize(40);
	lText.setPosition(150, 700);
	lText.setFillColor(Color::Red);
	lText.setOutlineThickness(3);
	lText.setOutlineColor(Color::Black);
	lText.setString("Linear");

	//Text for Exponential System
	eText.setFont(font);
	eText.setCharacterSize(40);
	eText.setPosition(600, 700);
	eText.setFillColor(Color::Red);
	eText.setOutlineThickness(3);
	eText.setOutlineColor(Color::Black);
	eText.setString("Exponential");

	//Text for Sin System
	sText.setFont(font);
	sText.setCharacterSize(40);
	sText.setPosition(1200, 700);
	sText.setFillColor(Color::Red);
	sText.setOutlineThickness(3);
	sText.setOutlineColor(Color::Black);
	sText.setString("Sin");

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
		//Vector2i mouse = Mouse::getPosition(window);
		//if (Mouse::isButtonPressed(sf::Mouse::Left))
		//{
		//	//particles.setEmitter(window.mapPixelToCoords(mouse));
		//	systems.setEmitterPos(window.mapPixelToCoords(mouse));
		//	
		//}
		
		// update it
		Time elapsed = clock.restart();
		systems.Update(elapsed);

		//Updating the Particle display
		stringstream sS;
		sS << prt;
		pText.setString("Particles: " + sS.str());

		// draw it
		window.clear();
		window.draw(pText);
		window.draw(lText);
		window.draw(eText);
		window.draw(sText);
		for (Particle p : systems.system1->m_particles)
		{
			window.draw(p.vertex);
		}
		for (Particle p : systems.system2->m_particles)
		{
			window.draw(p.vertex);
		}
		for (Particle p : systems.system3->m_particles)
		{
			window.draw(p.vertex);
		}

		window.display();
	}

	return 0;
}
