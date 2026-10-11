#include <iostream>
using namespace std;

#define MAX 6

class CircularQueue {
    int front, rear;
    int a[MAX];

public:
    CircularQueue() { front = -1; rear = -1; }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue Overflow! Passenger " << x << " cannot enter" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        a[rear] = x;
        cout << "Passenger " << x << " entered the queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow!" << endl;
            return -1;
        }
        int x = a[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        cout << "Passenger " << x << " boarded" << endl;
        return x;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Passengers in boarding order: ";
        int i = front;
        while (true) {
            cout << a[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
        cout << "Front position: " << front << endl;
        cout << "Rear position: " << rear << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    q.dequeue();
    q.dequeue();

    q.enqueue(110);

    q.dequeue();

    q.enqueue(111);
    q.enqueue(112);

    cout << endl;
    q.display();

    return 0;
}
