#include "Player.h"
#include <Novice.h>

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

void Player::Update() {
   // プレイヤーの更新処理はとくになし
}

void Player::Draw() {
   Novice::DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), 50, 50, 0.0f, WHITE, kFillModeSolid);
}