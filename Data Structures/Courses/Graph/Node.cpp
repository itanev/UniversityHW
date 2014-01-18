using std::vector;

template<class T>
class Node
{
    T val;
    vector<Node<T> > successors;
public:
    Node(T& val)
    {
        this->val = val;
    }

    T& getVal()
    {
        return val;
    }

    void addSuccessor(Node<T>& successor)
    {
        successors.push_back(successor);
    }

    vector<Node<T> >& getSuccessors()
    {
        return successors;
    }
};
