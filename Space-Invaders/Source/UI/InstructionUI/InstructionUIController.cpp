#include "../../Header/UI/InstructionUI/InstructionUIController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Event/EventService.h"
#include "../../header/Graphics/GraphicService.h"

namespace UI
{
	namespace InstructionUI
	{
		using namespace Main;
		using namespace Sound;
		using namespace Global;
		using namespace UI::UIElement;

		InstructionUIController::InstructionUIController() 
		{ 
			createUIElements();

			createMenuButton();
		}

		InstructionUIController::~InstructionUIController() 
		{
			destroy();
		}

		void InstructionUIController::initialize()
		{
			initializeText();
			initializeMenuButton();
			registerButtonCallback();
		}

		void InstructionUIController::createUIElements()
		{
			instuctions_text = new TextView();
		}

		void InstructionUIController::initializeText()
		{
			sf::String instuctions = "A or left arrow to move left\n"
									 "D or right arrow to move right\n"	
									 "Mouse left click to shoot";

			instuctions_text->initialize(instuctions, sf::Vector2f(instructions_x_position, instructions_y_position), FontType::BUBBLE_BOBBLE, font_size, instruction_color);
		}

		void InstructionUIController::createMenuButton()
		{
			menu_button = new ButtonView();
		}

		void InstructionUIController::initializeMenuButton()
		{
			menu_button->initialize("Back Button", Config::menu_button_texture_path, menu_button_width, menu_button_height, sf::Vector2f(0, menu_button_top_offset));
			menu_button->setCentreAlinged();
		}

		void InstructionUIController::registerButtonCallback()
		{
			menu_button->registerCallbackFuntion(std::bind(&InstructionUIController::menuButtonCallback, this));
		}

		void InstructionUIController::menuButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void InstructionUIController::update() 
		{
			menu_button->update();
		}

		void InstructionUIController::render()
		{
			instuctions_text->render();
			menu_button->render();
		}

		void InstructionUIController::show() 
		{
			menu_button->show();
		}

		void InstructionUIController::destroy()
		{
			delete(instuctions_text);
			delete(menu_button);
		}
	}
}