#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int s)
    {
        arr = new int[s];
        this->size = s;
        front = -1;
        rear = -1;
    }
    ~Queue()
    {
        delete[] arr;
    }
    void push(int val)
    {
        // check overflow
        if (rear == size - 1)
        {
            cout << "Overflow" << endl;
        }
        else if (rear == -1 && front == -1)
        {
            // empty case
            rear++;
            front++;
            arr[rear] = val;
        }
        else
        {
            // normal case
            rear++;
            arr[rear] = val;
        }
    }
    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    int getSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        return rear - front + 1;
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "No element in Queue. Can't give element" << endl;
            return -1;
        }
        return arr[front];
    }
    int getBack()
    {
        if (rear == -1)
        {
            cout << "No element in Queue. Can't give element" << endl;
            return -1;
        }
        return arr[rear];
    }
    bool empty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    // For practice purpose
    void print()
    {
        cout << "Front: " << front << endl;
        cout << "Rear: " << rear << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();

    cout << "Size: " << q.getSize() << endl;
    cout << "front: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is not Empty" << endl;
    }
    return 0;
}