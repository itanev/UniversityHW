using std::string;
using std::queue;
using std::stack;
using std::vector;
using std::set;

template<class T>
class Graph
{
    vector<Node<T> > Nodes;

    void ConnectNode(Node<T> newNode)
    {
        if(empty()) return;
        queue<Node<T> > nodes;
        nodes.push(Nodes.front());
        Nodes.front().visit();
        Node<T> currNode = nodes.front();
        while(!nodes.empty())
        {
            if(std::count(newNode.getVal().takenCourses.begin(),
                          newNode.getVal().takenCourses.end(),
                          currNode.getVal().id) > 0)
            {
                currNode.addSuccessor(newNode);
            }

            if(std::count(currNode.getVal().takenCourses.begin(),
                         currNode.getVal().takenCourses.end(),
                         newNode.getVal().id) > 0)
            {
                newNode.addSuccessor(currNode);
            }

            vector<Node<T> > currNodeSuccessors = currNode.getSuccessors();
            for(int i = 0; i < currNodeSuccessors.size(); i++)
            {
                if(currNodeSuccessors[i].isVisited()) continue;
                nodes.push(currNodeSuccessors[i]);
                currNodeSuccessors[i].visit();
            }

            nodes.pop();
            if(!nodes.empty())
                currNode = nodes.front();
        }
    }

    vector<Node<T> >& topologicalSortUtil()
    {
        stack<Node<T> > nodes;
        vector<Node<T> > sortedNodes;
        typename vector<Node<T> >::iterator i = Nodes.begin();
        nodes.push(*i);
        i->visit();
        Node<T> currNode = nodes.top();
        while(!nodes.empty())
        {
            vector<Node<T> > currNodeSuccessors = currNode.getSuccessors();
            if(currNodeSuccessors.size() == 0)
            {
                if(!currNode.isVisited())
                {
                    sortedNodes.push_back(currNode);
                    currNode.visit();
                }
                else i++;
            }
            else
            {
                for(int i = 0; i < currNodeSuccessors.size(); i++)
                {
                    if(currNodeSuccessors[i].isVisited()) continue;
                    nodes.push(currNodeSuccessors[i]);
                    sortedNodes.push_back(currNodeSuccessors[i]);
                    currNodeSuccessors[i].visit();
                }
            }

            nodes.pop();
            if(!nodes.empty())
                currNode = nodes.top();
        }

        return sortedNodes;
    }

    void unvisitNodes()
    {
        typename vector<Node<T> >::iterator i;
        for(i = Nodes.begin(); i != Nodes.end(); ++i)
        {
            i->unvisit();
        }
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
        ConnectNode(node);
        Nodes.push_back(node);
        unvisitNodes();
    }

    vector<Node<T> >& topologicalSort()
    {
        return topologicalSortUtil();
    }
};
