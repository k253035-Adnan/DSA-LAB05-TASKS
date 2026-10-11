#include <iostream>
using namespace std;

#define MAX 10

class Stack {
    int top;
    int a[MAX];

public:
    Stack() { top = -1; }

    bool isFull() {
        return top >= MAX - 1;
    }

    bool isEmpty() {
        return top < 0;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top = top + 1;
        a[top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int x = a[top];
        top = top - 1;
        return x;
    }
};

class MyQueue {
    Stack incoming;
    Stack outgoing;

public:
    void enqueue(int item) {
        incoming.push(item);
    }

    int dequeue() {
        if (outgoing.isEmpty()) {
            while (!incoming.isEmpty()) {
                outgoing.push(incoming.pop());
            }
        }
        if (outgoing.isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return outgoing.pop();
    }
};

int main() {
    cout << "Items 1, 2, 3 stand for A, B, C" << endl;
    MyQueue q;

    q.enqueue(1);
    q.enqueue(2);
    cout << "Dequeued: " << q.dequeue() << endl;
    q.enqueue(3);
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}
