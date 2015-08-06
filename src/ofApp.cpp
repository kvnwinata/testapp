#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    openNI.setup();
    openNI.setMirror(true);
    openNI.addImageGenerator();
    openNI.addDepthGenerator();
    openNI.addUserGenerator();
    openNI.setMaxNumUsers(4);
    openNI.start();
    
    openNI.setDepthColoring(COLORING_GREY);
}

//--------------------------------------------------------------
void ofApp::update(){
    openNI.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    openNI.drawDebug(0, 0, ofGetWidth(), ofGetHeight());
    
    // get number of current users
    int numUsers = openNI.getNumTrackedUsers();
    
    //cout << "num:" << numUsers << endl;
    
    for (int i = 0; i < numUsers; i++){
        
        // get a reference to this user
        ofxOpenNIUser & user = openNI.getTrackedUser(i);
            
    }
    
    ofSetColor(255,255,255, ((int) ofGetElapsedTimeMillis()/5) % 255);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255,255,255,255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit()
{
    openNI.stop();
}
