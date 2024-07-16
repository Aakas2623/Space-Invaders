#pragma once
#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	

		class UIService
		{

		private:

			MainMenu::MainMenuUIController* main_menu_controller;

			Interface::IUIController* getCurrentUIController();

			void createControllers();
			void initializeControllers();
			void destroy();

		public:

			UIService();
			~UIService();

			void initialize();
			void update();
			void render();
			void showScreen();

		};
	
}