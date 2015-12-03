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
    
    //Adding weapons to weapon vector
    weapons.push_back(new Pistol());
    weapons.push_back(new Shotgun());
    weapons.push_back(new Rocket());
    weapons.push_back(new MachineGun());
    weapons.push_back(new ChargeRocket());
}

void Player::display(){
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    
    /*
     Weapon reload bar
     -Checks if players weapon has a reload
     -Colours one rectangle as red
     -Other green rectangle changes size depending on weapons reload timer
    */
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
    
    glScalef(direction, 1, 1); //Player faces correct direction
    gameSprite.display(); //Display gameSprite
    weapons[currentWeapon]->display(); //Display players current weapon
    
    //Move to next frame if the player is not jumping and is moving
    if(!action && moving){
        gameSprite.moveNextFrame();
    }
    else if(!action && !moving){ //Stationary if not jumping or moving
        gameSprite.currentFrame = gameSprite.stationaryFrame;
    }
    else{ //Jump frame if not of the above
        gameSprite.currentFrame = gameSprite.actionFrame;
    }
    glPopMatrix();
}

void Player::jump(){
    //If player hasn't already jumped, the player will jump
    if(!action){
        vel.y=-MAX_VEL.y;
        action = true;
    }
}