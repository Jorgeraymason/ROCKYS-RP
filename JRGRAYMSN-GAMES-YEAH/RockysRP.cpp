#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

//Global Variables
int money = 0;

bool hasSpeedCola = false;

bool hasDamageBuff = false;

float rockySpeed = 9.f;


//Function initializations
int fightStoner();

int shopKorge();


//Actual Function
int main()
{
	RenderWindow window(VideoMode(2000, 800), "ROCKYS RP");
	window.setFramerateLimit(60);


	//**ROCKY CHARACTER
	Texture rockyTex;

	if (!rockyTex.loadFromFile("Resource-Files/Images/rocky.png"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape rocky(Vector2f(100.f, 100.f));
	rocky.setTexture(&rockyTex);
	rocky.setPosition(window.getSize().x / 4, window.getSize().y / 6);



	//**STONER CHARACTER
	Texture stonerTex;

	if (!stonerTex.loadFromFile("Resource-Files/Images/stoner.jpg"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape stoner(Vector2f(100.f, 100.f));
	stoner.setTexture(&stonerTex);
	stoner.setPosition(window.getSize().x / 2, 506.f);

	

	//**Outdoor background
	Texture outsideTex;

	if (!outsideTex.loadFromFile("Resource-Files/Images/outside.jpg"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape outside(Vector2f(window.getSize().x, window.getSize().y));
	outside.setTexture(&outsideTex);



	//**Korge Store 
	Texture korgeTex;

	if (!korgeTex.loadFromFile("Resource-Files/Images/korge.jpg"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape korge(Vector2f(100.f, 700.f));
	korge.setTexture(&korgeTex);
	korge.setPosition(0.f, 0.f);

	bool inKorge = false;



	//Font Text
	Font font;
	if (!font.loadFromFile("Resource-Files/Fonts/Comic-Sans-MS.ttf"))
		return EXIT_FAILURE;

	Text text("fight me! ", font, 50);
	text.setPosition(window.getSize().x / 2, 430.f);
	text.setFillColor(Color::Blue);



	//**MUSIC**
	Music wackyMusic;

	if (!wackyMusic.openFromFile("Resource-Files/Audio/wackyMusic.wav"))
	{
		return 1;
	}

	wackyMusic.play();
	wackyMusic.setLoop(true);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}

			//Character movement (for some odd reason it makes me do this, I have to tab it over)
			if (Keyboard::isKeyPressed(Keyboard::Up) && rocky.getPosition().y > 0)
			{	
				rocky.move(0.f, -rockySpeed);
			}

			if (Keyboard::isKeyPressed(Keyboard::Down) && rocky.getPosition().y + rocky.getSize().y < window.getSize().y)
			{	
				rocky.move(0.f, rockySpeed);
			}

			if (Keyboard::isKeyPressed(Keyboard::Left) && rocky.getPosition().x > 0)
			{				
				rocky.move(-rockySpeed, 0.f);
			}

			if (Keyboard::isKeyPressed(Keyboard::Right) && rocky.getPosition().x + rocky.getSize().x < window.getSize().x)
			{
				rocky.move(rockySpeed, 0.f);
			}
		

		//**Game Events**\\


		//Intersect with stoner and fight him
		if (rocky.getGlobalBounds().intersects(stoner.getGlobalBounds()))
		{
			wackyMusic.stop();

			window.close();

			fightStoner();
		}

		
		//Go to the store and shop!
		if (rocky.getGlobalBounds().intersects(korge.getGlobalBounds()))
		{
			wackyMusic.stop();

			window.close();

			shopKorge();
		}


		window.clear();

		window.draw(outside);
		window.draw(rocky);
		window.draw(stoner);
		window.draw(korge);
		window.draw(text);

		window.display();
	}

	return 0;
}


int fightStoner() {
	RenderWindow window(VideoMode(640, 800), "JORGERAYMASON vs ~lost");
	window.setFramerateLimit(60);
	
	//Initialzes variables
	int health = 5;
	int misses;
	float hoopSpeed = 10.f;
	float ballSpeed = -6.f;

	if (hasSpeedCola == true)
	{
		ballSpeed = -11.f;
	}

	//Hoop tex/shape
	Texture stonerTex;

	if (!stonerTex.loadFromFile("Resource-Files/Images/stoner.jpg"))
	{
		throw "file didn't load gang member";
	}

	CircleShape hoop;
	int dir = 0;
	hoop.setRadius(50.f);
	hoop.setPosition(Vector2f(0, 10.f));
	hoop.setTexture(&stonerTex);
	
	//Ball tex/shape
	Texture rockyTex;

	if (!rockyTex.loadFromFile("Resource-Files/Images/rocky.png"))
	{
		throw "file didn't load gang member";
	}

	CircleShape ball;
	bool isShot = false;
	ball.setRadius(20.f);
	ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius() * 3));
	ball.setTexture(&rockyTex);

	while (window.isOpen())
	{
	
		//Font and Text declaration
		Font font;
		if (!font.loadFromFile("Resource-Files/Fonts/Comic-Sans-MS.ttf"))
			return EXIT_FAILURE;
	
		Text text("", font, 50);
		text.setPosition(-3.f, 5.f);
		text.setFillColor(Color::Blue);

	
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
	
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::B))
			{
				window.close();

				main();
			}
		}
	
		//Update
		if (hoop.getPosition().x <= 0)
			dir = 1;
		else if(hoop.getPosition().x + hoop.getRadius() >= window.getSize().x)
			dir = 0;
	
		if (dir == 0)
		{
			hoop.move(-hoopSpeed, 0);
		}
		else
		{
			hoop.move(hoopSpeed, 0);
		}
	
		//Update ball shot
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			isShot = true;
		}
	
		if(!isShot)
			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
		else
			ball.move(0, ballSpeed);
	
		//Collision ball
		if (ball.getPosition().y <= 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
		{
	
			if (ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
			{
				if (hasDamageBuff)
				{
					health -= 3; // decreae health by 3 when the ball collides with the hoop if player has damage buff
				}

				health -= 1; // decreae health by 1 when the ball collides with the hoop
	
				misses = 0;
	
				hoopSpeed += 1.f;
			}
			else
			{
				misses = 1;
	
				if (misses <= 1)
				{
					health = 5;
	
					hoopSpeed = 10.f;
				}
			}

			if (health <= 0)
			{
				window.close();

				money += 10; //Award $10 for beating stoner
				
				main();

			}
	
			//Resets ball position
			isShot = false;
			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
		}
	
		window.clear(Color::White);
	
		// Update health text
		text.setString("Health: " + std::to_string(health));
	
		//Draw
		window.draw(hoop);
	
		window.draw(text);
	
		window.draw(ball);
	
		window.display();
	}
	
	return 0;
}


int shopKorge() {
	RenderWindow window(VideoMode(2000, 800), "KORGE. FEED THE HUMAN SPIRIT");
	window.setFramerateLimit(60);


	//**ROCKY CHARACTER TEX/SHAPE
	Texture rockyTex;

	if (!rockyTex.loadFromFile("Resource-Files/Images/rocky.png"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape rocky(Vector2f(100.f, 100.f));
	rocky.setTexture(&rockyTex);
	rocky.setPosition(window.getSize().x / 2, window.getSize().y / 2);


	//Store background tex
	Texture korgeInsideTex;

	if (!korgeInsideTex.loadFromFile("Resource-Files/Images/korgeInside.jpeg"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape korgeInside(Vector2f(window.getSize().x, window.getSize().y));
	korgeInside.setTexture(&korgeInsideTex);


	//Exit Door shape/texture
	Texture exitDoorTex;

	if (!exitDoorTex.loadFromFile("Resource-Files/Images/door.jpg"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape exitDoor(Vector2f(100.f, 100.f));
	exitDoor.setPosition(Vector2f(0.f, 0.f));
	exitDoor.setTexture(&exitDoorTex);


	//**Shop ITEMS tex/shapes

	//Speed Cola
	Texture speedColaTex;

	if (!speedColaTex.loadFromFile("Resource-Files/Images/speedCola.jpg"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape speedCola(Vector2f(100.f, 100.f));
	speedCola.setTexture(&speedColaTex);
	speedCola.setPosition(110.f, 500.f);


	//Damage Buff
	Texture damageBuffTex;

	if (!damageBuffTex.loadFromFile("Resource-Files/Images/damageBuff.png"))
	{
		throw "file didn't load gang member";
	}

	RectangleShape damageBuff(Vector2f(100.f, 100.f));
	damageBuff.setTexture(&damageBuffTex);
	damageBuff.setPosition(530.f, 250.f);


	//Store music
	Music korgeMusic;

	if (!korgeMusic.openFromFile("Resource-Files/Audio/korgeMusic.wav"))
	{
		return 1;
	}

	korgeMusic.play();
	korgeMusic.setLoop(true);


	while (window.isOpen())
	{
		//Font and Text declaration
		Font font;
		if (!font.loadFromFile("Resource-Files/Fonts/Comic-Sans-MS.ttf"))
			return EXIT_FAILURE;

		//Money Text display
		Text text("", font, 50);
		text.setPosition(110.f, 5.f);
		text.setFillColor(Color::Black);


		//Item text description
		Text desc("", font, 35);
		desc.setFillColor(Color::White);


		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();
		}

		if (event.type == Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && rocky.getPosition().y > 0)
		{
			rocky.move(0.f, -rockySpeed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && rocky.getPosition().y + rocky.getSize().y < window.getSize().y)
		{
			rocky.move(0.f, rockySpeed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && rocky.getPosition().x > 0)
		{
			rocky.move(-rockySpeed, 0.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && rocky.getPosition().x + rocky.getSize().x < window.getSize().x)
		{
			rocky.move(rockySpeed, 0.f);
		}

		//Exit the shop
		if (rocky.getGlobalBounds().intersects(exitDoor.getGlobalBounds()))
		{
			korgeMusic.stop();

			window.close();

			main();
		}


		//Buy speedCola
		if (rocky.getGlobalBounds().intersects(speedCola.getGlobalBounds()))
		{
			int price = 10;

			desc.setPosition(95.f, 450.f);
			desc.setString("Speed Cola: $10. Increases movement speed/Speed in battle. (Left Click to buy)");


			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (!hasSpeedCola && money >= price)
				{
					hasSpeedCola = true;

					money -= price;

					rockySpeed = 13.f;

					desc.setString("Speed Cola purchased successfully!");
				}
				else
				{
					desc.setString("Insufficient funds!");
				}

				//If user has item unlocked, when they hover over it, it will display that they own it
				if (hasSpeedCola)
				{
					desc.setString("You already own this item.");
				}

				// Add a small delay to prevent multiple purchases on a single click
				sf::sleep(sf::milliseconds(200));
			}
		}


		//Buy Damage Buff
		if (rocky.getGlobalBounds().intersects(damageBuff.getGlobalBounds()))
		{
			int price = 30;

			desc.setPosition(400.f, 230.f);
			desc.setString("Damage Buff: $30. Hit harder in battle. (Left Click to buy)");


			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (!hasDamageBuff && money >= price)
				{
					hasDamageBuff = true;

					money -= price;

					desc.setString("Damage Buff purchased successfully!");
				}
				else
				{
					desc.setString("Insufficient funds!");
				}

				//If user has item unlocked, when they hover over it, it will display that they own it
				if (hasDamageBuff)
				{
					desc.setString("You already own this item.");
				}

				// Add a small delay to prevent multiple purchases on a single click
				sf::sleep(sf::milliseconds(200));
			}
		}


		// Update money balance text
		text.setString("Money: $" + std::to_string(money));


		window.clear();

		window.draw(korgeInside);

		window.draw(rocky);

		window.draw(text);

		window.draw(exitDoor);

		window.draw(speedCola);

		window.draw(damageBuff);

		window.draw(desc);

		window.display();

	}

	return 0;
}

