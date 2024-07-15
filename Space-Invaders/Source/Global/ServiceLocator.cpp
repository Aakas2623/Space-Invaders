#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global
{
	using namespace Graphic;
	using namespace Time;
	using namespace Player;
	using namespace Event;
	using namespace UI;
	using namespace Main;
	using namespace Enemy;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;

	// Constructor: Initializes the graphic_service pointer to null and creates services.
	ServiceLocator::ServiceLocator() 
	{
		graphic_service = nullptr; // Initialize graphic_service to null
		time_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;
		sound_service = nullptr;
		bullet_service = nullptr;
		powerup_service = nullptr;

		createServices(); // Call createServices to instantiate services
	}

	// Destructor: Cleans up resources by clearing all services.
	ServiceLocator::~ServiceLocator() {
		clearAllServices(); // Call clearAllServices to delete any allocated services	
	}

	// Creates service instances, specifically the graphic service in this case.
	void ServiceLocator::createServices() {
		graphic_service = new GraphicService(); // Dynamically create a GraphicService instance
		ui_service = new UIService();
		time_service = new TimeService();
		event_service = new EventService();
		player_service = new PlayerService();
		enemy_service = new EnemyService();
		gameplay_service = new GameplayService();
		element_service = new ElementService();
		bullet_service = new BulletService();
		sound_service = new SoundService();
		powerup_service = new PowerupService();
	}

	// Deletes allocated services to prevent memory leaks, specifically the graphic service.
	void ServiceLocator::clearAllServices() {
		delete(graphic_service); // Delete the graphic_service instance
		delete(ui_service);
		delete(time_service);
		delete(event_service);
		delete(player_service);
		delete(enemy_service);
		delete(gameplay_service);
		delete(element_service);
		delete(bullet_service);
		delete(sound_service);
		delete(powerup_service);

		graphic_service = nullptr; // Reset pointer to null to avoid dangling pointer
	}

	// Returns a pointer to ServiceLocator.
	ServiceLocator* ServiceLocator::getInstance() {
		static ServiceLocator instance; // we will discuss what 'static' means at a later time.
		return &instance; // Return address of the instance
	}

	// Calls initialize on the graphic service, readying it for use.
	void ServiceLocator::initialize() {
		graphic_service->initialize(); // Initialize graphic service
		ui_service->initialize();
		time_service->initialize();
		event_service->initialize();
		player_service->initialize();
		enemy_service->initialize();
		gameplay_service->initialize();
		element_service->initialize();
		bullet_service->initialize();
		sound_service->initialize();
		powerup_service->initialize();
	}

	// Updates the state of the graphic service.
	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();

		//Only update if the game state is correct
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			player_service->update();
			enemy_service->update();
			bullet_service->update();
			element_service->update();
			powerup_service->update();
		}

		ui_service->update();

	}

	// Renders using the graphic service.
	void ServiceLocator::render()
	{
		graphic_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			bullet_service->render();
			element_service->render();
			powerup_service->render();
		}
		
		ui_service->render();
		
	}

	// Returns a pointer to the currently set graphic service.
	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
	UIService* ServiceLocator::getUIService() { return ui_service; }
	EventService* ServiceLocator::getEventService() { return event_service; }
	PlayerService* ServiceLocator::getPlayerService() { return player_service; }
	TimeService* ServiceLocator::getTimeService() { return time_service; }
	EnemyService* ServiceLocator::getEnemyService() { return enemy_service; }
	GameplayService* ServiceLocator::getGameplayService() { return gameplay_service; }
	ElementService* ServiceLocator::getElementService() { return element_service; }
	BulletService* ServiceLocator::getBulletService() { return bullet_service; }
	SoundService* ServiceLocator::getSoundService() { return sound_service; }
	PowerupService* ServiceLocator::getPowerupService() { return powerup_service; }

	void ServiceLocator::deleteServiceLocator()
	{
		delete(this);
	}

}





