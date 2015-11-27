//
//  ExplosiveType.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#ifndef __UltraCrateBox__ExplosiveType__
#define __UltraCrateBox__ExplosiveType__

#include "../Weapon.h"
#include <stdio.h>

class ExplosiveType:public Weapon{
public:
    ExplosiveType(string _name, int _damage, int _reload, bool _holdFire);
    
    void fire(Entity &_entity);
};

#endif /* defined(__UltraCrateBox__ExplosiveType__) */
