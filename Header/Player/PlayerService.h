#pragma once
#include "../../Header/Player/PlayerController.h"

namespace Player
{

	enum class PlayerState;
	//class PlayerController;

	class PlayerService
	{
	private:
		PlayerController* player_controller;

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();
	};
}