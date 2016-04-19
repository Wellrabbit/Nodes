//
//  BinaryTree.hpp
//  Nodes
//
//  Created by Orton, Emily on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include "TreeNode.h"
template <class Type>
class BinaryTree
{
private:
    int size;
    TreeNode<Type> * root;
    int height;
    bool balanced;
    void calculateSize(TreeNode<Type> * currentNode);
    bool contains(Type value, BinaryTree<Type> * currentTree); // Done
    TreeNode<Type> * getRightMostChild(BinaryTree<Type> leftSubTree);
    TreeNode<Type> * getLeftMostChild(BinaryTree<Type> rightSubTree);
public:
    BinaryTree();
    ~BinaryTree();
    bool insert( const Type& value);
    Type remove(const Type& value);
    bool contains (Type value); //Done
    int getSize();
    int getHieght();
    bool isBalanced();
    TreeNode<Type> * getRoot();
    void preorderTraversal(TreeNode<Type> * currentNode); //Done
    void inorderTraversal(TreeNode<Type> * currentNode); //Done
    void postorderTraversal(TreeNode<Type> * currentNode); //Done
};


#endif /* BinaryTree_hpp */
