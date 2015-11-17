#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    text.loadFont(OF_TTF_SANS,20); //Loads font to text variable
    
    //Creates platforms as example and to test
    for(int i=0; i<53;i++){
        platforms.push_back(Platform(ofVec2f(i*20, 500)));
    }
    for(int i=0; i<20;i++){
        platforms.push_back(Platform(ofVec2f(i*20, 440)));
//        platforms.push_back(Platform(ofVec2f(i*100, 440)));
        platforms.push_back(Platform(ofVec2f(i*80, 110)));
    }
//    Level level;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Player controls
    if(player.moving){
        if(player.right){
            player.moveX(1);
        }
        else{
            player.moveX(-1);
        }
    }
    else{
        player.friction();
    }
    
    if(up){
        player.jump();
    }
    
    //Tile collision routine
    ene.onPlatform=false;//Sets entities 'onPlatform' bool to false
    player.onPlatform=false;
    //For each platform checks if the player is colliding with an entity and changes the onPlatform to true accordingly
    for(auto &_platform: platforms){
        checkCollisions(_platform,&player);
        checkCollisions(_platform,&ene);
    }
    
    //Entity Movement
    ene.moveX(1); //Sets enemy speed to 1 to the right
    ene.move(); //Actually moves the enemy position and does all physics checks
    player.move(); //Same as previous comment but with player
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Displays all platforms, player and enemy
    for(auto &_platform: platforms){
        _platform.display();
    }
    player.display();
    ene.display();
    
    text.drawString("VelX:"+to_string(player.vel.x) +"\nVelY:"+ to_string(player.vel.y) +"\nAccX:"+ to_string(player.acc.x)+"\nPosX:"+ to_string(player.pos.x)+"\nPosY:"+ to_string(player.pos.y),100,100);
    
    text.drawString("VelX:"+to_string(ene.vel.x) +"\nVelY:"+ to_string(ene.vel.y) +"\nAccX:"+ to_string(ene.acc.x)+"\nPosX:"+ to_string(ene.pos.x)+"\nPosY:"+ to_string(ene.pos.y),400,100);
    
    text.drawString("SizeX:"+to_string(player.size.x) +"\nSizeY:"+to_string(player.size.y),700,100);
    
    text.drawString("SizeX:"+to_string(platforms[0].size.x) +"\nSizeY:"+to_string(platforms[0].size.y)+"\nPosX:"+to_string(platforms[0].pos.x)+"\nPosY:"+to_string(platforms[0].pos.y),100,300);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT){
        player.right = true;
        player.moving = true;
    }
    else if(key == OF_KEY_LEFT){
        player.right = false;
        player.moving = true;
    }
    if(key == OF_KEY_UP || key == 'z'){
        up = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_UP || key == 'z'){
        up = false;
    }
    if(key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
        player.moving = false;
    }
}


void ofApp::checkCollisions(Tile _platform, Entity *_entity){
    //Checks if entity is jumping into a tile from below
    if(_platform.detectBottom(_entity)){
        _entity->pos.y=_platform.pos.y+_platform.size.y/2+_entity->size.y/2; //Changes position of entity so it is below the tile and cannot clip through
        _entity->vel.y=0;
        _entity->acc.y=0;
    }
    
    //Detects the top of the tile
    else if(_platform.detectTop(_entity)){
        _entity->action = false; //Entities can now jump
        _entity->vel.y=0; //Velocity set to 0, prevent clipping
        _entity->acc.y=0; //Acceleration set to 0, prevent clipping
        _entity->pos.y=_platform.pos.y-_platform.size.y/2-_entity->size.y/2;
        //Changes position of entity to above the top of the tile so the entity is in a 'buffer zone' meaning that the entity is not falling due to gravity but can still run and jump
    }

    //Detect if left of tile is colliding with the entity
    else if(_platform.detectLeft(_entity)){
        _entity->pos.x=_platform.pos.x-_platform.size.x/2-_entity->size.x/2; //Changes position of entity to side of tile thus not making the entity clip through the tile
    }
    
    //Same but with the right of the tile
    else if(_platform.detectRight(_entity)){
        _entity->pos.x=_platform.pos.x+_platform.size.x/2+_entity->size.x/2; //Changes position of entity to side of tile thus not making the entity clip through the tile
    }

    
    //Checks if entity is in buffer zone and stops entity from falling through tile
    if(_platform.detectAboveTop(_entity)){
        if(_entity->vel.y>0){ //If entity is falling downward
            _entity->vel.y=0; //velocity stops to prevent clipping
        }
        _entity->onPlatform=true;
        _entity->action = false; //Entity can jump
    }
}

void ofApp::createLevel(){
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
