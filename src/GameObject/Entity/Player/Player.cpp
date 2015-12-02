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
//    weapons.push_back(new Pistol());
//    weapons.push_back(new Shotgun());
//    weapons.push_back(new Rocket());
//    weapons.push_back(new MachineGun());
    weapons.push_back(new ChargeRocket());
//    weapons.push_back(new Weapon("pistol",'b',5,-1,false));
//    weapons.push_back(new Weapon("pistol",'b',2,3,true));
}

void Player::display(){
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    if(weapons[currentWeapon]->holdFire){
        ofPushStyle();
            ofSetColor(255, 0, 0);
            ofFill();
            ofDrawRectangle(-25, -size.y/2-10, 50, 5);
            
            ofSetColor(0, 255, 0);
            ofFill();
            ofDrawRectangle(-25, -size.y/2-10, float(weapons[currentWeapon]->counter)/weapons[currentWeapon]->reloadTime*50, 5);
        ofPopStyle();
    }
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