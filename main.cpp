#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int arr[5];
public:
    Stack() {
        top = -1;
        for(int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == 4);
    }

    void push(int val) {
        if(isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;
        } else {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count() {
        return (top + 1);
    }

    int peek(int pos) {
        if(pos < 0 || pos > top) {
            cout << "Invalid position" << endl;
            return -1;
        }
        return arr[pos];
    }

    void change(int pos, int val) {
        if(pos < 0 || pos > top) {
            cout << "Invalid position" << endl;
            return;
        }
        arr[pos] = val;
        cout << "All values in the stack are:" << endl;
        for(int i = 4; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    void display() {  
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are:" << endl;
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s1;
    int option, position, value;

    do {
        cout << "What operation do you want to perform? Select option number. Enter 0 to exit" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. clear screen" << endl << endl;

        cin >> option;
        switch(option) {
            case 1:
                cout << "Enter an item to push in the stack: ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                cout << "Pop function called - Popped value: " << s1.pop() << endl;
                break;
            case 3:
                if(s1.isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;
            case 4:
                if(s1.isFull())
                    cout << "Stack is full" << endl;
                else
                    cout << "Stack is not full" << endl;
                break;
            case 5:
                cout << "Enter the position of item you want to peek: ";
                cin >> position;
                cout << "Peek function called - Value at position " << position
                     << " is " << s1.peek(position) << endl;
                break;
            case 6:
                cout << "Count function called - Number of items in the stack: "
                     << s1.count() << endl;
                break;
            case 7:
                cout << "Change function called" << endl;
                cout << "Enter the position of item you want to change: ";
                cin >> position;
                cout << "Enter the value you want to change to: ";
                cin >> value;
                s1.change(position, value);
                break;
            case 8:
                cout << "Display function called" << endl;
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout << "Enter proper option number" << endl;
        }
    } while(option != 0);

    return 0;
}
