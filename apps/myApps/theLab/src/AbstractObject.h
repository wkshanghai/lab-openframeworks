//
//  AbstractObject.h
//  theLab
//
//  Created by Victor.Norgren on 8/1/14.
//
//

#ifndef __theLab__AbstractObject__
#define __theLab__AbstractObject__

#include <iostream>

class AbstractObject {
    int objectId;
    int width;
    int height;
    
public:
    AbstractObject(int _objectId, int _width, int _height);
	~AbstractObject();
protected:
private:
    
};

#endif /* defined(__theLab__AbstractObject__) */
