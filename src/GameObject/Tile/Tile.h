//
//  Tile.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#ifndef __UltraCrateBox__Tile__
#define __UltraCrateBox__Tile__

//Includes GameObject reference in Entity
#include "../Entity/Entity.h"
#include <stdio.h>

class Tile: public GameObject{
public:
    /*Constructors*/
    Tile();
    Tile(ofVec2f _pos);
    
    /*Methods*/
    bool detectLeft(Entity &_entity);
    bool detectRight(Entity &_entity);
    bool detectTop(Entity &_entity);
    bool detectBottom(Entity &_entity);
    
    /*Properties*/
    ofVec2f size;
    
};

#endif /* defined(__UltraCrateBox__Tile__) */
