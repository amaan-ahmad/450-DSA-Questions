#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T *ptr;
    int size, front = -1, rear = -1;

public:
    Queue(int size);
    void enQueue(int data);
    void deQueue();
    void display();
};

template <typename T>
Queue<T>::Queue(int data)
{
    ptr = new T[data];
    size = data;
}

template <typename T>
void Queue<T>::enQueue(int data)
{
    if (rear + 1 == size)
    {
        return;
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
            ptr[++rear] = data;
        }
        else
        {
            ptr[++rear] = data;
        }
    }
}

template <typename T>
void Queue<T>::deQueue()
{
    if (front > rear)
        return;
    else if (front == rear)
        front = rear = -1;
    else
        front++;
}

template <typename T>
void Queue<T>::display()
{
    for (int i = front; i <= rear; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue<int> q = Queue<int>(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);
    q.enQueue(70);
    q.display();
    return 0;
}
