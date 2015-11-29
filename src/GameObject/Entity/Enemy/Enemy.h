//
//  Enemy.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Enemy__
#define __UltraCrateBox__Enemy__

#include "../Entity.h"
#include <stdio.h>

//Base for all enemies - enemy types will be created like Drone and Tank than Enemy
//Those types will inherit this one

//Enemy inherits from Entity
class Enemy: public Entity{
public:
    //Constructors
    Enemy();
    Enemy(ofVec2f _pos);
    
    //Methods
    void changeDirection();
    void checkAlive();
    void enrage();
    
    //Properties
    int health;
    bool dead;
    bool fallen; //Checks if enemy has fallen in fire
    string type;
};

#endif /* defined(__UltraCrateBox__Enemy__) */
