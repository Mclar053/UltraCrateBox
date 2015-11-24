//
//  Player.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Player.h"

Player::Player(){}

Player::Player(ofVec2f _pos):Entity(_pos),currentWeapon(0){
    gameSprite = Sprite(5, 1, 6, 0, "sprites/entities/player/");
    getSize();
    moving = false;
    MAX_VEL.set(5, 10);
    weapons.push_back(new Pistol("pistol",'b',1,-1
                             ,false));
    weapons.push_back(new Weapon("rocket",'e',30,60,true));
    weapons.push_back(new Weapon("pistol",'b',5,-1,false));
    weapons.push_back(new Weapon("pistol",'b',2,3,true));
}

void Player::display(){
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    glScalef(direction, 1, 1);
    gameSprite.display();
    weapons[currentWeapon]->display();
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