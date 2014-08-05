//
//  ObjPixelRect.h
//  theLab
//
//  Created by Victor.Norgren on 8/4/14.
//
//

#ifndef __theLab__ObjPixelRect__
#define __theLab__ObjPixelRect__

#include <iostream>
#include "AbstractObject.h"

class ObjPixelRect : public AbstractObject
{
public:
    ObjPixelRect(int _objectId, int _width, int _height);

    void draw() override;
private:
};

#endif /* defined(__theLab__ObjPixelRect__) */
