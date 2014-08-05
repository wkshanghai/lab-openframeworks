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
    std::cout << "New object width ID (subclass) " << objectId << " and " << width << "x" << height << std::endl;
}

void ObjLines::draw()
{
    ofEnableSmoothing();
	
	ofSetHexColor(0xFF00FF);
    
    int segmentHeight = height / 21;
    
	for (int i = 0; i < 20; i++){
		ofLine(x,y + (i*3),x + width, y + (i*segmentHeight));
	}
	
    ofDisableSmoothing();
	
    ofSetColor(255,255,255);
	ofDrawBitmapString("lines", x + 5, y + 15);
    
    AbstractObject::draw();
}
