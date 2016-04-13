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
        
        preorderTraversal(currentNode->getLetChild());
        cout << currentNode->getValue() << " " ;
        preorderTraversal(currentNode->getRightChild());
    }
}
template <class Type>
void BinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        
        preorderTraversal(currentNode->getLetChild());
        preorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " " ;
    }
}
