#ifndef DOUBLE_NODE
#define DOUBLE_NODE

template <class T>
class DoubleNode {
    private:
        DoubleNode *_prev;
        T _data;
        DoubleNode *_next;

    public:
        DoubleNode(T data) : _prev(nullptr), _data(data), _next(nullptr) {}

        void setPrev(DoubleNode *prev) {
            _prev = prev;
        }

        DoubleNode *getPrev() {
            return _prev;
        }

        void setNext(DoubleNode *next) {
            _next = next;
        }

        DoubleNode *getNext() {
            return _next;
        }

        T getData() {
            return _data;
        }
};

#endif
