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
}

void ObjPixelRect::draw()
{
    //--------------------------- rectangles
	ofFill();
	for (int i = 0; i < 200; i++){
		ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
		ofRect(ofRandom(x,x+width-20),ofRandom(y,y+height-20),ofRandom(10,20),ofRandom(10,20));
	}

	ofSetHexColor(0xffffff);
	ofDrawBitmapString("rectangles", x + 5, y + 15);

    AbstractObject::draw();
}