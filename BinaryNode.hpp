#ifndef BINARY_NODE
#define BINARY_NODE

template <class S, class T>
class BinaryNode {
    private:
        S _key;
        T _data;
        BinaryNode *_left;
        BinaryNode *_right;

    public:
        BinaryNode(S key, T data) : _key(key), _data(data), _left(nullptr), _right(nullptr) {}

        BinaryNode *getKey() {
            return _key;
        }

        void setData(T data) {
            _data = data;
        }

        BinaryNode *getData() {
            return _data;
        }

        void setLeft(BinaryNode *left) {
            _left = left;
        }

        BinaryNode *getLeft() {
            return _left;
        }

        void setRight(BinaryNode *right) {
            _right = right;
        }

        BinaryNode *getRight() {
            return _right;
        }
};

#endif
