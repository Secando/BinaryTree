#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

class TreeNode {
public:
    int value;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val);
};

#endif

