using std::cout;
using std::cin;
using std::endl;

class Student
{
    Graph<Course> graph;
    int facultyNumber;
    int course;
    vector<int> passedCourses;
    string name;

    void readPassedCourses()
    {
        cout << "Enter passed courses ids." << endl;
        cout << "Press some letter to stop." << endl;
        string currSymbol;
        int courseId;

        cout << "Course id - ";
        cin.ignore(1000, '\n');
        getline(cin, currSymbol);

        while(courseId = atoi(currSymbol.c_str()))
        {
            passedCourses.push_back(courseId);
            cout << "Course id - ";
            getline(cin, currSymbol);
        }
    }

    void getStudentInfo()
    {
        cout << "Name - ";
        getline(cin, name);
        cout << "Faculty number - ";
        cin >> facultyNumber;
        cout << "Course - ";
        cin >> course;
        readPassedCourses();
    }

    Course getCourseWithMaxEstk(vector<Course>& courses)
    {
        typename vector<Course>::iterator i = courses.begin();
        typename vector<Course>::iterator maxEstkCourse = i;
        ++i;
        while(i != courses.end())
        {
            if(i->estk > maxEstkCourse->estk)
            {
                maxEstkCourse = i;
            }

            ++i;
        }

        courses.erase(maxEstkCourse);
        return *maxEstkCourse;
    }

    public:
    Student(Graph<Course>& graph)
    {
        this->graph = graph;
        getStudentInfo();
    }

    void printAvailableCourses()
    {
        vector<Course> availableCourses = graph.findBy(course, passedCourses);
        typename vector<Course>::iterator i;
        for(i = availableCourses.begin(); i != availableCourses.end(); ++i)
        {
            i->printCourse();
        }
    }

    void printBestOptionForCourses(int minNum)
    {
        vector<Course> availableNotMandatoryCourses = graph.findBy(course, passedCourses, true);
        if(availableNotMandatoryCourses.size() > 0)
        {
            for(int i = 0; i < minNum; ++i)
            {
                getCourseWithMaxEstk(availableNotMandatoryCourses).printCourse();
            }
        }
        else cout << "No available courses.";
    }
};
