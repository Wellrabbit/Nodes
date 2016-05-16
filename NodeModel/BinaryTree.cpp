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
BinaryTree<Type> :: BinaryTree()
{
    this-> root= nullptr;
    this->size=0;
    this->height=0;
    this->balanced=true;
}
template <class Type>
int BinaryTree<Type> :: getSize()
{
    size=0;
    calculateSize(root);
    return size;
}
template<class Type>
BinaryTree<Type> :: ~BinaryTree()
{
    
}

template <class Type>
void BinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculatedSize(currentNode->getLeftChild());
        calculatedSize(currentNode->getRightChild());
        size++;
    }
}
template <class Type>
TreeNode<Type> * BinaryTree<Type> :: getRoot()
{
    return root;
}

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

template <class Type>
bool BinaryTree<Type> :: contains(Type value, TreeNode<Type> * currentTree)
{
    bool isInTree = false;
    
    if(currentTree != nullptr)
    {
        if(currentTree->getRoot()->getValue() == value)
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

template<class Type>
bool BinaryTree<Type> :: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
        TreeNode<Type> * current = root;
        TreeNode<Type> * trailNode;
        
        if(root == nullptr)
        {
            root = new TreeNode<Type>(value);
        }
        else
        {
            while(current != nullptr)
            {
                trailNode = current;
                
                if(current->getValue() > value)
                {
                    current = current->getLeftChild();
                    
                }
                else
                {
                    current = current->getRightChild();
                    
                }
            }
            if(trailNode->getValue() > value)
            {
                trailNode->setLeftChild(new TreeNode<Type>(value, trailNode));
                
            }
            else
            {
                TreeNode<Type> * insertedNode = new TreeNode<Type>(value, trailNode);
                trailNode->setRightChild(insertedNode);
                
            }
            
        }
    }
    return true;
}

template <class Type>
TreeNode<Type> * BinaryTree<Type> :: getLeftMostChild(TreeNode<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode= rightSubTree->getRoot();
    while(leftNode->getleftChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}

template <class Type>
TreeNode<Type> * BinaryTree<Type>:: getRightMostChild(TreeNode<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode= leftSubTree->getRoot();
    while(rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}
template<class Type>
void BinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    
    if(!contains(value))
    {
        
        return;
    }
    else
    {
        
        current = root;
        trailing =root;
        cout<<"got here" << endl;
        while(current != nullptr && current->getValue() != value)
        {
            cout<<"got here" << endl;
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        if(current == root)
        {
            cout << "removing root" << endl;
            remove(root);
        }
        else if(trailing->getValue() > value)
        {
            remove(trailing->getLeftChild());
        }
        else
        {
            remove(trailing->getRightChild());
        }
    }
}
template<class Type>
void BinaryTree<Type> :: remove(TreeNode<Type> * nodeToBeRemoved)
{
    
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if(nodeToBeRemoved == nullptr)
    {
        cerr << "That isn't in the list" << endl;
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr && nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nullptr;
        delete temp;
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nodeToBeRemoved->getRightChild();
        delete temp;
    }
    else if(nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nodeToBeRemoved->getLeftChild();
        delete temp;
    }
    else
    {
        current = nodeToBeRemoved->getLeftChild();
        trailing = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToBeRemoved->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToBeRemoved->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        delete current;
        
    }
    
}


