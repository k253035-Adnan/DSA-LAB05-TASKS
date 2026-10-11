#include <iostream>
using namespace std;

#define MAX 8

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
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        top = top + 1;
        a[top] = x;
    }

    void undo() {
        if (isEmpty()) {
            cout << "Undo failed, stack is empty" << endl;
            return;
        }
        cout << "Undo removed operation " << a[top] << endl;
        top = top - 1;
    }

    void showTop() {
        if (isEmpty()) {
            cout << "Current top operation: none" << endl;
        } else {
            cout << "Current top operation: " << a[top] << endl;
        }
    }

    void showAll() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i = i - 1) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(12);
    cout << "Operation 12 done" << endl;
    s.showTop();

    s.push(25);
    cout << "Operation 25 done" << endl;
    s.showTop();

    s.push(17);
    cout << "Operation 17 done" << endl;
    s.showTop();

    s.push(31);
    cout << "Operation 31 done" << endl;
    s.showTop();

    s.push(44);
    cout << "Operation 44 done" << endl;
    s.showTop();

    s.push(19);
    cout << "Operation 19 done" << endl;
    s.showTop();

    cout << endl << "Undo three times" << endl;
    s.undo();
    s.showTop();
    s.undo();
    s.showTop();
    s.undo();
    s.showTop();

    cout << endl << "New operation 52" << endl;
    s.push(52);
    cout << "Operation 52 done" << endl;
    s.showTop();

    cout << endl << "Undo twice" << endl;
    s.undo();
    s.showTop();
    s.undo();
    s.showTop();

    cout << endl << "Remaining operations from top to bottom: ";
    s.showAll();

    cout << endl << "Undo on an empty stack" << endl;
    s.undo();
    s.undo();
    s.undo();
    s.showTop();

    return 0;
}
