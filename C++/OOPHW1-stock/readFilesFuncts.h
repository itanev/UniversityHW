#ifndef readFiles
#define readFiles

using namespace std;

template<typename T>
void readData(vector<T>& dataHolder, ifstream& file)
{
    if(file.is_open())
    {
        while(file.good())
        {
            T tempDataHolder;
            file.seekg(0, ios::cur);
            file.read((char*)&tempDataHolder, sizeof(T));

            dataHolder.push_back(tempDataHolder);
        }

        dataHolder.pop_back();   //delete last entry, because it has been read twice
    }
    else cout << "File can't be opened!";

    file.close();
}

#endif // readFiles
