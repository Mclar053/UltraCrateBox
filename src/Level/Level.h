//
//  Level.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 15/11/2015.
//
//

#ifndef __UltraCrateBox__Level__
#define __UltraCrateBox__Level__

#include "../ofMain.h"
#include <fstream>
#include <stdio.h>

class Level{
public:
    /*Constructors*/
    Level();
    
    /*Methods*/
    void loadLevel();
    void saveLevel();
    
    
    /*Properties*/
    vector<vector<int>> layout;
};

#endif /* defined(__UltraCrateBox__Level__) */
