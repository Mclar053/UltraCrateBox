//
//  Weapon.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#include "Weapon.h"
Weapon::Weapon(){}


Weapon::Weapon(string _name, char _type, int _damage, int _reload, bool _holdFire):reloadTime(_reload),weaponType(_type),firing(false),fired(false),canFire(true),counter(2),holdFire(_holdFire){
    gameSprite = Sprite("sprites/weapons/"+_name+"/");
    damage = _damage;
    pos = ofVec2f(5,0);
}

void Weapon::checkBullets(){
    for (int i=0; i<ammo.size(); i++){
        ammo[i].move();
        if(ammo[i].checkWall()){
            ammo.erase(ammo.begin()+i, ammo.begin()+i+1);
        }
    }
}

void Weapon::fireWeapon(Entity &_entity){
    if(firing){
        if (canFire) {
            fire(_entity);
            canFire=false;
        }
    }
    if(!canFire){
        counter--;
        checkRecharge();
    }
}

void Weapon::checkRecharge()//Checks if the weapon can be fired again
{
    if(reloadTime-counter==reloadTime)
    {
        canFire=true;
        counter=reloadTime;
    }
}

void Weapon::checkHoldFire(Entity &_entity)//Checks if the weapon is a weapon which can be held down to fire
{
    if(!holdFire)
    {
        if(!fired)
        {
            fire(_entity);
            fired=true;
        }
    }
    else
    {
        firing=true;
    }
}

void Weapon::resetWeapon()//Resets the weapon so that it is not firing
{
    firing=false;
    fired=false;
}

void Weapon::fire(Entity &_entity){
    ammo.push_back(Projectile(_entity.pos,_entity.direction, checkWeaponType(),damage));
}

string Weapon::checkWeaponType(){
    switch (weaponType) {
        case 'b':
            return "bullet";
            break;
        case 'e':
            return "explosive";
            break;
        case 'l':
            return "laser";
            break;
        default:
            return "bullet";
            break;
    }
}