//lin
#include "heap.h"
#define __STDC_LIMIT_MACROS
#include <stdint.h>

//constructor
Heap::Heap(int cap)
{
    if (cap < 0)
    {
        cout << "Error: invalid heap capacity" << endl;
    }else
    {
        heapSize = 0;
        capacity = cap;
        heapArray = new ELEMENT[cap];
    }
}

//constructor
//Heap::Heap()
//{
  //  if (cap < -1)
  //  {
//        cout << "Error: invalid heap capacity" << endl;
  //  }else
//    {
//        heapSize = 0;
  //      capacity = cap;
  //      heap_array = new ELEMENT[cap];
  //  }
//}
//to build heap
void Heap::buildHeap(int arr[], int m)
{
    for (int j = 0; j < m; j++)
    {
        heapArray[j].key = arr[j];
    }
    heapSize = m;
    int startingIndex = (m / 2) - 1;
    for (int j = startingIndex; j >= 0; j--){
        Heapi(j);
    }
}

int Heap::getCapacity()
{
    return capacity;
}

int Heap::valByIndx(int j)
{
    return heapArray[j].key;
}

int Heap::par(int j)
{
    return (j - 1) / 2;
}

int Heap::get_Size()
{
    return heapSize;
}

int Heap::left(int j)
 {
    return (2 * j + 1);
}

int Heap::right(int j)
{
    return (2 * j + 2);
}


//to add key to the heap
void Heap::insKey(int q)
{

    if (heapSize == capacity)
     {
        for (int j = 1; ; j *= 2)
        {
            if (j > capacity)
            {
                capacity = j;
                break;
            }
        }
    }

    //to add key to  end
    heapSize++;
    int j = heapSize - 1;
    heapArray[j].key = q;


    while (j != 0 && heapArray[par(j)].key < heapArray[j].key)
     {
        swapp(&heapArray[j].key, &heapArray[par(j)].key);
        j = par(j);
    }
}


//methood to print
void Heap::displayHeap()
{
    cout << "Capacity = " << capacity << endl;
    cout << "Size = " << heapSize << endl;
    for (int j = 0; j < heapSize; j++){
        cout << heapArray[j].key<< endl;
    }
}

//2 elements  getting swapped
void Heap::swapp(int* u, int* o)
{
    int temt = *u;
    *u = *o;
    *o = temt;
}

//replacing the last element with the top
int Heap::DeleteMax()
{
   //if ther is no element
    if (heapSize<= 0)
    {
         return INT8_MAX;
    }
    //if there is only one element
    if (heapSize == 1)
    {
        heapSize--;
        return heapArray[0].key;
    }

    //getting rid of the top element
    int root = heapArray[0].key;
    heapArray[0].key = heapArray[heapSize - 1].key;
    heapSize--;
    Heapi(0);
    return root;
}

//this a methdd to max heap
void Heap::Heapi(int j)
 {
    int l = left(j);
    int r = right(j);
    int larg = j;
    if (l < heapSize && heapArray[l].key > heapArray[larg].key)
        larg = l;
    if (r < heapSize && heapArray[r].key > heapArray[larg].key)
        larg = r;
    if (larg != j) {
        swapp(&heapArray[j].key, &heapArray[larg].key);
        Heapi(larg);
    }
}

//this is a method to increase the vaue of the key
void Heap::IncreKey(int j, int newvalue)
{
    heapArray[j].key = newvalue;
    //placing key to right place
    while (j != 0 && heapArray[par(j)].key < heapArray[j].key)
    {
        swapp(&heapArray[j].key, &heapArray[par(j)].key);
        j = par(j);
    }
}
