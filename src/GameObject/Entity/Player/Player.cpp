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
}

void Player::moveX(int _dir){
    direction = _dir;
    if(moving){
        acc.set(_dir*0.5,acc.y);
    }
}

void Player::jump(){
    if(!action){
        vel.y=-15;
        action = true;
    }
}