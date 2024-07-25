#pragma once
#include <SFML/Graphics.hpp>


namespace Player
{
    enum class PlayerState;
    enum class Entity;

    class PlayerView;
    class PlayerModel;

    class PlayerController
    {
    private:
        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();
        void fireBullet();

    public:
        PlayerController(EntityType owner_type);
        ~PlayerController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getPlayerPosition();
        PlayerState getPlayerState();
        EntityType getOwnerEntityType();
        
    };

}
