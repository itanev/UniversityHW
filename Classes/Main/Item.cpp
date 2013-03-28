#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "../Lib/Item.h"
#include "../Lib/Properties.h"
#include "../Lib/BackPack.h"
#include "../Lib/BackPackProperties.h"

using namespace std;

Item * copySortedItems(Item * sortedItems, int numOfItems)
{
    Item * copyOfSortedItems = new Item[numOfItems];

    for(int i = 0; i < numOfItems; i++)
    {
        copyOfSortedItems[i] = sortedItems[i];
    }

    return copyOfSortedItems;
}

int main()
{
    BackPack p;
    p.read();

    cout << "weight: " << p.getWeight() << endl;

    cout << "best item is: ";
    p.getBestItem().print();

    Item * sortedItems = copySortedItems(p.sortItems(), p.getNumOfItems());

    cout << endl << "First three best items are: " << endl;
    sortedItems[0].print();
    cout << endl;
    sortedItems[1].print();
    cout << endl;
    sortedItems[2].print();
    cout << endl << endl;

    int weight;
    cout << "Enter weight: ";
    cin >> weight;

    //################################################
    //brute force solution
    //the idea is to generate all possible combinations
    //and to select the one with the clossest weight to the entered
    //################################################
    vector<int> sequence;
    vector<int> tempResultSequence;
    vector<int> resultSequence;
    int currSum = 0, maxSum = 0;

    //generates uniq variations
    for(int var = 0; var <= p.getNumOfItems(); var++)
    {
        for (int i = 0; i < p.getNumOfItems(); i++)
        {
            sequence.clear();
            sequence.push_back(i);

            for (int t = i + 1; t < p.getNumOfItems(); t++)
            {
                if (i < t) sequence.push_back(t);

                if (sequence.size() == var)
                {
                    for (int j = 0; j < var; j++)
                    {
                        currSum += sortedItems[sequence[j]].GetWeight();
                        tempResultSequence.push_back(sequence[j]);
                    }
                    sequence.clear();
                    sequence.push_back(i);
                }
            }

            if(currSum > maxSum && currSum <= weight)
            {
                resultSequence.clear();

                for(int si = 0; si < tempResultSequence.size(); si++)
                    resultSequence.push_back(tempResultSequence[si]);

                maxSum = currSum;
            }

            currSum = 0;
            tempResultSequence.clear();
        }
    }

    cout << "max sum: " << maxSum << endl;
    for(int i = 0; i < resultSequence.size(); i++)
    {
        sortedItems[resultSequence[i]].print();
        cout << endl;
    }

    //################################################

    delete[] sortedItems;

    return 0;
}
