#include "Player.h"

Player::Player() {
   pos_ = {0.0f, 0.0f};
   speed_ = 5.0f;
}

void Player::MoveRight() {
   pos_.x += speed_;
}

void Player::MoveLeft() {
   pos_.x -= speed_;
}
