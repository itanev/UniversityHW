using std::vector;

template<class T>
class Node
{
    T * val;
    vector<Node> successors;
    bool visited = false;
public:
    Node(T * val)
    {
        this->val = val;
    }

    Node(T * val, vector<Node>& successors)
    {
        this->val = val;
        this->successors = successors;
    }

    T& getVal()
    {
        return val;
    }

    void addSuccessor(Node successor)
    {
        successors.push_back(successor);
    }

    void removeTopSuccessor()
    {
        successors.erase(successors.begin());
    }

    vector<Node>& getSuccessors()
    {
        return successors;
    }

    bool isVisited()
    {
        return visited;
    }

    void visit()
    {
        visited = true;
    }

    void unvisit()
    {
        visited = false;
    }
};
