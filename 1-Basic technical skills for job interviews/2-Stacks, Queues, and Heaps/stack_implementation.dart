abstract class AbstractStack<T> {
  void push(T value);
  void pop();
  T topElement();
  int sizeOfStack();
  bool isEmpty();
  void display();
}

class StackOperations<T> implements AbstractStack<T> {
  List<T> elements = [];
  int top = -1;

  @override
  void push(T value) {
    elements.add(value);
    top++;
  }

  @override
  void pop() {
    if (top == -1) {
      throw StateError("Stack is empty. You can't remove anything.");
    }
    elements.removeLast();
    top--;
  }

  @override
  T topElement() {
    if (top == -1) {
      throw StateError("Stack is empty.");
    }
    return elements[top];
  }

  @override
  int sizeOfStack() {
    return top + 1;
  }

  @override
  bool isEmpty() {
    return top == -1;
  }

  @override
  void display() {
    while (top != -1) {
      print('${elements[top--]} ');
    }
    print('\n');
  }
}


