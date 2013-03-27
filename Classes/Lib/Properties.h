using namespace std;

#ifndef a
#define a

//Getters
char * Item::GetName()
{
    return name;
}

int Item::GetPower()
{
    return this->power;
}

int Item::GetWeight()
{
    return this->weight;
}

//Setters
void Item::SetName(char * n)
{
    strcpy(name, n);
}

void Item::SetPower(int p)
{
    this->power = p;
}

void Item::SetWeight(int w)
{
    this->weight = w;
}

//read
void Item::read()
{
    int w,p;
    string n;

    cout << "Enter weight: ";
    cin >> w;
    SetWeight(w);

    cout << "Enter power: ";
    cin >> p;
    SetPower(p);

    cout << "Enter name: ";
    cin.ignore(1000, '\n'); //bug fixer
    getline(cin, n);
    SetName((char*)n.c_str());
    cout << "###############" << endl;
}

//print
void Item::print()
{
    cout << "weight - " << GetWeight() << ' ';
    cout << "power - " << GetPower() << ' ';
    cout << "name - " << GetName() << ' ';
}

#endif;
