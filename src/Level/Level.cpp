//
//  Level.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 15/11/2015.
//
//

#include "Level.h"

Level::Level(){
    //Sets size of level
    layout.resize(46);
    for (auto &i: layout){
        i.resize(33);
    }
    
    for (int i=0; i<layout.size(); i++) {
        for (int j=0; j<layout[i].size(); j++) {
            if (j%3==0) {
                 layout[i][j]=1;
            }
        }
    }
}
   //Level dimensions = [33][46] at platform size = 20px
    /*
     0=air
     1=platform
     2=fire
     3=enemy Spawner
     4=Player spawn
    */

//void Level::loadLevel(){
//    ifstream fin; //declare a file stream
//    fin.open( ofToDataPath("../levelFile/level.txt").c_str() ); //open your text file
//    
//    vector<string> data; //declare a vector of strings to store data
//    
//    while(fin!=NULL) //as long as theres still text to be read
//    {
//        string str; //declare a string for storage
//        getline(fin, str); //get a line from the file, put it in the string
//        data.push_back(str); //push the string onto a vector of strings
//    }
//}

