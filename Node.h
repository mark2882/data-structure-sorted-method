#if !defined(___class_Node)
#define ___class_Node

template<typename T>
class Node
{
    public:
        Node(T v)
        {
            value = v;
            previous = 0;
            next = 0;
        }
        ~Node()
        {
            if(previous != next)
                delete previous;
            delete next;
        }
        Node<T>* previous;
        Node<T>* next;
        T value;
    protected:
    private:
};

#endif
