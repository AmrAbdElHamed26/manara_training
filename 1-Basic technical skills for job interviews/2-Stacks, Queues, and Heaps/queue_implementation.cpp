#include <bits/stdc++.h>

using namespace std;


/// Base class for Queue Operations
template<typename T>
class AbstractQueue {
public:
    virtual void enqueue(T value) = 0;
    virtual void dequeue() = 0;
    virtual T frontElement() = 0;
    virtual int sizeOfQueue() = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
};

template<typename T>
class QueueOperations : public AbstractQueue<T> {
private:
    vector<T> elements;
    int front;  // Index of the front element
    int rear;   // Index of the rear element

public:
    QueueOperations() : front(-1), rear(-1) {}

    void enqueue(T value) override {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        elements.push_back(value);
    }

    void dequeue() override {
        if (isEmpty()) {
            throw underflow_error("Queue is empty. You can't remove anything.");
        }
        front++;
    }

    T frontElement() override {
        if (isEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        return elements[front];
    }

    int sizeOfQueue() override {
        return rear - front + 1;
    }

    bool isEmpty() override {
        return front > rear;
    }

    void display() override {
        for (int i = front; i <= rear; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};
