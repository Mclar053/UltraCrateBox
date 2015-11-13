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
    pos.set(100, 100);
    MAX_VEL.set(5, 20);
}

void Player::jump(){
    if(!action){
        vel.y=-MAX_VEL.y;
        action = true;
        hitFloor=false;
    }
}