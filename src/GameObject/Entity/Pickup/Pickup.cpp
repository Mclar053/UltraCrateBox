//
//  Pickup.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Pickup.h"

Pickup::Pickup(){
    gameSprite = Sprite(0, 0, 0, 0, "sprites/misc/");
    getSize();
    pos.set(ofVec2f(rand()%ofGetWidth(),rand()%ofGetHeight()));
    moving=true;
    MAX_VEL.set(0, 0);
}