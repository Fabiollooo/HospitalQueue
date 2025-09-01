#pragma once

#include "Heap.h"
template<class ItemType>
class PQType
{
public:
    PQType(int);          						// parameterized class constructor
    ~PQType();							      // class destructor

    void MakeEmpty();
    // Function: Initializes the queue to an empty
    // state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is
    // empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is
    // full.
    // Post: Function value = (queue is full)
    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the
    // queue.
    // Pre:  Queue is not full.
    // Post: newItem is in the queue.
    void Dequeue(ItemType& item);
    // Function: Removes element with highest
    // priority from the queue
    // and returns it in item.
    // Pre:  Queue is not empty.
    // Post: Highest priority element has been 
    //       removed from the queue.
    //       item is a copy of the removed element
public: //changed to public
    int numItems;
    HeapType<ItemType> items;
    int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[max];
    numItems = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete[] items.elements;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    numItems = 0;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Function value = true if the queue is   // 		empty; false, otherwise
{
    return numItems == 0;
}

template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Function value = true if the queue is   // 		full; false, otherwise
{
    return numItems == maxItems;
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is in the queue.
{
    numItems++;
    items.elements[numItems - 1] = newItem;
    items.ReheapUp(0, numItems - 1);
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been  // removed from the queue; a copy is returned in // item.
{
    item = items.elements[0];
    items.elements[0] = items.elements[numItems - 1];
    numItems--;
    items.ReheapDown(0, numItems - 1);
}


