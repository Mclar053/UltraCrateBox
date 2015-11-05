//
//  Player.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Player.h"

Player::Player(){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/player/");
    pos.set(100, 100);
    MAX_VEL.set(5, 10);
}

void Player::jump(){
    if(!action){
        vel.y=-MAX_VEL.y;
        action = true;
    }
}