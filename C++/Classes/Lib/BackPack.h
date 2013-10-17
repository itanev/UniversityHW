#ifndef k;
#define k;

class BackPack
{
    private:
        const static int numItems = 4;
        Item content[numItems];
    public:
        BackPack()
        {
        }

        void read();
        void print();
        long getWeight();
        int getNumOfItems();
        Item getBestItem();
        Item * sortItems();
};

#endif;
