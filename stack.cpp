#include <iostream>
#define SIZE 100
using namespace std;


int stack[SIZE];
int top = -1;

void push(int value) {
    if (top >= SIZE - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    top++;
    stack[top] = value;
    cout << value << " pushed to stack." << endl;
}

int pop() {
    if (top < 0) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    int popped = stack[top];
    top--;
    return popped;
}

int peek() {
    if (top < 0) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return stack[top];
}

bool isEmpty() {
    return top == -1;
}

void display() {
    if (top < 0) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}


int main() {
    int n, val;
    cout << "How many elements ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        push(val);
    }

    display();
    cout << "Top element: " << peek() << endl;
    cout << "Popped element: " << pop() << endl;
    display();

    return 0;
}
