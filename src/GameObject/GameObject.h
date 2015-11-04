//
//  GameObject.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__GameObject__
#define __UltraCrateBox__GameObject__

#include "../ofMain.h"
#include <stdio.h>

class GameObject{
    
public:
    GameObject();
    ofVec2f pos;
    int x;
    void display();
    
};

#endif /* defined(__UltraCrateBox__GameObject__) */
