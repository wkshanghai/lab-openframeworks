//
//  ObjStaticNoise.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#include "ObjStaticNoise.h"

ObjStaticNoise::ObjStaticNoise(int _objectId, int _width, int _height) : AbstractObject(_objectId, _width, _height)
{
    x = 0;
    y = 0;
    width = _width;
    height = _height;
    objectId = _objectId;
    tex.allocate(width, height, GL_RGBA);
}

void ObjStaticNoise::draw()
{
    // draw static into our one texture.
    unsigned char pixels[width*height*4];
    
    for (int i = 0; i < width*height*4; i++)
    {
        pixels[i] = (int)(255 * ofRandomuf());
    }
    tex.loadData(pixels, width, height, GL_RGBA);
    
    ofSetColor(255, 255, 255);
    
    ofEnableAlphaBlending();
    
    tex.draw(x, y);
    
    ofSetHexColor(0xFFFFFF);
	ofDrawBitmapString("texture", x + 5, y + 15);

    AbstractObject::draw();
}
