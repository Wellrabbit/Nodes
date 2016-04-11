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
    bool contains(Type value, BinaryTree<Type> * currentTree)
public:
    BinaryTree();
    ~BinaryTree();
    bool insert( const Type& value)
    Type remove(const Type& value)
    bool contains (type value)
    int getSize();
    int getHieght();
    bool isBalanced();
    TreeNode<Type> * getRoot();
};


#endif /* BinaryTree_hpp */
