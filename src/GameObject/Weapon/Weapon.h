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
//#include "../Entity/Projectile/Explosive/Explosive.h"
//#include "../Entity/Projectile/Bullet/Bullet.h"
//#include "../Entity/Projectile/Bullet/Bullet.h"
#include <stdio.h>

//Weapons will emit projectiles when used.

//Weapons inherits from GameObject
class Weapon: public GameObject{
public:
    /*Constructors*/
    Weapon();
    Weapon(string _name, char _type, int _damage, int _reload, bool _holdFire);
    
    /*Methods*/
    void checkBullets();
    string checkWeaponType();
    
    //Firing controls
    void fireWeapon(Entity &_entity);
    virtual void fire(Entity &_entity);
    void checkHoldFire(Entity &_entity);
    void checkRecharge();
    void resetWeapon();
    
    /*Properties*/
    vector<Projectile*> ammo;
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
