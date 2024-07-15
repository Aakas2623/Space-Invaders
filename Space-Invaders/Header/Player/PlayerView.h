#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Player/PlayerController.h"



class PlayerView
{
private:
	
	PlayerController* player_controller; // ptr to player controller

	//player texture path
	const sf::String player_texture_path = "assets/textures/player_ship.png";

	//player sprite and texture
	sf::Texture player_texture;
	sf::Sprite player_sprite;


	//player sprite attribute(height & Width)(60, 60)
	const int player_sprite_width = 60;
	const int player_sprite_height = 60;


	//ptr to game window for rendering our player
	sf::RenderWindow* game_window;


	//initializePlayerSprite()
	void initializePlayerSprite();


	//scaleSprite()
	void scalePlayerSprite();

public:
	
		//constructor Destructor
	PlayerView();
	~PlayerView();


		//initialise, update, render	

	void initialize(PlayerController* controller); // we pass a pointer of type controller because we need to use this in the view later.
	void update();
	void render();


};
