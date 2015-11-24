//
//  Pistol.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#ifndef __UltraCrateBox__Pistol__
#define __UltraCrateBox__Pistol__

#include "../BulletType.h"
#include <stdio.h>

class Pistol: public BulletType{
public:
    Pistol(string _name, char _type, int _damage, int _reload, bool _holdFire);
};

#endif /* defined(__UltraCrateBox__Pistol__) */
