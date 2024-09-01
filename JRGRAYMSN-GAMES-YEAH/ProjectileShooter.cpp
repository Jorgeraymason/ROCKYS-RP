//#include <iostream>
//#include "SFML\Graphics.hpp"
//#include "SFML\Window.hpp"
//#include "SFML\System.hpp"
//#include<cstdlib>c  
//
//#include<vector>
//
//using namespace sf;
//
//int main()
//{
//    srand(time(NULL));
//
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Rip-off Space Invaders");
//    window.setFramerateLimit(60);
//    
//    //Balls
//    CircleShape projectile;
//    projectile.setFillColor(Color::Red);
//    projectile.setRadius(5.f);
//
//    RectangleShape enemy;
//    enemy.setFillColor(Color::Blue);
//    enemy.setSize(Vector2f(50.f, 50.f));
//
//    std::vector<RectangleShape> enemies;
//    enemies.push_back(RectangleShape(enemy));
//    
//    CircleShape player;
//    player.setFillColor(Color::White);
//    player.setRadius(50.f);
//    player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y - player.getRadius() * 2 - 10.f);
//    Vector2f playerCenter;
//
//    int shootTimer = 0;
//
//    std::vector<CircleShape> projectiles;
//    projectiles.push_back(CircleShape(projectile));
//
//    std::vector<RectangleShape> enemies;
//    enemies.push_back(RectangleShape(enemy));
//
//    int enemySpawnTimer = 0;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        //UPDATE
//        //PLAYER
//        playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
//
//        player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);
//
//        if (shootTimer < 5)
//        {
//            shootTimer++;
//        }
//
//        player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);
//
//        if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 3)
//        {
//            projectile.setPosition(playerCenter);
//            projectiles.push_back(CircleShape(projectile));
//
//            shootTimer = 0;
//        }
//
//        for (size_t i = 0; i < projectiles.size(); i++)
//        {
//            projectiles[i].move(0.f, -10.f);
//
//            if (projectiles[i].getPosition().y <= 10)
//            {
//                projectiles.erase(projectiles.begin() + i);
//            }
//        }
//
//        //ENEMIES
//        if (enemySpawnTimer < 10)
//        {
//            enemySpawnTimer++;
//        }
//
//        if (enemySpawnTimer >= 10)
//        {
//            enemy.setPosition((rand() % int(window.getSize().x - enemy.getSize().x)), 0.f);
//
//            enemies.push_back(RectangleShape(enemy));
//
//            enemySpawnTimer = 0;
//        }
//
//        for (size_t i = 0; i < enemies.size(); i++)
//        {
//            enemies[i].move(0.f, 5.f);
//        }
//
//        //Collision
//        for (size_t i = 0; i < projectiles.size(); i++)
//        {
//            for (size_t k = 0; k < enemies.size(); k++)
//            {
//                if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()));
//            }
//        }
//
//        //DRAW
//        window.clear();
//
//        window.draw(player);
//
//        for (size_t i = 0; i < enemies.size(); i++)
//        {
//            window.draw(enemies[i]);
//        }
//
//        for (size_t i = 0; i < projectiles.size(); i++)
//        {
//            window.draw(projectiles[i]);
//        }
//
//        window.display();
//    }
//
//    return 0;
//}