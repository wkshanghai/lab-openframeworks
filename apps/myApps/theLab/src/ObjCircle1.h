//
//  ObjCircle1.h
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#ifndef __theLab__ObjCircle1__
#define __theLab__ObjCircle1__

#include <iostream>
#include "AbstractObject.h"

class ObjCircle1 : public AbstractObject
{
public:
    ObjCircle1(int _objectId, int _width, int _height);
	ObjCircle1();
    
    void draw() override;
private:
	float 	counter;
};

#endif /* defined(__theLab__ObjCircle1__) */
