//
//  BinaryTree.cpp
//  Nodes
//
//  Created by Orton, Emily on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//
#include <iostream>
using namespace std;
#include "BinaryTree.h"
template <class Type>
void BinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() << " " ;
        preorderTraversal(currentNode->getLetChild());
        preorderTraversal(currentNode->getRightChild());
    }
}
template <class Type>
void BinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        
        inorderTraversal(currentNode->getLetChild());
        cout << currentNode->getValue() << " " ;
        inorderTraversal(currentNode->getRightChild());
    }
}
template <class Type>
void BinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        
        postorderTraversal(currentNode->getLetChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " " ;
    }
}

template <class Type>
bool BinaryTree<Type> :: contains(Type value)
{
    bool isInTree = false;

    if(root != nullptr)
    {
        if(root->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value > root->getValue())
            {
                isInTree = contains(value, root->getLeftChild());
            }
            else
            {
                isInTree = contains(value, root->getRightChild());
            }
        }
    }
    
    return isInTree;
}