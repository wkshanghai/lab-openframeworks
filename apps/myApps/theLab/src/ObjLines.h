//
//  ObjLines.h
//  theLab
//
//  Created by Victor.Norgren on 8/5/14.
//
//

#ifndef __theLab__ObjLines__
#define __theLab__ObjLines__

#include <iostream>
#include "AbstractObject.h"

class ObjLines : public AbstractObject
{
public:
    ObjLines(int _objectId, int _width, int _height);
	ObjLines();
    
    void draw() override;
private:
	float 	counter;
};

#endif /* defined(__theLab__ObjLines__) */
