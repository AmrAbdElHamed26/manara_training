abstract class AbstractQueue<T> {
  void enqueue(T value);
  void dequeue();
  T frontElement();
  int sizeOfQueue();
  bool isEmpty();
  void display();
}

class QueueOperations<T> implements AbstractQueue<T> {
  List<T> elements = [];
  int front = -1; 
  int rear = -1;  

  @override
  void enqueue(T value) {
    if (front == -1) {
      front = 0;
      rear = 0;
    } else {
      rear++;
    }
    elements.add(value);
  }

  @override
  void dequeue() {
    if (isEmpty()) {
      throw StateError("Queue is empty. You can't remove anything.");
    }
    front++;
  }

  @override
  T frontElement() {
    if (isEmpty()) {
      throw StateError("Queue is empty.");
    }
    return elements[front];
  }

  @override
  int sizeOfQueue() {
    return rear - front + 1;
  }

  @override
  bool isEmpty() {
    return front > rear;
  }

  @override
  void display() {
    for (int i = front; i <= rear; i++) {
      print('${elements[i]} ');
    }
    print('');
  }
}

