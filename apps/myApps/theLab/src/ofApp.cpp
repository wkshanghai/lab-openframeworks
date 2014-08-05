#include "ofApp.h"
#include "AbstractObject.h"

#include "ObjPixelRect.h"
#include "ObjCircle1.h"
#include "ObjCircle2.h"
#include "ObjLines.h"
#include "ObjStaticNoise.h"

const int width = 800;
const int height = 600;

//--------------------------------------------------------------
void ofApp::setup(){

    counter = 0;
	ofSetCircleResolution(50);
	
    //ofBackground(0,0,0);
    
    bSmooth = false;
	ofSetWindowTitle("ofxSyphon Example");
    
	mainOutputSyphonServer.setName("Screen Output");
	individualTextureSyphonServer.setName("Texture Output");
    
	mClient.setup();
    
    //using Syphon app Simple Server, found at http://syphon.v002.info/
    mClient.set("","Simple Server");
	
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    shared_ptr<AbstractObject> ptr1(new ObjPixelRect(1, 128, 128));
    shared_ptr<AbstractObject> ptr2(new ObjCircle1(1, 128, 128));
    shared_ptr<AbstractObject> ptr3(new ObjCircle2(1, 128, 128));
    shared_ptr<AbstractObject> ptr4(new ObjLines(1, 512, 128));
    shared_ptr<AbstractObject> ptr5(new ObjStaticNoise(1, 128, 128));

    container.add(ptr1);
    container.add(ptr2);
    container.add(ptr3);
    container.add(ptr4);
    container.add(ptr5);
}

//--------------------------------------------------------------
void ofApp::update(){
	counter = counter + 0.033f;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Clear with alpha, so we can capture via syphon and composite elsewhere should we want.
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// Syphon Stuff
    mClient.draw(50, 50);
	mainOutputSyphonServer.publishScreen();
    
    //individualTextureSyphonServer.publishTexture(&tex);
    
    ofDrawBitmapString("Note this text is not captured by Syphon since it is drawn after publishing.\nYou can use this to hide your GUI for example.", 150,500);
    container.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's'){
		bSmooth = !bSmooth;
	}
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
