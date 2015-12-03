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
}

void Level::loadLevel(string level){
    ifstream file;
    string sub, textLine;
    int xCount;
    int yCount;
    xCount = 0;
    yCount = 0;
    
    file.open (ofToDataPath("levels/"+level)); //Open text file
    while(!file.eof()) // To get all the line
    {
        getline(file,textLine); // Saves the line in textLine
        sub = ""; //Sets the substring to ""
        
        for(int i=0; i<textLine.length(); i++){ //For each character in the textLine string
            if(textLine.at(i)==','){//Check if the character is a comma
                sub = "";//Text sub to ""
            }
            else{ //If any other character
                sub+=textLine.at(i); //Add the character to sub
                layout[xCount][yCount]=(stoi(sub)); //Convert sub into an integer and add to layout at position xCount, yCount
                xCount++; //Move to next position
            }
        }
        //Once the line has ended
        yCount++;//Move down one positon in layout
        xCount=0; //Set xCount to 0
    }
    file.close(); //Close file once complete with loading
}

