//
//  Weapon.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#include "Weapon.h"
Weapon::Weapon(){}


Weapon::Weapon(string _name, int _damage, int _reload, bool _holdFire):reloadTime(_reload),firing(false),fired(false),canFire(true),counter(0),holdFire(_holdFire){
    damage = _damage;
    name = _name;
    pos = ofVec2f(5,0);
}

void Weapon::checkBullets(){
    
    
    for (int i=0; i<ammo.size(); i++){
        ammo[i].move();
        if(ammo[i].checkWall()){
//            delete ammo[i];
            ammo.erase(ammo.begin()+i);
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
    if(reloadTime-counter>=reloadTime)
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
    cout<<"pew"<<endl;
//    ammo.push_back(new Projectile(_entity.pos,_entity.direction, checkWeaponType(),damage));
}