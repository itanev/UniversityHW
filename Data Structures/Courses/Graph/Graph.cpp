using std::string;
using std::queue;
using std::vector;
using std::set;

template<class T>
class Graph
{
    vector<Node<T> > Nodes;

    Node<T>& BFS(vector<string>& specialities)
    {
        queue<Node<T> > nodes;
        nodes.push(Nodes.front());
        Nodes.front().visit();
        while(!nodes.empty())
        {
            Node<T> currNode = nodes.front();
            if(contains<string>(specialities, currNode.getVal().specialities)) return currNode;
            vector<Node<T> > currNodeSuccessors = currNode.getSuccessors();
            for(int i = 0; i < currNodeSuccessors.size(); i++)
            {
                nodes.push(currNodeSuccessors[i]);
                currNodeSuccessors[i].visit();
            }

            nodes.pop();
        }

        return NULL;
    }

    Node<T>& BFS(vector<int>& requirements)
    {
        queue<Node<T> > nodes;
        nodes.push(Nodes.front());
        Nodes.front().visit();
        while(!nodes.empty())
        {
            Node<T> currNode = nodes.front();
            if(contains<int>(requirements, currNode.getVal().requirements)) return currNode;

            vector<Node<T> > currNodeSuccessors = currNode.getSuccessors();
            for(int i = 0; i < currNodeSuccessors.size(); i++)
            {
                if(currNodeSuccessors[i].isVisited()) continue;
                nodes.push(currNodeSuccessors[i]);
                currNodeSuccessors[i].visit();
            }

            nodes.pop();
        }

        return NULL;
    }

    Node<T>& BFS(vector<string>& specialities, vector<int>& requirements)
    {
        queue<Node<T> > nodes;
        nodes.push(Nodes.front());
        Nodes.front().visit();
        while(!nodes.empty())
        {
            Node<T> currNode = nodes.front();
            if(contains<int>(specialities, currNode.getVal().specialities) &&
               contains<string>(requirements, currNode.getVal().requirements)) return currNode;

            vector<Node<T> > currNodeSuccessors = currNode.getSuccessors();
            for(int i = 0; i < currNodeSuccessors.size(); i++)
            {
                if(currNodeSuccessors[i].isVisited()) continue;
                nodes.push(currNodeSuccessors[i]);
                currNodeSuccessors[i].visit();
            }

            nodes.pop();
        }

        return NULL;
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

        topologicalSort(successors.front(), sortedNodes);
    }

    void unvisitNodes()
    {
        typename vector<Node<T> >::iterator i;
        for(i = Nodes.begin(); i != Nodes.end(); ++i)
        {
            i->unvisit();
        }
    }

    template<class K>
    bool contains(vector<K>& searched, set<K>& current)
    {
        typename vector<K>::iterator i;
        for(i = searched.begin(); i != searched.end(); ++i)
        {
            if(current.count(*i) <= 0) return false;
        }

        return true;
    }

public:
    Graph() { }

    Graph(vector<Node<T> >& nodes)
    {
        this->Nodes = nodes;
    }

    void addNode(Node<T>& node)
    {
        Nodes.push_back(node);
    }

    Node<T>& findNode(vector<string>& specialities)
    {
        return BFS(specialities);
        unvisitNodes();
    }

    Node<T>& findNode(vector<int>& requirements)
    {
        return BFS(requirements);
        unvisitNodes();
    }

    Node<T>& findNode(vector<string>& specialities, vector<int>& requirements)
    {
        return BFS(specialities, requirements);
        unvisitNodes();
    }

    vector<Node<T> >& topologicalSort()
    {
        vector<Node<T> > sortedNodes;
        topologicalSortUtil(Nodes.front(), sortedNodes);
        return &sortedNodes;
    }
};
