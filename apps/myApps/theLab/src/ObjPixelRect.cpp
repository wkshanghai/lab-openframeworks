//
//  ObjPixelRect.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/4/14.
//
//

#include "ObjPixelRect.h"
#include "AbstractObject.h"
#include "ofMain.h"

ObjPixelRect::ObjPixelRect(int _objectId, int _width, int _height) : AbstractObject(_objectId, _width, _height)
{
    x = 0;
    y = 0;
    width = _width;
    height = _height;
    objectId = _objectId;
    std::cout << "New object width ID (subclass) " << objectId << " and " << width << "x" << height << std::endl;
}

void ObjPixelRect::draw()
{
    //--------------------------- rectangles
	ofFill();
	for (int i = 0; i < 200; i++){
		ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
		ofRect(ofRandom(250,350),ofRandom(350,450),ofRandom(10,20),ofRandom(10,20));
	}
	ofSetHexColor(0x000000);
	ofDrawBitmapString("rectangles", 275,500);
    cout << "Subclass drawing..." << endl;
    //AbstractObject::draw();
}