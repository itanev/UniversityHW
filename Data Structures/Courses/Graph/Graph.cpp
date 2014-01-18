using std::string;
using std::stack;
using std::vector;
using std::set;
using std::cout;

template<class T>
class Graph
{
    vector<Node<T> > Nodes;

    bool contains(vector<int> collection, int item)
    {
        typename vector<int>::iterator i;
        for(i = collection.begin(); i != collection.end(); ++i)
        {
            if(*i == item) return true;
        }

        return false;
    }

    bool contains(vector<int> biggerCollection, vector<int> smallerCollection)
    {
        if(biggerCollection.size() == 1 && biggerCollection.front() == 0) return true;

        typename vector<int>::iterator i;
        for(i = smallerCollection.begin(); i != smallerCollection.end(); ++i)
        {
            if(!contains(biggerCollection, *i)) return false;
        }

        return true;
    }

    void ConnectNode(Node<T>& newNode)
    {
        typename vector<Node<T> >::iterator i;
        for(i = Nodes.begin(); i != Nodes.end(); ++i)
        {
            if(contains(newNode.getVal().takenCourses, i->getVal().id))
            {
                i->addSuccessor(newNode);
            }

            if(contains(i->getVal().takenCourses, newNode.getVal().id))
            {
                newNode.addSuccessor(*i);
            }
        }
    }

    vector<Node<T> > topologicalSortUtil()
    {
        stack<Node<T> > nodes;
        vector<Node<T> > sortedNodes;
        bool * visited = new bool[Nodes.size()];
        typename vector<Node<T> >::iterator i = Nodes.begin();
        nodes.push(*i);
        visited[i->getVal().id - 1] = true;
        sortedNodes.push_back(*i);
        Node<T> currNode = nodes.top();
        while(!nodes.empty())
        {
            vector<Node<T> > currNodeSuccessors = currNode.getSuccessors();
            if(currNodeSuccessors.size() == 0)
            {
                if(visited[currNode.getVal().id - 1])
                {
                    if(sortedNodes.size() == Nodes.size()) break;
                    i++;
                    nodes.push(*i);
                }
                else
                {
                    visited[currNode.getVal().id - 1] = true;
                    nodes.push(currNode);
                    sortedNodes.push_back(currNode);
                }
            }
            else
            {
                for(int k = 0; k < currNodeSuccessors.size(); k++)
                {
                    if(visited[currNodeSuccessors[k].getVal().id - 1]) continue;
                    nodes.push(currNodeSuccessors[k]);
                    sortedNodes.push_back(currNodeSuccessors[k]);
                    visited[currNodeSuccessors[k].getVal().id - 1] = true;
                }
            }

            if(!nodes.empty())
                currNode = nodes.top();

            nodes.pop();
        }

        return sortedNodes;
    }

public:
    Graph() { }

    Graph(vector<Node<T> >& nodes)
    {
        this->Nodes = nodes;
    }

    bool empty()
    {
        return Nodes.size() == 0;
    }

    void addNode(Node<T>& node)
    {
        if(!empty()) ConnectNode(node);
        Nodes.push_back(node);
    }

    vector<Node<T> > topologicalSort()
    {
        return topologicalSortUtil();
    }

    vector<Node<T> >& getNodes()
    {
        return Nodes;
    }

    vector<Course> findBy(int course, vector<int> passedCourses, bool onlyChoosable = false)
    {
        vector<Course> availableCourses;
        stack<Node<T> > nodes;
        bool * visited = new bool[Nodes.size()];
        typename vector<Node<T> >::iterator i = Nodes.begin();
        nodes.push(*i);
        visited[i->getVal().id - 1] = true;
        Node<T> currCourse = nodes.top();
        int cnt = 1;
        while(!nodes.empty() && cnt < Nodes.size())
        {
            cnt++;
            currCourse.getVal().printCourse();
            if(currCourse.getVal().course == course &&
               contains(currCourse.getVal().takenCourses, passedCourses))
            {
                if(onlyChoosable)
                {
                    if(!currCourse.getVal().mandatory)
                        availableCourses.push_back(currCourse.getVal());
                }
                else
                {
                    availableCourses.push_back(currCourse.getVal());
                }
            }

            vector<Node<T> > currNodeSuccessors = currCourse.getSuccessors();
            if(currNodeSuccessors.size() == 0)
            {
                if(visited[currCourse.getVal().id - 1])
                {
                    i++;
                    nodes.push(*i);
                }
                else
                {
                    visited[currCourse.getVal().id - 1] = true;
                    nodes.push(currCourse);
                }
            }
            else
            {
                for(int k = 0; k < currNodeSuccessors.size(); k++)
                {
                    if(visited[currNodeSuccessors[k].getVal().id - 1]) continue;
                    nodes.push(currNodeSuccessors[k]);
                    visited[currNodeSuccessors[k].getVal().id - 1] = true;
                }
            }

            if(!nodes.empty())
                currCourse = nodes.top();

            nodes.pop();
        }

        return availableCourses;
    }

    void printGraph()
    {
        typename vector<Node<T> >::iterator i;
        typename vector<Node<T> >::iterator k;
        for(i = Nodes.begin(); i != Nodes.end(); ++i)
        {
            cout << i->getVal().id << " - ";
            for(k = i->getSuccessors().begin(); k != i->getSuccessors().end(); k++)
            {
                cout << k->getVal().id << ", ";
            }

            cout << std::endl;
        }
    }
};
