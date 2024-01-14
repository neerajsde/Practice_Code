#include <iostream>
using namespace std;

class MyCircularQueue
{
    int size, front, rear;
    int *arr;

public:
    MyCircularQueue(int k)
    {
        size = k;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    ~MyCircularQueue() { delete[] arr; }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = value;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if ((front == size - 1 && rear != 0) || (front == size - 1 && rear == 0))
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty() { return front == -1 && rear == -1; }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }
    void print()
    {
        cout << "Front: " << front << " Rear: " << rear << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyCircularQueue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    q.print();
    q.enQueue(60);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();

    q.deQueue();
    q.deQueue();

    q.print();
    return 0;
}