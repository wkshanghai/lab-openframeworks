//
//  ObjCircle2.h
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#ifndef __theLab__ObjCircle2__
#define __theLab__ObjCircle2__

#include <iostream>
#include "AbstractObject.h"

class ObjCircle2 : public AbstractObject
{
public:
    ObjCircle2(int _objectId, int _width, int _height);
    
    void draw() override;
private:
	float 	counter;
};

#endif /* defined(__theLab__ObjCircle2__) */
