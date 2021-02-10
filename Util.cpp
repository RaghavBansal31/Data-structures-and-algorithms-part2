//lib
#include "Util.h"


void ReadInputFile(Heap& z)
{
    //to open file
    ifstream fin;
    fin.open("HEAPINPUT.txt");
    //if file is not opened
    if (!fin)
    {
        cout << "File is not opened" << endl;
        fin.close();
        return;
    }
    //to take in the numnber of elements
    int n;
    fin >> n;
    if (n > z.getCapacity())
    {
        cout << "Error: array size crosses heap capacity" << endl;
        return;
    }

    int* A = new int[n];
    int y = 0;

    for (int i = 0; ; i++)
    {
        y = i;
        if (i == n) break;
        string w;
        fin >> w;
        if (w == "")
        {
          break;
        }
        bool flag = false;
        if (w[0] == '-')
        {
          flag = true;
        }
        A[i] = 0;
        for (int j = 0; j < w.length(); j++)
        {
            if (w[j] == '-') continue;
            A[i] = A[i] * 10 + (w[j] - '0');
        }

        if(flag == true)
        {
            A[i] *= -1;
        }


    }
    //to build heap
    z.buildHeap(A, n);
    return;
}

//cmmand from the user
int nextCommand(int* i, int* v, int* f)
{
    char c;
    while (1)
    {
        scanf("%c", &c);
        if (c == ' ' || c == '\t' || c == '\n')
         {
            continue;
        }
        if (c == 'S' || c == 's' || c == 'r' || c == 'R' || c == 'W' || c == 'w')
        {
            break;
        }
        if (c == 'K' || c == 'k')
        {
            c = 'K';
            scanf("%d", f);scanf("%d", i);scanf("%d", v);
            break;
        }
        if (c == 'C' || c == 'c')
        {
            c = 'C';
            scanf("%d", i);
            break;
        }
        if (c == 'I' || c == 'i')
         {
            c = 'I';
            scanf("%d", f);scanf("%d", v);
            break;
        }
        if (c == 'D' || c == 'd')
        {
            c = 'D';
            scanf("%d", f);
            break;
        }
//        printf("Invalid Command\n");
    }
    return c;
}
