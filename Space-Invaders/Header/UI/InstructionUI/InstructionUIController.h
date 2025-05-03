#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
	namespace InstructionUI
	{
		class InstructionUIController : public Interface::IUIController 
		{
		private:
			const float menu_button_top_offset = 950.f;

			const float menu_button_width = 400.f;
			const float menu_button_height = 140.f;

			const float font_size = 40.f;

			const float instructions_y_position = 400.f;
			const float instructions_x_position = 700.f;

			const sf::Color instruction_color = sf::Color::White;

			UIElement::ButtonView* menu_button;
			UIElement::TextView* instuctions_text;

			void createUIElements();
			void initializeText();
			void createMenuButton();
			void initializeMenuButton();


			void registerButtonCallback();
			
			void menuButtonCallback();

			void destroy();

		public:
			InstructionUIController();
			~InstructionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}
