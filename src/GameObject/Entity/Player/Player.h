//
//  Player.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Player__
#define __UltraCrateBox__Player__

#include "../Entity.h"
#include <stdio.h>

class Player: public Entity{
public:
    //Constructors
    Player();
    
    //Methods
    void moveX(int _dir);
    
    //Properties
    bool right;
};

#endif /* defined(__UltraCrateBox__Player__) */
