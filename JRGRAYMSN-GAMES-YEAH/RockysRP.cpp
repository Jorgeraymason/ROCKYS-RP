#include <iostream>
#include <fstream>
#include <string>
#include <sfml/graphics.hpp>
#include <sfml/window.hpp>
#include <sfml/system.hpp>
#include <sfml/system/clock.hpp>
#include <sfml/audio.hpp>

using namespace sf;
using namespace std;



//**global variables**
int money = 0;

bool hasspeedcola = false;

bool hasdamagebuff = false;

float rockyspeed = 9.f;



//**function initializations**

//in-game event functions
int fightstoner();

int namelessinvasion();

int shopkorge();

//utility functions
int savegame();

int loadgame();


int main()
{
	renderwindow window(videomode(2000, 800), "rockys rp");
	window.setframeratelimit(60);


	//**jorgeraymason character
	texture rockytex;

	if (!rockytex.loadfromfile("resource-files/images/rocky.png"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape rocky(vector2f(100.f, 100.f));
	rocky.settexture(&rockytex);
	rocky.setposition(window.getsize().x / 4, window.getsize().y / 6);



	//**~lost character
	texture stonertex;

	if (!stonertex.loadfromfile("resource-files/images/stoner.jpg"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape stoner(vector2f(100.f, 100.f));
	stoner.settexture(&stonertex);
	stoner.setposition(window.getsize().x / 2, 506.f);



	//**namelessbrown character
	texture namelesstex;

	if (!namelesstex.loadfromfile("resource-files/images/namelessbrown.png"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape nameless(vector2f(100.f, 100.f));
	nameless.settexture(&namelesstex);
	nameless.setposition(1420.f, 606.f);



	//**outdoor background
	texture outsidetex;

	if (!outsidetex.loadfromfile("resource-files/images/outside.jpg"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape outside(vector2f(window.getsize().x, window.getsize().y));
	outside.settexture(&outsidetex);



	//**korge store 
	texture korgetex;

	if (!korgetex.loadfromfile("resource-files/images/korge.jpg"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape korge(vector2f(100.f, 700.f));
	korge.settexture(&korgetex);
	korge.setposition(0.f, 0.f);

	bool inkorge = false;



	//**font text
	font font;
	if (!font.loadfromfile("resource-files/fonts/comic-sans-ms.ttf"))
		return exit_failure;

	text text("", font, 25);
	text.setfillcolor(color::blue);



	//**music**
	music wackymusic;

if (!wackymusic.openfromfile("resource-files/audio/wackymusic.wav"))
	{
		return 1;
	}

	
	//play music

	//wackymusic.play();
	//wackymusic.setloop(true);

	while (window.isopen())
	{
		event event;
		while (window.pollevent(event))
		{
			if (event.type == event::closed)
			{
				window.close();
			}

			if (keyboard::iskeypressed(keyboard::escape))
			{
				window.close();
			}

		}

			//character movement (for some odd reason it makes me do this, i have to tab it over)
			if (keyboard::iskeypressed(keyboard::up) && rocky.getposition().y > 0)
			{	
				rocky.move(0.f, -rockyspeed);
			}

			if (keyboard::iskeypressed(keyboard::down) && rocky.getposition().y + rocky.getsize().y < window.getsize().y)
			{	
				rocky.move(0.f, rockyspeed);
			}

			if (keyboard::iskeypressed(keyboard::left) && rocky.getposition().x > 0)
			{				
				rocky.move(-rockyspeed, 0.f);
			}

			if (keyboard::iskeypressed(keyboard::right) && rocky.getposition().x + rocky.getsize().x < window.getsize().x)
			{
				rocky.move(rockyspeed, 0.f);
			}

			//saves game
			if (keyboard::iskeypressed(keyboard::s))
			{
				if (savegame() == 0) {
					text.setposition(window.getsize().x / 2, window.getsize().y / 2);
					text.setstring("game progress saved.");
				}
				else {
					text.setstring("failed to save game.");
				}
			}


			//loads game
			if (keyboard::iskeypressed(keyboard::l))
			{
				if (loadgame() == 0) {
					text.setposition(window.getsize().x / 2, window.getsize().y / 2);
					text.setstring("game loaded.");
				}
				else {
					text.setstring("failed to load game.");
				}
			}
			

		//**game events**\\

		
		//intersect with ~lost and fight him
		if (rocky.getglobalbounds().intersects(stoner.getglobalbounds()))
		{
			text.setposition(stoner.getposition().x, stoner.getposition().y + 200);
			text.setstring("fight me! (press enter to fight stoner)");

			if (keyboard::iskeypressed(keyboard::enter))
			{
				wackymusic.stop();

				window.close();

				fightstoner();
			}
		}

		
		//go to the store and shop!
		if (rocky.getglobalbounds().intersects(korge.getglobalbounds()))
		{
			wackymusic.stop();

			window.close();

			shopkorge();
		}


		//the invasion of namelessbrown!
		if (rocky.getglobalbounds().intersects(nameless.getglobalbounds()))
		{
			text.setposition(nameless.getposition().x - 1000, nameless.getposition().y / 4);
			text.setstring("i will invade the world! i must first overthrow the freemasons....(press enter to stop the nameless invasion)");

			if (keyboard::iskeypressed(keyboard::enter))
			{
				wackymusic.stop();

				window.close();

				namelessinvasion();
			}
		}


		window.clear();

		window.draw(outside);
		window.draw(rocky);
		window.draw(stoner);
		window.draw(nameless);
		window.draw(korge);
		window.draw(text);

		window.display();
	}

	return 0;
}


int savegame() {
	ofstream file("gamedata.txt");
	if (file.is_open()) {
		file << money << endl;
		file << hasspeedcola << endl;
		file << hasdamagebuff << endl;
		file << rockyspeed << endl;
		file.close();
		cout << "game saved successfully!" << endl;
		return 0;
	}
	else {
		cout << "unable to open file for saving." << endl;
		return 1;
	}
}


int loadgame() {
	ifstream file("gamedata.txt");
	if (file.is_open()) {
		file >> money;
		file >> hasspeedcola;
		file >> hasdamagebuff;
		file >> rockyspeed;
		file.close();
		cout << "game loaded successfully!" << endl;
		return 0;
	}
	else {
		cout << "unable to open file for loading." << endl;
		return 1;
	}
}


int fightstoner() {
	renderwindow window(videomode(640, 800), "jorgeraymason vs ~lost");
	window.setframeratelimit(60);
	

	//initialzes variables
	int health = 5;
	int misses;
	float hoopspeed = 10.f;
	float ballspeed = -6.f;

	if (hasspeedcola == true)
	{
		ballspeed = -11.f;
	}

	//hoop tex/shape
	texture stonertex;

	if (!stonertex.loadfromfile("resource-files/images/stoner.jpg"))
	{
		throw "file didn't load gang member";
	}

	circleshape hoop;
	int dir = 0;
	hoop.setradius(50.f);
	hoop.setposition(vector2f(0, 10.f));
	hoop.settexture(&stonertex);
	
	//ball tex/shape
	texture rockytex;

	if (!rockytex.loadfromfile("resource-files/images/rocky.png"))
	{
		throw "file didn't load gang member";
	}

	circleshape ball;
	bool isshot = false;
	ball.setradius(20.f);
	ball.setposition(vector2f(0, window.getsize().y - ball.getradius() * 3));
	ball.settexture(&rockytex);

	while (window.isopen())
	{
	
		//font and text declaration
		font font;
		if (!font.loadfromfile("resource-files/fonts/comic-sans-ms.ttf"))
			return exit_failure;
	
		text text("", font, 50);
		text.setposition(-3.f, 5.f);
		text.setfillcolor(color::blue);

	
		event event;
		while (window.pollevent(event))
		{
			if (event.type == event::closed)
			{
				window.close();
			}
	
			if (keyboard::iskeypressed(keyboard::escape))
			{
				window.close();
			}

			if (keyboard::iskeypressed(keyboard::b))
			{
				window.close();

				main();
			}
		}
	
		//update
		if (hoop.getposition().x <= 0)
			dir = 1;
		else if(hoop.getposition().x + hoop.getradius() >= window.getsize().x)
			dir = 0;
	
		if (dir == 0)
		{
			hoop.move(-hoopspeed, 0);
		}
		else
		{
			hoop.move(hoopspeed, 0);
		}
	
		//update ball shot
		if (mouse::isbuttonpressed(mouse::left))
		{
			isshot = true;
		}
	
		if(!isshot)
			ball.setposition(mouse::getposition(window).x, ball.getposition().y);
		else
			ball.move(0, ballspeed);
	
		//collision ball
		if (ball.getposition().y <= 0 || ball.getglobalbounds().intersects(hoop.getglobalbounds()))
		{
	
			if (ball.getglobalbounds().intersects(hoop.getglobalbounds()))
			{
				if (hasdamagebuff)
				{
					health -= 3; // decreae health by 3 when the ball collides with the hoop if player has damage buff
				}

				health -= 1; // decreae health by 1 when the ball collides with the hoop
	
				misses = 0;
	
				hoopspeed += 1.f;
			}
			else
			{
				misses = 1;
	
				if (misses <= 1)
				{
					health = 5;
	
					hoopspeed = 10.f;
				}
			}

			if (health <= 0)
			{
				window.close();

				money += 10; //award $10 for beating stoner
				
				main();

			}
	
			//resets ball position
			isshot = false;
			ball.setposition(ball.getposition().x, window.getsize().y - ball.getradius() * 3);
		}
	
		window.clear(color::white);
	
		// update health text
		text.setstring("health: " + std::to_string(health));
	
		//draw
		window.draw(hoop);
	
		window.draw(text);
	
		window.draw(ball);
	
		window.display();
	}
	
	return 0;
}


int shopkorge() {
	renderwindow window(videomode(2000, 800), "korge. feed the human spirit");
	window.setframeratelimit(60);


	//**rocky character tex/shape
	texture rockytex;

	if (!rockytex.loadfromfile("resource-files/images/rocky.png"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape rocky(vector2f(100.f, 100.f));
	rocky.settexture(&rockytex);
	rocky.setposition(window.getsize().x / 2, window.getsize().y / 2);


	//store background tex
	texture korgeinsidetex;

	if (!korgeinsidetex.loadfromfile("resource-files/images/korgeinside.jpeg"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape korgeinside(vector2f(window.getsize().x, window.getsize().y));
	korgeinside.settexture(&korgeinsidetex);


	//exit door shape/texture
	texture exitdoortex;

	if (!exitdoortex.loadfromfile("resource-files/images/door.jpg"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape exitdoor(vector2f(100.f, 100.f));
	exitdoor.setposition(vector2f(0.f, 0.f));
	exitdoor.settexture(&exitdoortex);


	//**shop items tex/shapes

	//speed cola
	texture speedcolatex;

	if (!speedcolatex.loadfromfile("resource-files/images/speedcola.jpg"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape speedcola(vector2f(100.f, 100.f));
	speedcola.settexture(&speedcolatex);
	speedcola.setposition(110.f, 500.f);


	//damage buff
	texture damagebufftex;

	if (!damagebufftex.loadfromfile("resource-files/images/damagebuff.png"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape damagebuff(vector2f(100.f, 100.f));
	damagebuff.settexture(&damagebufftex);
	damagebuff.setposition(530.f, 250.f);


	//store music
	music korgemusic;

	if (!korgemusic.openfromfile("resource-files/audio/korgemusic.wav"))
	{
		return 1;
	}

	//korgemusic.play();
	//korgemusic.setloop(true);


	while (window.isopen())
	{
		//font and text declaration
		font font;
		if (!font.loadfromfile("resource-files/fonts/comic-sans-ms.ttf"))
			return exit_failure;

		//money text display
		text text("", font, 50);
		text.setposition(110.f, 5.f);
		text.setfillcolor(color::black);


		//item text description
		text desc("", font, 35);
		desc.setfillcolor(color::white);


		event event;
		while (window.pollevent(event)) {

			if (event.type == event::closed)
				window.close();
		}

		if (event.type == keyboard::iskeypressed(keyboard::escape))
		{
			window.close();
		}

		if (keyboard::iskeypressed(keyboard::up) && rocky.getposition().y > 0)
		{
			rocky.move(0.f, -rockyspeed);
		}

		if (keyboard::iskeypressed(keyboard::down) && rocky.getposition().y + rocky.getsize().y < window.getsize().y)
		{
			rocky.move(0.f, rockyspeed);
		}

		if (keyboard::iskeypressed(keyboard::left) && rocky.getposition().x > 0)
		{
			rocky.move(-rockyspeed, 0.f);
		}

		if (keyboard::iskeypressed(keyboard::right) && rocky.getposition().x + rocky.getsize().x < window.getsize().x)
		{
			rocky.move(rockyspeed, 0.f);
		}

		//exit the shop
		if (rocky.getglobalbounds().intersects(exitdoor.getglobalbounds()))
		{
			korgemusic.stop();

			window.close();

			main();
		}


		//buy speedcola
		if (rocky.getglobalbounds().intersects(speedcola.getglobalbounds()))
		{
			int price = 10;

			desc.setposition(95.f, 450.f);
			desc.setstring("speed cola: $10. increases movement speed/speed in battle. (left click to buy)");


			if (mouse::isbuttonpressed(mouse::left))
			{
				if (!hasspeedcola && money >= price)
				{
					hasspeedcola = true;

					money -= price;

					rockyspeed = 13.f;

					desc.setstring("speed cola purchased successfully!");
				}
				else
				{
					desc.setstring("insufficient funds!");
				}

				//if user has item unlocked, when they hover over it, it will display that they own it
				if (hasspeedcola)
				{
					desc.setstring("you already own this item.");
				}

				// add a small delay to prevent multiple purchases on a single click
				sf::sleep(sf::milliseconds(200));
			}
		}


		//buy damage buff
		if (rocky.getglobalbounds().intersects(damagebuff.getglobalbounds()))
		{
			int price = 30;

			desc.setposition(400.f, 230.f);
			desc.setstring("damage buff: $30. hit harder in battle. (left click to buy)");


			if (mouse::isbuttonpressed(mouse::left))
			{
				if (!hasdamagebuff && money >= price)
				{
					hasdamagebuff = true;

					money -= price;

					desc.setstring("damage buff purchased successfully!");
				}
				else
				{
					desc.setstring("insufficient funds!");
				}

				//if user has item unlocked, when they hover over it, it will display that they own it
				if (hasdamagebuff)
				{
					desc.setstring("you already own this item.");
				}

				// add a small delay to prevent multiple purchases on a single click
				sf::sleep(sf::milliseconds(200));
			}
		}


		// update money balance text
		text.setstring("money: $" + std::to_string(money));


		window.clear();

		window.draw(korgeinside);

		window.draw(rocky);

		window.draw(text);

		window.draw(exitdoor);

		window.draw(speedcola);

		window.draw(damagebuff);

		window.draw(desc);

		window.display();

	}

	return 0;
}


int namelessinvasion() {

	renderwindow window(videomode(600, 400), "invasion of namelessbrown!");
	
	window.setframeratelimit(60);


	//**jorgeraymason character
	texture rockytex;

	if (!rockytex.loadfromfile("resource-files/images/rocky.png"))
	{
		throw "file didn't load gang member";
	}

	rectangleshape rocky(vector2f(100.f, 100.f));
	rocky.settexture(&rockytex);
	rocky.setposition(window.getsize().x / 4, window.getsize().y / 6);

	
	
	while (window.isopen())
	{
		event event;
	
		while(window.pollevent(event)){
	
			if (event.type == event::closed)
				window.close();
	
			if (event.type == keyboard::iskeypressed(keyboard::escape))
			{
				window.close();
			}
			if (keyboard::iskeypressed(keyboard::b))
			{
				window.close();

				main();
			}
		}

			//character movement (for some odd reason it makes me do this, i have to tab it over)
			if (keyboard::iskeypressed(keyboard::up) && rocky.getposition().y > 0)
			{
				rocky.move(0.f, -rockyspeed);
			}

			if (keyboard::iskeypressed(keyboard::down) && rocky.getposition().y + rocky.getsize().y < window.getsize().y)
			{
				rocky.move(0.f, rockyspeed);
			}

			if (keyboard::iskeypressed(keyboard::left) && rocky.getposition().x > 0)
			{
				rocky.move(-rockyspeed, 0.f);
			}

			if (keyboard::iskeypressed(keyboard::right) && rocky.getposition().x + rocky.getsize().x < window.getsize().x)
			{
				rocky.move(rockyspeed, 0.f);
			}
	

		window.clear();
	
		//draws shapes
		window.draw(rocky);
	
		//displays whatever you draw
		window.display();
	
	}
	
	return 0;
}
