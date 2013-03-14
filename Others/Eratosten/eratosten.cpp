#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    const int length = 1000;

    bool a[length];

    for(int i = 0; i < length; i++) a[i] = 1;

    for(int i=2; i < (int)sqrt(length); i++)
    {
        if(a[i] == 1)
        {
            for(int j=2*i; j < length; j++)
            {
                if(j%i == 0) a[j] = 0;
            }
        }
    }

    for(int i=2; i < length; i++)
    {
        if(a[i] == 1) cout<<i<<" ";
    }
    return 0;
}
