#ifndef q;
#define q;

void BackPack::read()
{
    for(int i = 0; i < numItems; i++)
    {
        content[i].read();
    }
}

void BackPack::print()
{
    cout << "number of items - " << numItems << endl;

    for(int i = 0; i < numItems; i++)
    {
        content[i].print();
        cout << endl;
    }
}

long BackPack::getWeight()
{
    long weight = 0;

    for(int i = 0; i < numItems; i++)
    {
        weight += content[i].GetWeight();
    }

    return weight;
}

int BackPack::getNumOfItems()
{
    return numItems;
}

Item BackPack::getBestItem()
{
    Item bestItem = content[0];

    for(int i = 1; i < numItems; i++)
    {
        if( (content[i].GetPower() * content[i].GetPower() / content[i].GetWeight()) >
            (bestItem.GetPower() * bestItem.GetPower() / bestItem.GetWeight()) )
        {
            bestItem = content[i];
        }
    }

    return bestItem;
}

Item * BackPack::sortItems()
{
    Item * sortedItems = new Item[numItems];

    for(int i = 0; i < numItems; i++)
    {
        sortedItems[i] = content[i];
    }

    for(int i = 0; i < numItems; i++)
    {
        for(int j = i; j < numItems; j++)
        {
            if( (sortedItems[i].GetPower() * sortedItems[i].GetPower() / sortedItems[i].GetWeight()) <
                (sortedItems[j].GetPower() * sortedItems[j].GetPower() / sortedItems[j].GetWeight()) )
            {
                swap(sortedItems[i], sortedItems[j]);
            }
        }
    }

    return sortedItems;
}

#endif;
