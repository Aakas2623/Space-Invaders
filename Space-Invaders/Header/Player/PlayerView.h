#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

class PlayerController;

class PlayerView
{
private:
	
	PlayerController* player_controller; // ptr to player controller

	//player sprite attribute(height & Width)(60, 60)
	const int player_sprite_width = 60;
	const int player_sprite_height = 60;

	UI::UIElement::ImageView* player_image;

	void createUIElements();
	void initializeImage();
	sf::String getPlayerTexturePath();

	void destroy();

public:
	
		//constructor Destructor
	PlayerView();
	~PlayerView();


		//initialise, update, render	

	void initialize(PlayerController* controller); // we pass a pointer of type controller because we need to use this in the view later.
	void update();
	void render();


};
