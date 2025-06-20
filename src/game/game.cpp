#include "game/game.h"

sf::ContextSettings settings(){
    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;
    return setting;
}

void playGame() {
    sf::RenderWindow window(sf::VideoMode(800,600), "window", sf::Style::Default, settings());
    //window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    bool canShoot = true;

    Player player("assets/player/textures/spritesheet.png", 0,0);
    NPC enemy("assets/player/textures/spritesheet.png", 4,2);

    sf::Clock clock;
    sf::Time deltaTimeTimer;

    // MAIN GAME LOOP
    while (window.isOpen()){

        deltaTimeTimer = clock.restart();
        //std::cout << "Framerate: " << 1/deltaTimeTimer.asSeconds() << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();}

            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
                canShoot = true;}
        }

        player.handleMovement(deltaTimeTimer.asSeconds());
        player.handleShooting(enemy, canShoot, deltaTimeTimer.asSeconds());

        window.clear(sf::Color::Black);

        player.draw(window);
        player.getMag().draw(window);
        enemy.draw(window);

        window.display();
    }
}


