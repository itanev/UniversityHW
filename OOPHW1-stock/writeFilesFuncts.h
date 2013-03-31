#ifndef writeToFiles
#define writeToFiles

template<typename T>
void writeData(vector<T>& dataHolder, ofstream& file)
{
    if(file.is_open() && file.good())
    {
        for(int i = 0; i < dataHolder.size(); i++)
        {
            file.seekp(0, ios::cur);
            file.write((char*)&dataHolder[i], sizeof(T));
        }
    }
    else cout << "File can't be opened!";

    file.close();
}

#endif // write
