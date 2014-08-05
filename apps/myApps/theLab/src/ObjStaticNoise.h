//
//  ObjStaticNoise.h
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#ifndef __theLab__ObjStaticNoise__
#define __theLab__ObjStaticNoise__

#include <iostream>
#include "AbstractObject.h"

class ObjStaticNoise : public AbstractObject
{
public:
    ObjStaticNoise(int _objectId, int _width, int _height);
    
    void draw() override;
private:
    ofTexture tex;
};

#endif /* defined(__theLab__ObjStaticNoise__) */
