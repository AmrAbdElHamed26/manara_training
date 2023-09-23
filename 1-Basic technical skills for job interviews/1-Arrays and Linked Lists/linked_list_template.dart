class Node<T> {
  T? data;
  Node<T>? next;

  Node(T value) {
    this.data = value;
    this.next = null;
  }
}

abstract class AbstractLinkedList<T> {
  void pushBack(T value);
  void display();
  bool findElement(T value);
  void removeElement(T value);
  void reverseElements();
  int getSize();
}

class LinkedListOperations<T> implements AbstractLinkedList<T> {
  Node<T>? head, last;
  int size = 0;

  LinkedListOperations() {
    head = last = null;
    size = 0;
  }

  @override
  void pushBack(T value) {
    Node<T> newNode = Node<T>(value);
    if (head == null) {
      head = newNode;
      last = newNode;
    } else {
      last?.next = newNode;
      last = newNode;
    }
    size++;
  }

  @override
  void display() {
    Node<T>? current = head;
    while (current != null) {
      print('${current.data} ');
      current = current.next;
    }
    print('');
  }

  @override
  bool findElement(T value) {
    Node<T>? current = head;
    while (current != null) {
      if (current.data == value) return true;
      current = current.next;
    }
    return false;
  }

  @override
  void removeElement(T value) {
    Node<T>? current = head;
    Node<T>? prev = null;

    while (current != null) {
      if (current.data == value) {
        size--;
        if (prev != null) {
          prev.next = current.next;
        } else {
          head = current.next;
        }
        return;
      }
      prev = current;
      current = current.next;
    }
  }

  @override
  void reverseElements() {
    Node<T>? current = head;
    Node<T>? prev = null, next = null;

    while (current != null) {
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }

    head = prev;
  }

  @override
  int getSize() {
    return size;
  }
}

void main() {
  LinkedListOperations<int> list = LinkedListOperations<int>();

  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);

  list.display(); // Output: 1 2 3

  list.reverseElements();
  list.display(); // Output: 3 2 1
}
