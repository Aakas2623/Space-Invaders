#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace Gameplay
{
	using namespace Global;
	using namespace UI::UIElement;

	GameplayView::GameplayView() { }

	GameplayView::~GameplayView() { }

	void GameplayView::initialize()
	{
		initializeImage();
	}

	void GameplayView::createUIElements()
	{
		gameplay_image = new ImageView();
	}

	void GameplayView::initializeImage()
	{
		gameplay_image->initialize(getGameplayTexturePath(), gameplay_controller);
	}

	sf::String GameplayView::getGameplayTexturePath()
	{
		return Config::background_texture_path;
	}

	void GameplayView::update() 
	{
		gameplay_image->update();
	}

	void GameplayView::render() 
	{ 
		gameplay_image->render();
	}

	void GameplayView::destroy()
	{
		delete(gameplay_image);
	}
}