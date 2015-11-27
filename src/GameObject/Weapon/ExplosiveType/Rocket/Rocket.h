//
//  Rocket.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#ifndef __UltraCrateBox__Rocket__
#define __UltraCrateBox__Rocket__

#include "../ExplosiveType.h"
#include <stdio.h>

class Rocket: public ExplosiveType{
public:
    Rocket();
    
    void fire(Entity &_entity);
};

#endif /* defined(__UltraCrateBox__Rocket__) */
