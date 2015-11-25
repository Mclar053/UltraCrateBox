//
//  Shotgun.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#ifndef __UltraCrateBox__Shotgun__
#define __UltraCrateBox__Shotgun__

#include "../BulletType.h"
#include <stdio.h>

class Shotgun: public BulletType{
public:
    Shotgun(string _name, char _type, int _damage, int _reload, bool _holdFire);
    
    void fire(Entity &_entity);
};

#endif /* defined(__UltraCrateBox__Shotgun__) */
