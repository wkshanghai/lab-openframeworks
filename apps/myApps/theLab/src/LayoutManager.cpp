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

void LayoutManager::add(shared_ptr<AbstractObject> object)
{
    cout << "LayoutManager::add()" << endl;
    objects.push_back(object);
    layout();
}

void LayoutManager::layout()
{
    cout << "LayoutManager::layout()" << endl;
    // Packing algorithm here!
}

void LayoutManager::draw()
{
    vector<shared_ptr<AbstractObject> >::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); iterator++)
        (*iterator)->draw();
}