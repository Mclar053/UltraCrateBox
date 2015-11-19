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
    weapons.push_back(Pistol());
}

Player::Player(ofVec2f _pos):Entity(_pos){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/player/");
    getSize();
    MAX_VEL.set(5, 10);
    weapons.push_back(Pistol());
}

void Player::display(){
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    glScalef(direction, 1, 1);
    gameSprite.display();
    weapons[0].display();
    if(!action && moving){
        gameSprite.moveNextFrame();
    }
    else if(!action && !moving){
        gameSprite.currentFrame = gameSprite.stationaryFrame;
    }
    else{
        gameSprite.currentFrame = gameSprite.actionFrame;
    }
    glPopMatrix();
}

void Player::jump(){
    if(!action){
        vel.y=-MAX_VEL.y;
        action = true;
    }
}