//
//  CTECHashTable.cpp
//  Nodes
//
//  Created by Orton, Emily on 5/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECHashTable.hpp"
#include <iostream>
#include <cmath>
using namespace std;


template<class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->internalStorage = new HashNode<Type>*[capacity];
    this->chainedSize = 0;
    this->chainedCapacity = 101;
    this->chainedStorage = new CTECLists<HashNode <Type>>[chainedCapacity];
}

template<class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
    delete [] chainedStorage;
}

template<class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}
template<class Type>
void CTECHashTable<Type> :: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateCapacity();
        }
        int insertionIndex = findPos(currentNode);
        HashNode<Type> * tempPointer = internalStorage[insertionIndex];
        if(tempPointer != NULL)
        {
            insertionIndex = handleCollision(currentNode);
            
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
            cout << internalStorage[insertionIndex] << endl;
        }
        internalStorage[insertionIndex] = &currentNode;
        cout << internalStorage[insertionIndex] << endl;
        size++;
    }
    
    
    
}

template<class Type>
int CTECHashTable<Type> :: findPos(HashNode<Type> currentNode)
{
    int pos = 0;
    pos = currentNode.getKey() % capacity;
    return pos;
}


template<class Type>
int CTECHashTable<Type> :: getNextPrime()
{
    int nextPrime = capacity;
    
    nextPrime *= 2;
    nextPrime++;
    
    while(!isPrime(nextPrime))
    {
        nextPrime+=2;
    }
    
    
    return nextPrime;
}

template<class Type>
bool CTECHashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    if(candidateNumber <=1)
    {
        isPrime = false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 ==0)
    {
        isPrime = false;
    }
    else
    {
        for(int spot = 3; spot < sqrt(candidateNumber) + 1; spot+=2)
        {
            if(spot)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    
    return isPrime;
    
}
template<class Type>
void CTECHashTable<Type> :: updateCapacity()
{
    int updatedCapacity = getNextPrime();
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    HashNode<Type> * largerStorage = new HashNode<Type>[capacity];
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedIndex = findPos(*internalStorage[index]);
            largerStorage[updatedIndex] = *internalStorage[index];
            
        }
    }
    internalStorage = &largerStorage;
}

template<class Type>
bool CTECHashTable<Type> :: contains(HashNode<Type> currentNode)
{
    
    bool isInTable = false;
    int possibleLocation = findPos(currentNode);
    
    cout << "here" << endl;
    
    while(internalStorage[possibleLocation] != nullptr && !isInTable)
    {
        cout << "here2" << endl;
        
        if(internalStorage[possibleLocation]->getValue() == currentNode.getValue())
        {
            cout << "here3" << endl;
            isInTable = true;
        }
        possibleLocation = (possibleLocation + 1) % capacity;
    }
    
    return isInTable;
}

template<class Type>
bool CTECHashTable<Type> :: remove(HashNode<Type> currentNode)
{
    bool hasBeenRemoved = false;
    if(contains(currentNode))
    {
        int possibleLocation = findPos(currentNode);
        
        while(internalStorage[possibleLocation] != nullptr && !hasBeenRemoved)
        {
            if(internalStorage[possibleLocation]->getValue() == currentNode.getValue())
            {
                hasBeenRemoved = true;
                internalStorage[possibleLocation] = nullptr;
            }
            possibleLocation = (possibleLocation + 1) % capacity;
        }
        
    }
}




template<class Type>
int CTECHashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
    int updatedPos = findPos(currentNode);
    
    
    updatedPos = ( 47 + (updatedPos * updatedPos)) % capacity;
    
    
    
    return updatedPos;
}



template<class Type>
void CTECHashTable<Type> :: addChained(HashNode<Type> currentNode)
{
    if((chainedSize/chainedCapacity) >= efficiencyPercentage())
    {
        updateChainCapacity();
    }
    int insertionIndex = findPos(currentNode);
    if(chainedStorage[insertionIndex] != nullptr)
    {
        CTECLists<HashNode<Type>> temp = chainedStorage[insertionIndex];
        temp.addEnd(currentNode);
    }
    else
    {
        CTECLists<HashNode<Type>> tempList;
        tempList.addEnd(currentNode);
        chainedStorage[insertionIndex] = tempList;
    }
    chainedSize++;
}




template<class Type>
void CTECHashTable<Type> :: updateChainCapacity()
{
    int updatedChainedCapacity = getNextPrime();
    int oldChainedCapacity = capacity;
    chainedCapacity = updatedChainedCapacity;
    
    CTECLists<HashNode<Type>> * largestChainedStorage = new CTECLists<HashNode<Type>>[updatedChainedCapacity];
    for(int index = 0; index < oldChainedCapacity; index++)
    {
        if(chainedStorage[index] != nullptr)
        {
            CTECLists<HashNode<Type>> temp = chainedStorage[index];
            for(int innerIndex = 0; innerIndex < temp.getSize(); innerIndex++)
            {
                int updatedChainedPos = findPos(temp.getFromIndex(innerIndex));
                if(largestChainedStorage[updatedChainedPos] == nullptr)
                {
                    CTECLists<HashNode<Type>> insertList;
                    insertList.addEnd(temp.getomIndex(innerIndex));
                    largestChainedStorage[updatedChainedPos] = insertList;
                }
                else
                {
                    largestChainedStorage[updatedChainedPos].addEnd(temp.getFromIndex(innerIndex));
                }
            }
        }
    }
    
}