#include "BinaryTree.h"
#include <functional>  // Добавлено подключение для использования std::function

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::addNode(shared_ptr<TreeNode>& node, int value) {
    if (!node) {
        node = make_shared<TreeNode>(value);
    } else if (value < node->value) {
        addNode(node->left, value);
    } else {
        addNode(node->right, value);
    }
}

shared_ptr<TreeNode> BinaryTree::findMin(shared_ptr<TreeNode> node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

shared_ptr<TreeNode> BinaryTree::deleteNode(shared_ptr<TreeNode>& node, int value) {
    if (!node) return nullptr;
    if (value < node->value) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->value) {
        node->right = deleteNode(node->right, value);
    } else {
        if (!node->left) return node->right;
        if (!node->right) return node->left;

        shared_ptr<TreeNode> minRight = findMin(node->right);
        node->value = minRight->value;
        node->right = deleteNode(node->right, minRight->value);
    }
    return node;
}

void BinaryTree::inorderTraversal(shared_ptr<TreeNode> node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }
}

bool BinaryTree::searchNode(shared_ptr<TreeNode> node, int value) {
    if (!node) return false;
    if (node->value == value) return true;
    return value < node->value ? searchNode(node->left, value) : searchNode(node->right, value);
}

void BinaryTree::add(int value) {
    addNode(root, value);
}

void BinaryTree::remove(int value) {
    root = deleteNode(root, value);
}

void BinaryTree::search(int value) {
    if (searchNode(root, value)) {
        cout << "Значение " << value << " найдено в дереве.\n";
    } else {
        cout << "Значение " << value << " отсутствует в дереве.\n";
    }
}

void BinaryTree::display() {
    cout << "Симметричный обход дерева: ";
    inorderTraversal(root);
    cout << endl;
}

int BinaryTree::countNodes() {
    int count = 0;
    function<void(shared_ptr<TreeNode>)> countHelper = [&](shared_ptr<TreeNode> node) {
        if (node) {
            count++;
            countHelper(node->left);
            countHelper(node->right);
        }
    };
    countHelper(root);
    return count;
}

void BinaryTree::clear() {
    root = nullptr;
}
