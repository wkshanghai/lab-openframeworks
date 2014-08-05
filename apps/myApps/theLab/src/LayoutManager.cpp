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
    objects.push_back(object);
    layout();
}

template <typename T> bool PComp(const T & a, const T & b)
{
    return (*a).width > (*b).width;
}

void LayoutManager::layout()
{
    cout << "LayoutManager::layout()" << endl;
    //sort(objects.begin(), objects.end());
    
    std::sort(objects.begin(), objects.end(), PComp<shared_ptr<AbstractObject> >);

    uint i = 0;
    uint biggestHeight = 0;
    uint x = 0;
    uint y = 0;
    uint w = 800;
    uint h = 600;
    
    vector<shared_ptr<AbstractObject> >::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); iterator++)
    {
        (*iterator)->draw();

        if((*iterator)->height > biggestHeight)
            biggestHeight = (*iterator)->height;
        
        // check if column exceeds width
        if((x + (*iterator)->width) >= w) {
            x = 0;
            y += biggestHeight;
            biggestHeight = 0;
        }
        
        (*iterator)->x = x;
        (*iterator)->y = y;
        x += (*iterator)->width;

        i++;
    }
    
    // Packing algorithm here!
}

void LayoutManager::draw()
{
    vector<shared_ptr<AbstractObject> >::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); iterator++)
        (*iterator)->draw();
}