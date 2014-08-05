//
//  AbstractObject.h
//  theLab
//
//  Created by Victor.Norgren on 8/1/14.
//
//

#ifndef __theLab__AbstractObject__
#define __theLab__AbstractObject__

#include "ofMain.h"
#include <iostream>

class AbstractObject {
public:
    AbstractObject(int _objectId, int _width, int _height);
	~AbstractObject();
    
    int objectId;
    int x;
    int y;
    int width;
    int height;
    
    virtual void draw();
    
    bool operator == (const AbstractObject &rhs);
protected:
private:
    
};

#endif /* defined(__theLab__AbstractObject__) */
