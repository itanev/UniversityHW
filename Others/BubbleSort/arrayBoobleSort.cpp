#include <iostream>

using namespace std;

int main()
{
    int arrLength = 9;
    int arr[] = {1,32,2,6,2,87,34,323,7};
    int next = 0;

    for(int count = 0; count < arrLength; count++)
    {
        for(int curr = count; curr < arrLength; curr++)
        {
            next = curr + 1;
            if(arr[curr] > arr[next] && next < arrLength)
            {
                swap(arr[curr], arr[next]);
            }
        }
    }

    for(int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
