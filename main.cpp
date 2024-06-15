#include "../Space-Invaders/Header/Main/GameService.h"

int main() {

    using namespace Main;

    GameService gameService;

    gameService.ignite();

    while (gameService.isRunning())
    {

        gameService.update();
        gameService.render();

    }

}





/*

#include <iostream>

#include <sfml/graphics.hpp>

class player {

private:

     private properties
    int health = 3;
    sf::vector2f position = sf::vector2f(200.0f, 100.0f);
    int movement_speed = 1;
    int player_score = 0;

public:

     public properties
    sf::texture player_texture;
    sf::sprite player_sprite;

    public getter & setter methods
    int getscore() {
        return player_score;
    }

    void setscore(int newscore) {
        player_score = newscore;
    }

    sf::vector2f getposition() {
        return position;
    }


    void takedamage() {};
    void move(float offsetx) {
        position.x += offsetx;
        
    };

    
    
    int getmovespeed() {
        return movement_speed;
    }

    void shootbullets() {};

};

int main() {

    sf::videomode videomode = sf::videomode(800, 600); // define the video mode (dimensions)

    sf::renderwindow window(videomode, "sfml window");  // create a window object

    player player;  // create the player object


    while (window.isopen()) {
        sf::event event;
        while (window.pollevent(event)) {
             check for window closure
            if (event.type == sf::event::closed)
                window.close();
        }

           handle keyboard input
        if (sf::keyboard::iskeypressed(sf::keyboard::left)) {
            player.move(-1.0f * player.getmovespeed());
        }
        if (sf::keyboard::iskeypressed(sf::keyboard::right)) {
            player.move(1.0f * player.getmovespeed());
        }
        


        player.player_texture.loadfromfile("assets/textures/player_ship.png"); // load the player ship texture

        player.player_sprite.settexture(player.player_texture);  // set the player sprite variable 

         clear the window
        window.clear(sf::color::blue); // this code will set a blue background color (optional)

        player.player_sprite.setposition(player.getposition()); // set the position of the player sprite

        window.draw(player.player_sprite);    // draw the player sprite

        window.display(); // display what was drawn

    } // end while loop

    return 0;
}

*/