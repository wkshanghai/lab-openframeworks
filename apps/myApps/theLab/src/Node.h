//
//  Node.h
//  theLab
//
//  Created by Mimosa.Poon on 8/7/14.
//
//

#ifndef __theLab__Node__
#define __theLab__Node__

#include "AbstractObject.h"
#include <iostream>

class Node {
public:
    Node();
    Node *left = NULL;
    Node *right = NULL;
    AbstractObject rect;
    bool isFill = false;
    //Node insertRect();
};

#endif /* defined(__theLab__Node__) */
