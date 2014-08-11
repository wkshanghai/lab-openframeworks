//
//  LayoutManager.cpp
//  theLab
//
//  Created by Victor.Norgren on 8/4/14.
//
//

#include "LayoutManager.h"
#include "Node.h"
#include "AbstractObject.h"
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
}

template <typename T> bool compareWidth(const T & a, const T & b)
{
    return (*a).width > (*b).width;
}

template <typename T> bool compareHeight(const T & a, const T & b)
{
    return (*a).height < (*b).height;
}

void LayoutManager::layout()
{
    sort(objects.begin(), objects.end(), compareWidth<shared_ptr<AbstractObject> >);
    
    cout << "LayoutManager::layout()" << endl;
    cout << objects.size() << endl;
    
    //define first Node and its rect//
    startNode = new Node();
    startNode->rect.x = 0;
    startNode->rect.y = 0;
    startNode->rect.width = ofGetWidth();
    startNode->rect.height = ofGetHeight();
    
    int i;
    for(i = 0; i < objects.size(); i++)
    {
        cout << "iterator size " << objects.size() << " num " << i << endl;
        
        shared_ptr<AbstractObject> rect = objects.at(i);
        
        cout << rect->width << endl;
        cout << rect->height << endl;
        
        Node *node = insertRect(startNode, rect);
        if(node != NULL) {
            cout << "has node!" << endl;
            rect->x = node->rect.x;
            rect->y = node->rect.y;
        }
    }
}

Node *LayoutManager::insertRect(Node *cnode, shared_ptr<AbstractObject> newRect)
{
    cout << "LayoutManager::insertRect" << endl;
    
    if(cnode->left != NULL) {
        cout << "Has Left" << endl;
        Node *leftInsertRect =insertRect(cnode->left, newRect);
        if(leftInsertRect != NULL)
        {
           cout << "leftInsertRect" << endl;
            return leftInsertRect;
        }
        else
        {
            cout << "rightInsertRect" << endl;
            return insertRect(cnode->right, newRect);
        }
    }
    
    if(cnode->isFill == true) {
        cout << "isFilled" << endl;
        return NULL;
    }
    
    if(fitsIn(cnode->rect,newRect) == false) {
        cout << "doesn't fit" << endl;
        return NULL;
    }
    
    if(sameSize(cnode->rect,newRect) == true)
    {
        cout << "same size" << endl;
        cnode->isFill = true;
        
        return cnode;
    }
    
    cout << "make left & right" << endl;
    
    cnode->left = new Node();
    cnode->right = new Node();
    
    float widthDiff = cnode->rect.width - newRect->width;
    float heightDiff = cnode->rect.height - newRect->height;
    
    if( widthDiff > heightDiff) {
        cnode->left->rect.x = cnode->rect.x;
        cnode->left->rect.y = cnode->rect.y;
        cnode->left->rect.width = newRect->width;
        cnode->left->rect.height = cnode->rect.height;
        
        cnode->right->rect.x = cnode->rect.x + newRect->width;
        cnode->right->rect.y = cnode->rect.y;
        cnode->right->rect.width = cnode->rect.width - newRect->width;
        cnode->right->rect.height = cnode->rect.height;
        
    }else {
        cnode->left->rect.x = cnode->rect.x;
        cnode->left->rect.y = cnode->rect.y;
        cnode->left->rect.width = cnode->rect.width;
        cnode->left->rect.height = newRect->height;
        
        cnode->right->rect.x = cnode->rect.x;
        cnode->right->rect.y = cnode->rect.y + newRect->height;
        cnode->right->rect.width = cnode->rect.width;
        cnode->right->rect.height = cnode->rect.height - newRect->height;
    }
    
    return insertRect(cnode->left, newRect);
}

bool LayoutManager::sameSize(AbstractObject nodeRect,shared_ptr<AbstractObject> newRect)
{
    if(nodeRect.width == newRect->width && nodeRect.height == newRect->height){
        return true;
    }
    return false;
}

bool LayoutManager::fitsIn(AbstractObject nodeRect,shared_ptr<AbstractObject> newRect)
{
    if(newRect->width <= nodeRect.width && newRect->height <= nodeRect.height){
        return true;
    }
    return false;
}

void LayoutManager::draw()
{
    vector<shared_ptr<AbstractObject> >::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); iterator++)
        (*iterator)->draw();
}