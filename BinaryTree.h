#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <memory>
#include <iostream>

using namespace std;

class BinaryTree {
private:
    shared_ptr<TreeNode> root;

    void addNode(shared_ptr<TreeNode>& node, int value);
    shared_ptr<TreeNode> findMin(shared_ptr<TreeNode> node);
    shared_ptr<TreeNode> deleteNode(shared_ptr<TreeNode>& node, int value);
    void inorderTraversal(shared_ptr<TreeNode> node);
    bool searchNode(shared_ptr<TreeNode> node, int value);

public:
    BinaryTree();

    void add(int value);
    void remove(int value);
    void search(int value);
    void display();
    int countNodes();
    void clear();
};

#endif
