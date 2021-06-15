#include <iostream>

/*
Operations this linked list class can do:

[x] adding node at first
[x] adding node at last
[x] adding node at an index
[x] display linked list
[x] remove node from first
[x] remove node from last
[x] remove node at an index
[ ] reverse linked list (recursively)
[ ] reverse linked list in K-groups
[ ] detect a loop in linked list
[ ] delete loops in linked list
*/

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    Node(int val, Node *nextPtr)
    {
        data = val;
        next = nextPtr;
    }
};

class LinkedList
{
public:
    Node *head, *tail;
    int size;

    LinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }

    void addLast(int val)
    {
        Node *tmp = new Node(val);

        if (head == nullptr)
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }

        size++;
    }

    void addFirst(int val)
    {
        Node *tmp = new Node(val);

        if (head == nullptr)
        {
            head = tail = tmp;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }

        size++;
    }

    void insertAt(int val, int index)
    {
        Node *newNode = new Node(val);
        Node *ptr = head;

        while (ptr != nullptr)
        {
            if (index - 1 == 0)
            {
                newNode->next = ptr->next;
                ptr->next = newNode;
                size++;
            }
            index--;
            ptr = ptr->next;
        }
    }

    void display()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->next == nullptr)
            {
                std::cout << tmp->data << std::endl;
            }
            else
            {
                std::cout << tmp->data << " -> ";
            }
            tmp = tmp->next;
        }
    }

    void removeFirst()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            head = head->next;
            size--;
        }
    }

    void removeLast()
    {
        if (head == nullptr && tail == nullptr)
        {
            return;
        }
        else
        {
            Node *current, *prev;
            current = prev = head;
            while (current != nullptr)
            {
                if (current->next == nullptr)
                {
                    prev->next = nullptr;
                    tail = prev;
                    size--;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    void removeAt(int index)
    {

        if (head == nullptr)
        {
            return;
        }

        if (index == 0)
        {
            removeFirst();
            return;
        }

        Node *current, *prev;
        current = prev = head;
        for (int i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        free(current);
        size--;
    }

    Node *reverseUtil(Node *tmp)
    {
        if (tmp == nullptr || tmp->next == nullptr)
        {
            head = tmp;
            return tmp;
        }

        reverseUtil(tmp->next);
        tmp->next->next = tmp;
        tmp->next = nullptr;
    }

    void reverse()
    {
        head = reverseUtil(head);
    }
};

int main()
{
    LinkedList list;
    list.addFirst(10);
    list.addFirst(20);
    list.addFirst(30);
    list.addFirst(40);
    list.addFirst(50);
    list.display();
    list.addLast(5);
    list.display();
    list.insertAt(100, 2);
    list.display();
    list.removeFirst();
    list.display();
    list.removeLast();
    list.display();
    list.removeAt(2);
    list.display();
    list.removeAt(0);
    list.display();
    std::cout << "HEAD: " << list.head->data << std::endl;
    std::cout << "TAIL: " << list.tail->data << std::endl;

    return 0;
}