#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    text.loadFont(OF_TTF_SANS,10); //Loads font to text variable
    player = Player(ofVec2f(100,300));
    
    //Creates level from Level object
    createLevel();
    posOffset.set(52,44);
    state = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    switch (state) {
        case 1:
            if(ofGetFrameNum()%90==0){
                enemies.push_back(new Enemy(ofVec2f(30,300)));
            }
            
            entityControls();
            collisions();
            player.move(); //Same as previous comment but with player
            if(gameOver){
                state=2;
            }
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch(state){
            case 1:
                glPushMatrix();
                glTranslated(posOffset.x, posOffset.y, 0);
                //Displays all platforms, player and enemy
                for(auto _platform: platforms){
                    _platform->display();
                }
                for(int i=0; i<player.weapons.size(); i++){
                    for(auto &_projectile: player.weapons[i]->ammo){
                        _projectile.display();
                    }
                }
                
                for(int i=0; i<enemies.size(); i++){
                    enemies[i]->display();
                    text.drawString(to_string(i)+": "+to_string(enemies[i]->health), 10, i*10+30);
                }
                player.display();
                glPopMatrix();
                break;
            
            case 2:
                ofPushStyle();
                    ofSetColor(0);
                    text.drawString("Game Over", 50, 10);
                ofPopStyle();
                break;
            default:
            break;
    }
    
    ofPushStyle();
        ofSetColor(0);
        text.drawString(to_string(int(ofGetFrameRate())), 10,10);
        text.drawString(player.weapons[player.currentWeapon]->name+" "+to_string(player.weapons[player.currentWeapon]->reloadTime-player.weapons[player.currentWeapon]->counter), 10,20);
    ofPopStyle();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (state) {
        case 1:
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
            if(int(key)>=48 && int(key)<57){player.currentWeapon = int(key)-48;}
            if(key=='x'){
                player.weapons[player.currentWeapon]->checkHoldFire(player);
            }
            break;
        case 2:
            state=1;
            break;
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (state) {
        case 1:
            if(key == OF_KEY_UP || key == 'z'){
                up = false;
            }
            if(key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
                player.moving = false;
            }
            if(key=='x'){
                player.weapons[player.currentWeapon]->resetWeapon();
            }
            break;
        case 2:
            
            break;
        default:
            break;
    }
}

void ofApp::entityControls(){
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
    
    for(int i=0; i<enemies.size(); i++){
        enemies[i]->moveX(1);
        enemies[i]->move();
        enemies[i]->checkAlive();
        if(enemies[i]->checkEntity(player)){
            gameOver=true;
        }
        for(int j=0; j<player.weapons.size(); j++){
            for(int k=0; k<player.weapons[j]->ammo.size(); k++){
                if(enemies[i]->checkEntity(player.weapons[j]->ammo[k])){
                    damageEnemies(player.weapons[j]->ammo[k]);
                    player.weapons[j]->ammo.erase(player.weapons[j]->ammo.begin()+k);
                }
            }
        }
        if(enemies[i]->dead){
            delete enemies[i];
            enemies.erase(enemies.begin()+i);
        }
    }
    player.weapons[player.currentWeapon]->fireWeapon(player);
}

void ofApp::collisions(){
    //Tile collision routine
    for(auto &_enemy: enemies){
        _enemy->onPlatform = false;//Sets entities 'onPlatform' bool to false
    }
    player.onPlatform=false;
    
    //For each platform checks if the player is colliding with an entity and changes the onPlatform to true accordingly
    for(auto _platform: platforms){
        checkCollisions(_platform,&player);
        for(auto _enemy: enemies){
            checkCollisions(_platform,_enemy);
        }
    }
    
    for(int i=0; i<player.weapons.size(); i++){
        player.weapons[i]->checkBullets();
    }
}


void ofApp::checkCollisions(Tile *_platform, Entity *_entity){
    
    //Checks around the entity and only executes collision checks if entity is within 30 pixels in any direction of a platform
    if(abs(_platform->pos.x-_entity->pos.x)<30 && abs(_platform->pos.y-_entity->pos.y)<30){
    
        //Checks if entity is jumping into a tile from below
        if(_platform->detectBottom(_entity)){
            _entity->pos.y=_platform->pos.y+_platform->size.y/2+_entity->size.y/2; //Changes position of entity so it is below the tile and cannot clip through
            _entity->vel.y=0;
            _entity->acc.y=0;
        }
        
        //Detect if left of tile is colliding with the entity
        else if(_platform->detectLeft(_entity)){
            _entity->pos.x=_platform->pos.x-_platform->size.x/2-_entity->size.x/2; //Changes position of entity to side of tile thus not making the entity clip through the tile
        }
        
        //Same but with the right of the tile
        else if(_platform->detectRight(_entity)){
            _entity->pos.x=_platform->pos.x+_platform->size.x/2+_entity->size.x/2; //Changes position of entity to side of tile thus not making the entity clip through the tile
        }
        
        //Detects the top of the tile
        else if(_platform->detectTop(_entity)){
            _entity->action = false; //Entities can now jump
            _entity->vel.y=0; //Velocity set to 0, prevent clipping
            _entity->acc.y=0; //Acceleration set to 0, prevent clipping
            _entity->pos.y=_platform->pos.y-_platform->size.y/2-_entity->size.y/2;
            //Changes position of entity to above the top of the tile so the entity is in a 'buffer zone' meaning that the entity is not falling due to gravity but can still run and jump
        }

        
        //Checks if entity is in buffer zone and stops entity from falling through tile
        if(_platform->detectAboveTop(_entity)){
            if(_entity->vel.y>0){ //If entity is falling downward
                _entity->vel.y=0; //velocity stops to prevent clipping
            }
            _entity->onPlatform=true;
            _entity->action = false; //Entity can jump
        }
    }
}

void ofApp::createLevel(){
    for(int j=0; j<level.layout[0].size(); j++)
    {
        for(int i=0; i<level.layout.size(); i++)
        {
            switch(level.layout[i][j])
            {
                case 1:
                    platforms.push_back(new Platform(ofVec2f(i*20,j*20)));
                    break;
            }
        }
    }
}

void ofApp::damageEnemies(Projectile &_projectile){
    for(auto &_enemy: enemies){
        if(abs(_projectile.pos.x-_enemy->pos.x)<_projectile.explosionRadius+_projectile.size.x && abs(_projectile.pos.y-_enemy->pos.y)<_projectile.explosionRadius+_projectile.size.y){
            _enemy->health-=_projectile.damage;
        }
    }
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
