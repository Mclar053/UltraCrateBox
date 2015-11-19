//
//  Weapon.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#ifndef __UltraCrateBox__Weapon__
#define __UltraCrateBox__Weapon__

#include "../GameObject.h"
#include "../Entity/Projectile/Bullet/Bullet.h"
#include <stdio.h>

//This is a placeholder. Will work on later

//Weapons will emit projectiles when used.
//Base class for all types of weapons. E.g. Pistol, Sword, Laser Rifle etc...

//Weapons inherits from GameObject
class Weapon: public GameObject{
public:
    /*Constructors*/
    Weapon();
    
    /*Methods*/
    void checkBullets();
    void fire(Entity &_entity);
    
    /*Properties*/
    vector<Projectile> ammo;
    int reloadTime;
    float range;
    int damage;
    bool holdFire;
};

#endif /* defined(__UltraCrateBox__Weapon__) */
