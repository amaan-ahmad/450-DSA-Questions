#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void addNode(int val)
    {

        Node *tmp = new Node();
        tmp->data = val;
        tmp->next = head;
        head = tmp;
    }

    void display()
    {
        Node *tmp = head;

        while (tmp != NULL)
        {
            if (tmp->next == NULL)
                cout << tmp->data << endl;
            else
                cout << tmp->data << " -> ";

            tmp = tmp->next;
        }
    }

    Node *reverse(Node *tmp)
    {
        // base case if linkedlist is empty;
        if (tmp == NULL || tmp->next == NULL)
        {
            return tmp;
        }

        // have faith that "rest" will contain reversed list
        Node *rest = reverse(tmp->next);

        // pointing the reversed part to first one.
        tmp->next->next = tmp;

        // setting fist as last element
        tmp->next = NULL;

        return rest;
    }
};

int main()
{
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.display();
    list.head = list.reverse(list.head);
    list.display();
    return 0;
}