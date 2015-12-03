//
//  Button.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 30/11/2015.
//
//

#ifndef __UltraCrateBox__Button__
#define __UltraCrateBox__Button__

#include "../ofMain.h"
#include <stdio.h>

class Button{
public:
    Button(){};
    Button(ofVec2f _pos, ofVec2f _size, string _text);
    Button(ofVec2f _pos, ofVec2f _size, string _text, ofColor _col);
    
    //Displays the button
    void display(ofTrueTypeFont *_font);
    
    //Checks if the button has been clicked
    bool clicked(float _mouseX, float _mouseY);
    
    ofVec2f pos; //Position of button
    ofVec2f size; //Size of button
    string text; //Text for button
    ofColor colour; //Colour of the button
};

#endif /* defined(__UltraCrateBox__Button__) */
