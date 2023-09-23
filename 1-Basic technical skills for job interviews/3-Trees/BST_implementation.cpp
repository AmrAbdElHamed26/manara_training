#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

/// Base class for BST Operations
template<typename T>
class AbstractBST{
public:
    virtual void insert(T value) = 0;
    virtual bool contains(T value ) = 0;
    virtual vector<T> inorderTraversal() = 0;
    virtual vector<T> preorderTraversal() = 0;
    virtual vector<T> postorderTraversal() = 0;
};

template<typename T>
class BSTOperations : public AbstractBST<T>{
private:
    TreeNode<T>* root;
    vector<T>order;
    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }
    bool contains(TreeNode<T>* node, T value){
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        }

        if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }
    void  inorderTraversal (TreeNode<T>*node){
        if(node == nullptr)return;

        inorderTraversal(node->left);
        order.push_back(node->data);
        inorderTraversal(node->right);
    }
    void  preorderTraversal (TreeNode<T>*node){
        if(node == nullptr)return;

        order.push_back(node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
    void  postorderTraversal (TreeNode<T>*node){
        if(node == nullptr)return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        order.push_back(node->data);

    }


public:
    BSTOperations(){
        this->root = nullptr;
    }

    void insert(T value )override{
        root = insert(root,value );
    }
    bool contains(T value) override {
        return contains(root, value);
    }

    vector<T> inorderTraversal()override{
        order.clear();
        inorderTraversal(root);
        return order;
    }
    vector<T> preorderTraversal()override{
        order.clear();
        preorderTraversal(root);
        return order;
    }

    vector<T> postorderTraversal()override{
        order.clear();
        postorderTraversal(root);
        return order;
    }

};
