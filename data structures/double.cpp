#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class doublylist
{
    Node *head;
    Node *tail;

public:
    doublylist()
    {
        head = nullptr;
        tail = nullptr;
    }
    void printlist()
    {
        Node *c = head;
        while (c != nullptr)
        {
            cout << c->data << endl;
            c = c->next;
        }
        cout << endl;
    }
    void insertatfront(int val)
    {
        Node *temp = new Node(val);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertatend(int val)
    {
        Node *temp = new Node(val);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }
        temp->prev = tail;

        tail->next = temp;
        tail = temp;
    }
    void deletenode(int val)
    {
        if (head == nullptr)
        {
            cout << "list is empty " << endl;
            return;
        }

        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                if (curr->prev != nullptr)
                {
                    curr->prev->next = curr->next;
                }
                else
                {
                    head = curr->next;
                }
                if (curr->next != nullptr)
                {
                    curr->next->prev = curr->prev;
                }
                else
                {
                    tail = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }
    void reverse() {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    // Swap head and tail
    Node* temp = head;
    head = tail;
    tail = temp;
}
};

int main()
{
    doublylist list1;
    list1.insertatfront(98);
    list1.insertatfront(8);
    list1.insertatfront(9568);
    list1.insertatfront(18);
    list1.insertatend(233);
    list1.insertatend(900);
    list1.insertatend(4500);

    list1.deletenode(4500);

    list1.printlist();

    return 0;
}