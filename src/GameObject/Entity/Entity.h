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
//#include "../Weapon/Pistol/Pistol.h"
#include <stdio.h>

//Entity inherits GameObject
class Entity: public GameObject{
public:
    /*Constructors*/
    Entity();
    Entity(ofVec2f _pos);
    
    /*Methods*/
    void display();
    
    //Physics
    void applyGravity();
    void friction();
    void move();
    void speedControl();
    void moveX(int _dir);
    void yControl();
    void stopMoveX();
    
    //Collisions
    void checkCollision();
    
    //Features
    void wallWrap();
    bool checkWall();
    
    /*Properties*/
    ofVec2f MAX_VEL; //Maximum Velocity
    ofVec2f vel; //Velocity
    ofVec2f acc; //Acceleration
    bool action; //Whether the entity has performed it's action e.g. Jumping etc.
    bool onPlatform; //Checks if entity is on a platform
    bool moving;
    int direction; //Direction the entity is facing
    float gravity; //The constant acceleration of gravity
};

#endif /* defined(__UltraCrateBox__Entity__) */
