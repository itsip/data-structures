#ifndef NODE
#define NODE

template <class T>
class Node {
    protected:
        T _data;
        Node *_next;

    public:
        Node(T data) : _next(nullptr), _data(data) {}

        void setNext(Node *next) {
            _next = next;
        }

        Node *getNext() {
            return _next;
        }

        T getData() {
            return _data;
        }
};

#endif
