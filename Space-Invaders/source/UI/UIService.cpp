#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace SplashScreen;

	UIService::UIService()
	{
		splash_screen_controller = nullptr;
		main_menu_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		splash_screen_controller = new SplashScreenUIController();
		main_menu_controller = new MainMenuUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			splash_screen_controller->update();
			break;

		case GameState::MAIN_MENU:
			return main_menu_controller->update();;
			break;
		}
	}

	void UIService::render()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			splash_screen_controller->render();
			break;

		case GameState::MAIN_MENU:
			return main_menu_controller->render();;
			break;
		}
	}

	void UIService::showScreen()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			splash_screen_controller->show();
			break;

		case GameState::MAIN_MENU:
			return main_menu_controller->show();;
			break;
		}
	}

	void UIService::initializeControllers()
	{
		splash_screen_controller->initialize();
		main_menu_controller->initialize();
	}

	void UIService::destroy()
	{
		delete(splash_screen_controller);
		delete(main_menu_controller);
	}
}