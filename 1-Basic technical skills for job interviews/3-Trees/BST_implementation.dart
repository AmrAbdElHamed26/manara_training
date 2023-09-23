class TreeNode {
  int data;
  TreeNode? left;
  TreeNode? right;

  TreeNode(int value) : data = value, left = null, right = null;
}

abstract class AbstractBST {
  void insert(int value);
  bool contains(int value);
  List<int> inorderTraversal();
  List<int> preorderTraversal();
  List<int> postorderTraversal();
}

class BSTOperations implements AbstractBST {
  TreeNode? root = null;
  List<int> order = [];

  TreeNode? _insert(TreeNode? node, int value) {
    if (node == null) {
      return TreeNode(value);
    }

    if (value < node.data) {
      node.left = _insert(node.left, value);
    } else {
      node.right = _insert(node.right, value);
    }

    return node;
  }

  bool _contains(TreeNode? node, int value) {
    if (node == null) {
      return false;
    }

    if (value == node.data) {
      return true;
    }

    if (value < node.data) {
      return _contains(node.left, value);
    } else {
      return _contains(node.right, value);
    }
  }

  void _inorderTraversal(TreeNode? node) {
    if (node == null) return;

    _inorderTraversal(node.left);
    order.add(node.data);
    _inorderTraversal(node.right);
  }

  void _preorderTraversal(TreeNode? node) {
    if (node == null) return;

    order.add(node.data);
    _preorderTraversal(node.left);
    _preorderTraversal(node.right);
  }

  void _postorderTraversal(TreeNode? node) {
    if (node == null) return;

    _postorderTraversal(node.left);
    _postorderTraversal(node.right);
    order.add(node.data);
  }

  @override
  void insert(int value) {
    root = _insert(root, value);
  }

  @override
  bool contains(int value) {
    return _contains(root, value);
  }

  @override
  List<int> inorderTraversal() {
    order.clear();
    _inorderTraversal(root);
    return order;
  }

  @override
  List<int> preorderTraversal() {
    order.clear();
    _preorderTraversal(root);
    return order;
  }

  @override
  List<int> postorderTraversal() {
    order.clear();
    _postorderTraversal(root);
    return order;
  }
}


