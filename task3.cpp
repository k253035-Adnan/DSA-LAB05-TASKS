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

class Queue {
    int front, rear;
    int a[MAX];

public:
    Queue() { front = -1; rear = -1; }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        a[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int x = a[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return x;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        return (rear - front + MAX) % MAX + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << "J" << a[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

void reverseFirstK(Queue &q, int k) {
    if (k <= 0 || k > q.size()) {
        cout << "Invalid value of K" << endl;
        return;
    }

    Stack s;

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;

    for (int i = 1; i <= 7; i++) {
        q.enqueue(i);
    }

    cout << "Queue before: ";
    q.display();

    reverseFirstK(q, 3);

    cout << "Queue after reversing first 3: ";
    q.display();

    return 0;
}
