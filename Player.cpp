#include "Player.h"

Player::Player(string _PlayerName)
{
	PlayerName = _PlayerName;
}

Player::~Player()
{
}

void Player::addSubMarinetoplayer(SubMarine _SubMarineName) {
	PlayerSubMarines.push_back(_SubMarineName);
}
void Player::removeSubMarinefromplayer() {
	PlayerSubMarines.pop_back();
}
vector <SubMarine> Player::getPlayerSubMarine() {
	return PlayerSubMarines;

}

Player::Player()
{
}
