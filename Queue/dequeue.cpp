#include <iostream>
using namespace std;

// DOUBLY ENDED QUEUE
class DeQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    DeQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    ~DeQueue(){
        delete[] arr;
    }
    void push_back(int val)
    {
        // overflow
        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void push_front(int val)
    {
        // overflow
        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }
    void pop_front()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1 && rear != 0)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void pop_back()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            arr[rear] = -1;
            rear++;
        }
    }

    // For Experiment
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DeQueue q(5);
    q.push_back(10);
    q.print();
    q.push_front(11);
    q.push_front(15);
    q.push_back(20);
    q.push_back(30);
    q.print();
    q.push_back(27);
    q.pop_back();
    q.pop_front();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.print();
    return 0;
}