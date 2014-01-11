#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include "Course.cpp"
#include "Graph/Node.cpp"
#include "Graph/Graph.cpp"

using namespace std;

vector<string> split(string str, string delim)
{
      unsigned start = 0;
      unsigned end;
      vector<string> v;

      while( (end = str.find(delim, start)) != string::npos )
      {
            v.push_back(str.substr(start, end-start));
            start = end + delim.length();
      }
      v.push_back(str.substr(start));
      return v;
}

Course getCourse(vector<string>& parts)
{
    Course currCourse;
    for(int i = 0; i < parts.size(); i++)
    {
        string part = parts[i];
        switch(i + 1)
        {
            case 1:
                {
                    vector<string> subParts = split(part, "\t");
                    currCourse.id = atoi(subParts[0].c_str());
                    currCourse.name = subParts[1];
                    currCourse.mandatory = subParts[2] == "z";
                }
            break;
            case 2:
                currCourse.specialities = split(part, ", ");
            break;
            case 3:
                currCourse.course = atoi(part.c_str());
            break;
            case 4:
                currCourse.estk = atoi(part.c_str());
            break;
            case 5:
                vector<string> subParts = split(part, ", ");
                for(int p = 0; p < subParts.size(); p++)
                {
                    currCourse.takenCourses.push_back(atoi(subParts[p].c_str()));
                }
            break;
        }
    }

    return currCourse;
}

int main()
{
    vector<Course> courses;
    Graph<Course> graph;
    ifstream input("courses.txt");

    if(input.is_open())
    {
        while(!input.eof())
        {
            string currCourse;
            getline(input, currCourse);
            vector<string> parts = split(currCourse, "|");
            Course course = getCourse(parts);
            Node<Course> node(&course);
            graph.addNode(node);
        }

        cout << graph.topologicalSort().front().getVal().id;
    }

    input.close();
    return 0;
}
