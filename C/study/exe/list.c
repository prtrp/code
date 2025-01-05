#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int *arr;
    int size;
    int capacity;
} list;

int main() {
        
};

list append(list a, int value) {
    if(a.size == a.capacity) {
        a.capacity = a.capacity == 0 ? 2 : a.capacity*2;
        a.arr = malloc(sizeof(int)*a.capacity);
        a.arr[size] = value;
        a.size++;
    }
    return a;
}

