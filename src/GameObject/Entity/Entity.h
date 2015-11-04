//
//  Entity.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Entity__
#define __UltraCrateBox__Entity__

#include "../GameObject.h"
#include <stdio.h>

class Entity: public GameObject{
public:
    Entity();
    
    void display();
    void applyGravity();
    void friction();
    void move();
    void stopMoveX();
    
    
    ofVec2f vel; //Velocity
    ofVec2f acc; //Acceleration
    bool action; //Whether the entity has performed it's action e.g. Jumping etc.
    bool hitFloor;
    int direction; //Direction the entity is facing
    float gravity; //The constant acceleration of gravity
};

#endif /* defined(__UltraCrateBox__Entity__) */
