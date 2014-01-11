using std::string;
using std::queue;
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

    void topologicalSortUtil(Node<T>& node, vector<Node<T> > &sortedNodes)
    {
        if(sortedNodes.size() == Nodes.size()) return;
        typename vector<Node<T> >::iterator i;
        node.visit();
        vector<Node<T> > successors = node.getSuccessors();
        for(i = successors.begin(); i != successors.end(); ++i)
        {
            if(i->isVisited()) continue;
            i->visit();
            sortedNodes.push_back(*i);
        }
        //TODO: fix
        topologicalSortUtil(successors.front(), sortedNodes);
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
        vector<Node<T> > sortedNodes;
        topologicalSortUtil(Nodes.front(), sortedNodes);
        return sortedNodes;
    }
};
