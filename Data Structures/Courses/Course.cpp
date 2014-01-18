using std::string;
using std::vector;
using std::cout;
using std::endl;

struct Course
{
    int id;
    string name;
    bool mandatory;
    vector<string> specialities;
    int course;
    int estk;
    vector<int> takenCourses;

    void printCourse()
    {
        cout << id << ". " << name << (mandatory ? " mandatory " : " not mandatory ") << endl;
        cout << "For specialities: ";
        printCollection<string>(specialities);
        cout << "For course: " << course << endl;
        cout << "Credits: " << estk << endl;
        cout << "Courses that need to be taken: ";
        printCollection<int>(takenCourses);
        cout << endl;
    }

    template<class T>
    void printCollection(vector<T> collection)
    {
        typename vector<T>::iterator i;
        for(i = collection.begin(); i != collection.end(); ++i)
        {
            cout << *i << "; ";
        }
        cout << endl;
    }
};
