#include <cstdlib>
#include <stdio.h>

template <class T>
class Array {
    private:
        T *_baseAddress;
        int _size;

        T *getAddress(int index) {
            return _baseAddress + index;
        }

    public:
        Array(int size) {
            _baseAddress = (T*) malloc(size * sizeof(T));
            _size = size;
        }

        void set(int index, T value) {
            T *addr = getAddress(index);
            *addr = value;
        }

        T get(int index) {
            return *getAddress(index);
        }
};

int main() {
    Array<int> arr = Array<int>(4);
    arr.set(0, 9);
    arr.set(1, 3);
    int x = arr.get(1);
    printf("%d\n", x);
}
