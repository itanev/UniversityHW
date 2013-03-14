#include <iostream>

using namespace std;

int main()
{
    const int length = 100;
    int arr[length] = { 6,7,3,9,4,1,2,0,3,8,11,16,
                        17,19,31,14,18,21,22,20,6,
                        7,3,9,4,1,2,0,3,8,11,16,17,
                        19,31,14,18,21,22,20,6,7,3,
                        9,4,1,2,0,3,8,11,16,17,19,31,
                        14,18,21,22,20,6,7,3,9,4,1,2,
                        0,3,8,11,16,17,19,31,14,18,21,
                        22,20,6,7,3,9,4,1,2,0,3,8,11,
                        16,17,19,31,14,18,21,22,20 };

    int arr2[length];
    bool ins = false;

    arr2[0] = arr[0];

    for(int curr = 1; curr < length; curr++)
    {
        ins = false;

        for(int index = curr-1; index >= 0; index--)
        {
            if(arr2[index] > arr[curr])
            {
                arr2[index+1] = arr2[index];
                arr2[index] = arr[curr];
                ins = true;
            }
        }

        if(!ins)
        {
            arr2[curr] = arr[curr];
        }
    }

    for(int i = 0; i < length; i++)
    {
        cout << arr2[i] << endl;
    }

    return 0;
}
