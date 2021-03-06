#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *head;

    Stack()
    {
        head = NULL;
    }

    void print()
    {
        Node *current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    bool empty()
    {
        if (head != NULL)
            return false;
        return true;
    }

    size_t size()
    {
        size_t len = 0;
        Node *current = head;
        while (current != NULL) {
            len++;
            current = current->next;
        }
        return len;
    }

    void push(int data)
    {
        Node *new_element = new Node;
        new_element->data = data;
        new_element->next = head;
        head = new_element;
    }

    void pop()
    {
        if (empty())
            return;  // error

        Node *old_head = head;
        head = old_head->next;
        free(old_head);
    }

    int top()
    {
        if (empty())
            return INT_MIN;
        return head->data;
    }
};

