#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Elements/ElementService.h"
#include "../../header/Sound/SoundService.h"
#include "../../Header/Bullet/BulletService.h"

namespace Global
{


    class ServiceLocator
    {
    private:
        // Private Attributes:
        Graphic::GraphicService* graphic_service;

        UI::UIService* ui_service;

        Event::EventService* event_service;

        Player::PlayerService* player_service;

        Time::TimeService* time_service;

        Enemy::EnemyService* enemy_service;

        Gameplay::GameplayService* gameplay_service;

        Element::ElementService* element_service;

        Sound::SoundService* sound_service;

        Bullet::BulletService* bullet_service;

        // Private Constructor and Destructor:
        ServiceLocator();
        // Constructor for initializing the ServiceLocator.
        ~ServiceLocator(); 	// Destructor for cleaning up resources upon object deletion.

        // Private Methods:
        void createServices(); 			// Creates instances of all services.
        void clearAllServices(); 		//	Deletes and deallocates memory for all services.

    public:
        // Public Methods:
        static ServiceLocator* getInstance(); 			// Provides a method to access the unique ServiceLocator instance (object).
        void initialize(); 			//	Initializes the ServiceLocator.
        void update(); 				//	Updates all services.
        void render(); 				//	Renders using the services.(
        void deleteServiceLocator();

        // Methods to Get Specific Services: 
        Graphic::GraphicService* getGraphicService();
        UI::UIService* getUIService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
        Enemy::EnemyService* getEnemyService();
        Gameplay::GameplayService* getGameplayService();
        Element::ElementService* getElementService();
        Bullet::BulletService* getBulletService();
        Sound::SoundService* getSoundService();

    };
}