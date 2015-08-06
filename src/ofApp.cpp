#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    openNIDevice.setup();
    openNIDevice.setMirror(true);
    openNIDevice.setRegister(true);
    
    // frames
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setDepthColoring(COLORING_GREY);
    localColorFrame = openNIDevice.getimageTextureReference();
    localDepthFrame = openNIDevice.getDepthTextureReference();
    remoteColorFrame.allocate(640, 480, GL_RGB8);
    remoteDepthFrame.allocate(640, 480, GL_R8);

    // users
    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(4);
    
    // misc
    
    openNIDevice.start();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    openNIDevice.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int w = 640;
    int h = 480;
    
    localColorFrame.draw(0, 0, w, h);
    localDepthFrame.draw(w, 0, w, h);
    remoteColorFrame.draw(0, h, w, h);
    remoteDepthFrame.draw(w, h, w, h);
    
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
    openNIDevice.stop();
}
