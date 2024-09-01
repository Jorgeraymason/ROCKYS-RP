//#include <iostream>
//#include <SFML/Graphics.hpp> 
//#include <SFML/Audio.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include<cstdlib>
//
//using namespace sf;
//using namespace std;
//
//int testFunction();
//
//int main()
//{
//    RenderWindow window(VideoMode(2000, 400), "Pastor Jennings Popped up on the youtube");
//    window.setFramerateLimit(60);
//
//
//    //Minister Baker Sprite
//    Texture minBakerTex;
//    Sprite minBaker;
//
//    if (!minBakerTex.loadFromFile("Resource-Files/Images/minBaker.png"))
//    {
//        throw "file didn't load gang member";
//    }
//
//    minBaker.setTexture(minBakerTex);
//    minBaker.setScale(Vector2f(1.f, 0.4f));
//
//    Music PJPUOTYT;
//
//    if (!PJPUOTYT.openFromFile("Resource-Files/Audio/PJPUOTYT.wav"))
//    {
//        return 1;
//    }
//
//    PJPUOTYT.setLoop(true);
//    PJPUOTYT.play();
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//            {
//                window.close();
//            }
//
//            if (Keyboard::isKeyPressed(Keyboard::Space))
//            {
//                main();
//            }
//        }
//
//        //UPDATE
//
//
//        //DRAW
//        window.clear();
//
//        window.draw(minBaker);
//
//        window.display();
//    }
//
//    return 0;
//}
//
//int testFunction() {
//    RenderWindow window(VideoMode(640, 400), "JORGERAYMASON Lurnnz how two code ES-EM-EF-ELL");
//    window.setFramerateLimit(60);
//
//    CircleShape shape(50.f);
//    CircleShape shape2(50.f);
//    RectangleShape shape3(Vector2f(300.f, 25.f));
//
//    Music PJPUOTYT;
//
//    if (!PJPUOTYT.openFromFile("Resource-Files/Audio/PJPUOTYT.wav"))
//    {
//        return 1;
//    }
//
//    PJPUOTYT.setLoop(true);
//    PJPUOTYT.play();
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//            {
//                window.close();
//            }
//        }
//
//        //UPDATE
//
//
//        //DRAW
//        window.clear();
//
//        window.draw(shape);
//
//        window.display();
//    }
//
//    return 0;
//}