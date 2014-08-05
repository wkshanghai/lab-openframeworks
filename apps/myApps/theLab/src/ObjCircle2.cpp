//
//  ObjCircle2.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#include "ObjCircle2.h"

ObjCircle2::ObjCircle2(int _objectId, int _width, int _height) : AbstractObject(_objectId, _width, _height)
{
    x = 0;
    y = 0;
    width = _width;
    height = _height;
    objectId = _objectId;
    counter = 0;
}

void ObjCircle2::draw()
{
	ofNoFill();
	ofSetHexColor(0xCCCCCC);
	ofCircle(x + (width*.5),y + (height*.5), width * .5);

    ofSetHexColor(0xFFFFFF);
	ofDrawBitmapString("circle2", x + 5, y + 15);
    
    AbstractObject::draw();
}
