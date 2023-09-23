#include <bits/stdc++.h>
using namespace std;

///Base class for Stack Operations
template<typename T>
class AbstractStack{
public:
    virtual void push(T value) = 0;
    virtual void pop() = 0;
    virtual int topElement ( ) = 0 ;
    virtual int sizeOfStack() = 0 ;
    virtual bool isEmpty() = 0 ;
    virtual void display()=0;
};

template<typename T>
class StackOperations : public AbstractStack<T> {
private:
    vector<T>elements;
    int top ;

public:

    StackOperations(){
        this->top = -1 ;
    }

    void push(T value)override{
        elements.push_back(value );
        top++;
    }

    void pop()override{
        if(top == -1 ) throw underflow_error("Stack is empty you can't remove any thing ");
        elements.pop_back();
        top -- ;

    }

    int topElement()override{
        if(top == -1 ) throw underflow_error("Stack is empty");
        int value = elements[top--];
        return value;
    }
    int sizeOfStack() override{
        return top+1;
    }

    bool isEmpty()override{
        if(top == -1 )return false;

        return true;
    }

    void display()override{
        while(top != -1 ){
            cout << elements[top--]<< " " ;
        }
        cout <<endl;
    }

};
