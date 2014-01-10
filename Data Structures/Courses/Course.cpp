using std::string;
using std::vector;

struct Course
{
    int id;
    string name;
    bool mandatory;
    vector<string> specialities;
    int course;
    int estk;
    vector<int> takenCourses;
};
