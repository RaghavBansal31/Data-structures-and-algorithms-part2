// heaptest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Util.h"
#include <stdlib.h>
#include <iostream>



using namespace std;

int main()
{

    char c;
    int i, v, f;
    Heap z(0);
    while (true) {
        c = nextCommand(&i, &v, &f);
        //switch case
        switch (c)
        {
            case 's':
            case 'S':
                //excluding
                cout << "COMMAND: S" << endl;
                exit(0);
            case 'C':
                //to make heap
                printf("COMMAND: C %d\n", i);
                z = Heap(i);
                break;
            case 'r':
            case 'R':
                //to read file
                printf("COMMAND: R\n");
                if (z.getCapacity() == 0)
                 {
                    cout << "Error: heap is not initialized" << endl;
                    break;
                }
                ReadInputFile(z);
                break;
            case 'w':
            case 'W':
                //to show heap
                printf("COMMAND: W\n");
                if (z.getCapacity() == 0)
                {
                    cout << "Error: heap is not initialized" << endl;
                    break;
                }
                z.displayHeap();
                break;
            case 'D':
                //to delete top element
                printf("COMMAND: D %d\n", f);
                if (z.getCapacity() == 0)
                {
                    cout << "Error: heap is not initialized" << endl;
                    break;
                }
                if (z.get_Size() == 0)
                {
                    cout << "Error: heap is empty" << endl;
                    break;
                }
                if (f != 1 && f != 2)
                {
                    cout << "Error: invalid value of flag" << endl;
                    break;
                }
                if (f == 2)
                {
                    cout << "Before the delete max operation is conducted:" << endl;
                    z.displayHeap();
                    v=z.DeleteMax();
                    cout << "After the delete max operation is conducted:" << endl;
                    z.displayHeap();
                    cout <<"Deleted max = "<< v<<endl;
                }
                else if (f == 1)
                {
                    cout <<"Deleted max = "<< z.DeleteMax()<<endl;
                }
                break;
            case 'I':
                //to add element to heap
                printf("COMMAND: I %d %d\n", f, v);
                if (f != 1 && f != 2)
                {
                    cout << "Error: invalid value of flag" << endl;
                    break;
                }
                if (f == 2)
                {
                    cout << "Before the insertion operation:" << endl;
                    z.displayHeap();
                    z.insKey(v);
                    cout << "After the insertion operation:" << endl;
                    z.displayHeap();
                }
                else if (f == 1)
                {
                    z.insKey(v);
                }
                break;
            case 'K':
                //to increment heap
                printf("COMMAND: K %d %d %d\n", f, i, v);
                if (z.getCapacity() == 0)
                {
                    cout << "Error: heap is not initialized" << endl;
                    break;
                }
                if (f != 1 && f != 2)
                 {
                    cout << "Error: invalid value of flag" << endl;
                    break;
                }
                if (i > z.get_Size() || i<=0)
                {
                    cout << "Error: index is invalid" << endl;
                    break;
                }

                if (v < z.valByIndx(i - 1))
                {
                    cout << "Error: new key smaller than present key" << endl;
                    break;
                }

                if (f == 2)
                {
                    cout << "Before the increment key operation:" << endl;
                    z.displayHeap();
                    z.IncreKey(i - 1, v);
                    cout << "After the increment key operation:" << endl;
                    z.displayHeap();
                }
                else if (f == 1){
                    z.IncreKey(i - 1, v);
                }
                break;
            default: break;
        }
    }

    return 0;
}
