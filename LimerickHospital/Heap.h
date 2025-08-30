using namespace std;

template<class ItemType>
// Assumes ItemType is either a built-in simple  // type or a class with overloaded relational    // operators.
struct HeapType
{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType* elements; 						// Array to be allocated dynamically
    int numElements;
};

template<class ItemType>
inline void Swap(ItemType& item1,
    ItemType& item2)
    // Post: Contents of item1 and item2 have been swapped.
{
    ItemType tempItem;
    tempItem = item1;
    item1 = item2;
    item2 = tempItem;
}

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
    int maxChild;
    int rightChild;
    int leftChild;
    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    maxChild = leftChild;

    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (elements[leftChild].GetPriority() < elements[rightChild].GetPriority())
                maxChild = rightChild;
            else if (elements[leftChild].GetPriority() == elements[rightChild].GetPriority())
                if (elements[leftChild].GetAdmission() >= elements[rightChild].GetAdmission())
                    maxChild = rightChild;
                else
                    maxChild = leftChild;
            else
                maxChild = leftChild;
        }

        if (elements[root].GetAdmission() < elements[maxChild].GetAdmission())
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }

        if (elements[root].GetPriority() < elements[maxChild].GetPriority())
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
    int parent;
    if (bottom > root)
    {
        parent = (bottom - 1) / 2;
        if (elements[parent].GetPriority() < elements[bottom].GetPriority())
        {
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}
