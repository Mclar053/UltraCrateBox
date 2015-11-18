//
//  Player.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Player.h"

Player::Player(){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/player/");
    getSize();
    MAX_VEL.set(5, 10);
}

Player::Player(ofVec2f _pos):Entity(_pos){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/player/");
    getSize();
    MAX_VEL.set(5, 10);
}

void Player::jump(){
    if(!action){
        vel.y=-MAX_VEL.y;
        action = true;
    }
}