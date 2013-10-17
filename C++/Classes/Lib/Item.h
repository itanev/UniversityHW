#ifndef m;
#define m;

class Item
{
    private:
        int power;
        int weight;
        char * name;
    public:
        Item()
        {
            name = new char[256];
        }

        void SetPower(int p);
        void SetWeight(int w);
        void SetName(char * n);

        int GetPower();
        int GetWeight();
        char * GetName();

        void read();
        void print();
};

#endif;
