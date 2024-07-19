#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Gameplay
{

	class GameplayView {
	
	private:
		UI::UIElement::ImageView* gameplay_image;

		void createUIElements();
		void initializeImage();
		sf::String getGameplayTexturePath();

		void destroy();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();

	};
}
