//
//  ObjLines.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#include "ObjLines.h"

ObjLines::ObjLines(int _objectId, int _width, int _height) : AbstractObject(_objectId, _width, _height)
{
    x = 0;
    y = 0;
    width = _width;
    height = _height;
    objectId = _objectId;
    counter = 0;
    std::cout << "New object width ID (subclass) " << objectId << " and " << width << "x" << height << std::endl;
}

void ObjLines::draw()
{
    ofEnableSmoothing();
	
	ofSetHexColor(0xFF0000);
	for (int i = 0; i < 20; i++){
		ofLine(x,100 + (i*5),500, 50 + (i*10));
	}
	
    ofDisableSmoothing();
	
    ofSetColor(255,255,255);
	ofDrawBitmapString("lines\npress 's' to toggle smoothness", 300,300);
    
    AbstractObject::draw();
}
