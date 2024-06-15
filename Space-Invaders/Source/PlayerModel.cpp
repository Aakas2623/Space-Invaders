#include "../Header/PlayerModel.h"

PlayerModel::PlayerModel() { }

PlayerModel::~PlayerModel() { }

void PlayerModel::initialize() { reset(); }

void PlayerModel::reset()
{
	player_alive = true;
	player_position = initial_player_position;
}

sf::Vector2f PlayerModel::getPlayerPosition()
{
	return player_position;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position)
{
	player_position = position;
}

bool PlayerModel::getPlayerAlive()
{
	return player_alive;
}

void PlayerModel::setPlayerAlive(bool alive)
{
	player_alive = alive;
}