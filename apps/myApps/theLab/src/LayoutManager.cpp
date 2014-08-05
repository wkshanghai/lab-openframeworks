//
//  LayoutManager.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/4/14.
//
//

#include "LayoutManager.h"
#include <algorithm>

LayoutManager::LayoutManager()
{
    cout << "LayoutManager::LayoutManager()" << endl;
}

LayoutManager::~LayoutManager()
{
}

AbstractObject LayoutManager::add(AbstractObject object)
{
    cout << "LayoutManager::add()" << endl;
    objects.push_back(&object);
    layout();
    return object;
}

void LayoutManager::remove(AbstractObject object)
{
    cout << "LayoutManager::remove()" << endl;
    objects.remove(&object);
}

void LayoutManager::layout()
{
    cout << "LayoutManager::layout()" << endl;
    // Packing algorithm here!
}

void LayoutManager::draw()
{
    list<AbstractObject*>::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); iterator++)
    {
        (*iterator)->draw();
    }
    
    // Packing algorithm here!
}