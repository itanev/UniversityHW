#include <iostream>

using namespace std;

void print(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void fill(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = (i+1)*5;
    }
}

int main()
{
    int * first = new int[5];
    fill(first, 4);

    for(int i = 4; i >= 0; i--)
    {
        swap(first[i], first[i+1]);
    }

    print(first, 5);
    return 0;
}
