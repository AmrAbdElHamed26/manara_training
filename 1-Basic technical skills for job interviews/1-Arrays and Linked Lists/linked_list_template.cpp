#include <bits/stdc++.h>
using namespace std ;
template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        this->data= value;
        this->next = nullptr;
    }
};

///Base class for Linked List Operations
template<typename T>
class AbstractLinkedList {
public:
    virtual void push_back(T value) = 0;
    virtual void display() = 0;
    virtual bool findElement (T value ) = 0 ;
    virtual void removeElement(T vale) = 0 ;
    virtual void reverseElements() = 0 ;
    virtual  bool getSize() = 0 ;
};

template<typename T>
class LinkedListOperations : public AbstractLinkedList<T> {
private:
    Node<T>* head, *last;
    int size ;
public:
    LinkedListOperations() {
        this->head = this->last = nullptr;
        this->size = 0 ;
    }

    void push_back(T value) override {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        size++;
    }

    void display() override {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool findElement(T value) override{
        Node<T>* current = head ;
        while(current){
            if(current->data == value )return  true ;
            current=current->next;
        }
        return false;
    }

    void removeElement(T value) override {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current) {
            if (current->data == value) {
                size--;
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }

                return ;
            }
            prev = current;
            current = current->next;
        }
    }

    void reverseElements()override {
        Node<T>* current = head,* prev = nullptr , *next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    bool getSize() override{
        return size;
    }
};
