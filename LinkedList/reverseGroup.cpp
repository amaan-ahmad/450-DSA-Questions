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

    Node *reverseGroup(Node *tmp, int k)
    {

        // base case if linkedlist is empty
        if (tmp == NULL || tmp->next == NULL || k == 0)
        {
            return tmp;
        }

        Node *rest = tmp->next;
        tmp->next->next = tmp;
        reverseGroup(rest, k--);
        return tmp;
    }
};

int main()
{
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);
    list.addNode(7);
    list.display();
    list.head = list.reverseGroup(list.head, 3);
    list.display();
    return 0;
}