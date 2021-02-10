//lib
#include <iostream>
using namespace std;

//struct element
struct ELEMENT
{
    int key;
};

class Heap
{
    int capacity;
    ELEMENT *heapArray;
    int heapSize;
public:
    //all methods
    Heap();
    Heap(int capacity);
    void buildHeap(int arr[], int m);
    void Heapi(int j);
    int DeleteMax();
    void insKey(int q);
    int valByIndx(int j);
    int getCapacity();
    int get_Size();
    int par(int j);
    int left(int j);
    int right(int j);
    void displayHeap();
    void swapp(int* u, int* o);
    void IncreKey(int j, int newvalue);
};
