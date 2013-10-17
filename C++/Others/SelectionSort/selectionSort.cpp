#include <iostream>

using namespace std;

int main()
{
    const int length = 20;
    int arr[length] = {6,7,3,9,4,1,2,0,3,8,11,16,17,19,31,14,18,21,22,20};
    int tempMax = arr[0], index = 0;

    for(int curr = 0; curr < length; curr++)
    {
        tempMax = 0;
        for(int i = curr; i < length; i++)
        {
            if(arr[i] > tempMax)
            {
                tempMax = arr[i];
                index = i;
            }
        }

        swap(arr[curr], arr[index]);
    }

    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
