//
//  ChargeRocket.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 02/12/2015.
//
//

#ifndef __UltraCrateBox__ChargeRocket__
#define __UltraCrateBox__ChargeRocket__

#include "../ExplosiveType.h"
#include <stdio.h>

class ChargeRocket: public ExplosiveType{
public:
    ChargeRocket();
    
    void fire(Entity &_entity);
};

#endif /* defined(__UltraCrateBox__ChargeRocket__) */
