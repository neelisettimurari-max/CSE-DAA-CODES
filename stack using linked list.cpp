#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

void push(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    cout << value << " pushed into stack." << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow!" << endl;
        return;
    }

    Node *temp = top;

    cout << top->data << " popped from stack." << endl;

    top = top->next;

    delete temp;
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Top element = " << top->data << endl;
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    Node *temp = top;

    cout << "Stack: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    while (true)
    {
        cout << "\n--- STACK ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}