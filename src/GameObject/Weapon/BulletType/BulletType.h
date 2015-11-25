//
//  BulletType.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#ifndef __UltraCrateBox__BulletType__
#define __UltraCrateBox__BulletType__

#include "../Weapon.h"
//#include "../../Entity/Projectile/Bullet/Bullet.h"
#include <stdio.h>

class BulletType:public Weapon{
public:
    BulletType(string _name, char _type, int _damage, int _reload, bool _holdFire);
    
//    void fire(Entity &_entity);
};

#endif /* defined(__UltraCrateBox__BulletType__) */
