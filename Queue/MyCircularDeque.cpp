#include <iostream>
using namespace std;

class MyCircularDeque
{
    int size, front, rear;
    int *arr;

public:
    MyCircularDeque(int k)
    {
        size = k;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;

        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = value;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = value;
        }
        else
        {
            front--;
            arr[front] = value;
        }
        return true;
    }

    bool insertLast(int value)
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

    bool deleteFront()
    {
        if (isEmpty())
            return false;

        if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
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

    bool deleteLast()
    {
        if (isEmpty())
            return false;

        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return true;
    }

    int getFront()
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

    int getRear()
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
    MyCircularDeque q(6);
    q.insertFront(10);
    q.insertLast(5);
    q.insertFront(20);
    q.insertLast(15);
    q.insertFront(30);
    q.insertFront(40);
    q.insertFront(40);

    q.print();
    return 0;
}