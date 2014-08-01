//
//  AbstractObject.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/1/14.
//
//

#include "AbstractObject.h"

AbstractObject::AbstractObject(int _objectId, int _width, int _height) {
    width = _width;
    height = _height;
    objectId = _objectId;
    std::cout << "New object width ID " << objectId << " and " << width << "x" << height << std::endl;
}