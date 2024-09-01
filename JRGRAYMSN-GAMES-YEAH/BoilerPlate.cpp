//#include<iostream>
//#include "SFML/Graphics.hpp"
//#include "SFML/System.hpp"
//#include "SFML/Window.hpp"
//
//using namespace sf;
//
//int main() {
//	RenderWindow window(VideoMode(600, 400), "Name Of Window");
//
//	window.setFramerateLimit(60);
//
//	//Define items here
//
//	//While loop that checks to see if the window is open or not. If not open then all statments below don't execute.
//	while (window.isOpen())
//	{
//		//Define event of the Event class
//		Event event;
//
//		//While loop that takes a poll of events (which are just differnt types of inputs. Ex: Closing the window) on the window and assings and action to the corresponding event.
//		while(window.pollEvent(event)){
//
//			//IF user pushes 'x' button on window, window will close
//			if (event.type == Event::Closed)
//				window.close();
//
//			//Closes the window when the user presses escape
//			if (event.type == Keyboard::isKeyPressed(Keyboard::Escape))
//			{
//				window.close();
//			}
//		}
//
//		//Update items here, before you update the window
//
//
//		//Clears window, creating a blank screen
//		window.clear();
//
//		//Draws shapes
//		window.draw();
//
//		//Displays whatever you draw
//		window.display();
//
//	}
//
//	return 0;
//}