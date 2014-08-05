//
//  ObjCircle1.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#include "ObjCircle1.h"

ObjCircle1::ObjCircle1(int _objectId, int _width, int _height) : AbstractObject(_objectId, _width, _height)
{
    x = 0;
    y = 0;
    width = _width;
    height = _height;
    objectId = _objectId;
    counter = 0;
    std::cout << "New object width ID (subclass) " << objectId << " and " << width << "x" << height << std::endl;
}

void ObjCircle1::draw()
{
	counter = counter + 0.033f;

    //let's draw a circle:
    ofSetColor(255,130,0);
    float radius = (width * .3) + 20 * sin(counter);
    ofFill();
    ofCircle(x + (width*0.5),y + (height*0.5),radius);

    ofSetHexColor(0xFFFFFF);
	ofDrawBitmapString("circle1", x + 5, y + 15);
    
    AbstractObject::draw();
}
