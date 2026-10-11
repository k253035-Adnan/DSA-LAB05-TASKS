#include <iostream>
using namespace std;

#define MAX 20

class Stack {
    int top;
    string a[MAX];

public:
    Stack() { top = -1; }

    bool isFull() {
        return top >= MAX - 1;
    }

    bool isEmpty() {
        return top < 0;
    }

    void push(string x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top = top + 1;
        a[top] = x;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        string x = a[top];
        top = top - 1;
        return x;
    }

    void clear() {
        top = -1;
    }

    void showFromBottom() {
        for (int i = 0; i <= top; i++) {
            cout << a[i];
            if (i < top) {
                cout << " ";
            }
        }
    }
};

class TextEditor {
    Stack undoStack;
    Stack redoStack;

public:
    void type(string word) {
        undoStack.push(word);
        redoStack.clear();
    }

    void undo() {
        if (undoStack.isEmpty()) {
            return;
        }
        string word = undoStack.pop();
        redoStack.push(word);
    }

    void redo() {
        if (redoStack.isEmpty()) {
            return;
        }
        string word = redoStack.pop();
        undoStack.push(word);
    }

    void print() {
        cout << "Document: ";
        undoStack.showFromBottom();
        cout << endl;
    }
};

int main() {
    TextEditor editor;

    cout << "type Hello" << endl;
    editor.type("Hello");
    editor.print();

    cout << "type World" << endl;
    editor.type("World");
    editor.print();

    cout << "undo" << endl;
    editor.undo();
    editor.print();

    cout << "redo" << endl;
    editor.redo();
    editor.print();

    cout << "undo" << endl;
    editor.undo();
    editor.print();

    cout << "type There" << endl;
    editor.type("There");
    editor.print();

    cout << "redo" << endl;
    editor.redo();
    editor.print();

    return 0;
}
