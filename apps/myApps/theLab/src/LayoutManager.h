//
//  LayoutManager.h
//  theLab
//
//  Created by Victor.Norgren on 8/4/14.
//
//

#ifndef __theLab__LayoutManager__
#define __theLab__LayoutManager__

#include <iostream>
#include "AbstractObject.h"
#include <list>

using namespace std;

class LayoutManager {
    
public:
    LayoutManager();
	~LayoutManager();

    list<AbstractObject*> objects;
    
    AbstractObject add(AbstractObject object);
    void remove(AbstractObject object);
    
    void layout();
    void draw();
    
protected:
private:
    
};


#endif /* defined(__theLab__LayoutManager__) */
