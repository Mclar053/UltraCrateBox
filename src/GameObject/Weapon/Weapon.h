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
#include "../Entity/Projectile/Explosive/Explosive.h"
#include <stdio.h>

//Weapons will emit projectiles when used.

//Weapons inherits from GameObject
class Weapon: public GameObject{
public:
    /*Constructors*/
    Weapon();
    Weapon(string _name, int _damage, int _reload, bool _holdFire);
    
    /*Methods*/
    void checkBullets();
    string checkWeaponType();
    
    //Firing controls
    void fireWeapon(Entity &_entity); //Fires projectiles from weapon
    virtual void fire(Entity &_entity); //Virtual functions so child classes can overload due to each weapon having different behaviours
    void checkHoldFire(Entity &_entity); //Checks if weapon has reload time
    void checkRecharge();
    void resetWeapon();
    
    /*Properties*/
    vector<Projectile> ammo;
    int reloadTime;
    float range;
    int damage;
    bool holdFire;
    char weaponType;
    string name;
    
    //Firing controls
    bool firing;
    bool fired;
    bool canFire;
    int counter;
};

#endif /* defined(__UltraCrateBox__Weapon__) */
