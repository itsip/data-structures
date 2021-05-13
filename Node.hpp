#ifndef NODE
#define NODE

template <class T>
class Node {
    private:
        T _data;
        Node *_next;

    public:
        Node(T data) : _data(data), _next(nullptr) {}

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
