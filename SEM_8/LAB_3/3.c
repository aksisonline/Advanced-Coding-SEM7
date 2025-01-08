#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

bool myCircularDequeIsFull(MyCircularDeque* obj);
bool myCircularDequeIsEmpty(MyCircularDeque* obj);

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* deque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    deque->data = (int*)malloc(k * sizeof(int));
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
    deque->capacity = k;
    return deque;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->data[obj->front] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->data[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->data[(obj->rear - 1 + obj->capacity) % obj->capacity];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}

int main() {
    MyCircularDeque* deque = myCircularDequeCreate(3); // Set the size to be 3

    myCircularDequeInsertLast(deque, 1); // return true
    myCircularDequeInsertLast(deque, 2); // return true
    myCircularDequeInsertFront(deque, 3); // return true
    myCircularDequeInsertFront(deque, 4); // return false, the queue is full

    int rear = myCircularDequeGetRear(deque); // return 2
    printf("Rear element: %d\n", rear);

    bool isFull = myCircularDequeIsFull(deque); // return true
    printf("Is full: %s\n", isFull? "true": "false");

    myCircularDequeDeleteLast(deque); // return true

    myCircularDequeInsertFront(deque, 4); // return true

    int front = myCircularDequeGetFront(deque); // return 4
    printf("Front element: %d\n", front);

    myCircularDequeFree(deque);

    return 0;
}