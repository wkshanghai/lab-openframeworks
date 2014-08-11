//
//  LayoutManager.h
//  theLab
//
//  Created by Victor.Norgren on 8/4/14.
//
//

#ifndef __theLab__LayoutManager__
#define __theLab__LayoutManager__


#include "Node.h"
#include "AbstractObject.h"
#include <iostream>
#include "AbstractObject.h"
#include <list>

using namespace std;

class LayoutManager {
    
public:
    LayoutManager();
	~LayoutManager();

    Node *startNode;
    
    vector<shared_ptr<AbstractObject> > objects;

    void add(shared_ptr<AbstractObject> object);
    
    void layout();
    void draw();
    Node *insertRect(Node *cnode, shared_ptr<AbstractObject> newRect);
    
protected:
private:
    
};


#endif /* defined(__theLab__LayoutManager__) */
