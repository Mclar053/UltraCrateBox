//
//  Player.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Player.h"

Player::Player(){
    gameSprite = Sprite(5, 1, 7, "/Users/MatthewClark/Documents/University/Goldsmiths/Year1/Intro to Prog/New/Mini Project/aFinalGame/data/player");
    pos.set(100, 100);
}

void Player::moveX(int _dir){
    pos+=ofVec2f(_dir*3,0);
}