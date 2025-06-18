#include "game/game.h"

void settings(){
    
}


void playGame() {
    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800,600), "window", sf::Style::Default, setting);

    bool canShoot = true;

    Player player("assets/player/textures/spritesheet.png", 0,0);
    Player enemy("assets/player/textures/spritesheet.png", 4,2);
    enemy.getSprite().setPosition(sf::Vector2f(100,100));

    std::vector<std::unique_ptr<Bullet>> bullets;

    // -------------------------------- LOAD -------------------------------- //

    // MAIN GAME LOOP
    while (window.isOpen()){
        // -------------------------------- UPDATE -------------------------------- //
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            { window.close();}


            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
                canShoot = true;
            }
        }

        player.handleMovement();
        handleShooting(player, enemy, bullets, canShoot);
        updateBullets(bullets);


        // -------------------------------- UPDATE -------------------------------- //

        window.clear(sf::Color::Black);
        player.draw(window);
        enemy.draw(window);
        for(auto& bullet : bullets){
            bullet->bulletMove();
            window.draw(bullet->bull);
        }
        window.display();
    }
}

void handleShooting(Player& player, Player& enemy, 
                    std::vector<std::unique_ptr<Bullet>>& bullets, 
                    bool& canShoot) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot) {
        auto newBullet = std::make_unique<Bullet>();
        newBullet->setInitPosition(player.getSprite().getPosition());
        newBullet->setDirection(enemy.getSprite().getPosition());

        bullets.push_back(std::move(newBullet));
        canShoot = false;
    }
}

void updateBullets(std::vector<std::unique_ptr<Bullet>>& bullets) {
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
            [](const std::unique_ptr<Bullet>& b) {
                sf::Vector2f pos = b->bull.getPosition();
                return pos.x < 0 || pos.x > 800 || pos.y < 0 || pos.y > 600;
            }),
        bullets.end()
    );

    for (auto& bullet : bullets) {
        bullet->bulletMove();
    }
}
