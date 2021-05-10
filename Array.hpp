#ifndef ARRAY
#define ARRAY
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

#endif
