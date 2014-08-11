//
//  AbstractObject.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/1/14.
//
//

#include "AbstractObject.h"

AbstractObject::AbstractObject() :x(0), y(0), width(800), height(600), objectId(0)
{
    cout << "Default constructor with no args" << endl;
}

AbstractObject::AbstractObject(int _objectId, int _width, int _height) {
    x = 0;
    y = 0;
    width = _width;
    height = _height;
    objectId = _objectId;
}

AbstractObject::~AbstractObject() {
}

bool AbstractObject::operator == (const AbstractObject &rhs)
{
    return (rhs.objectId == objectId);
}

void AbstractObject::draw()
{
    ofSetColor(255,0,0);
    ofNoFill();
    ofRect(x, y, width, height);
}