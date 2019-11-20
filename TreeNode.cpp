/**
    Coding Assignment 4: Compression
    TreeNode.cpp
    November 22, 2019

    @author Zhaosen Guo
*/

#include "TreeNode.h"
#include <string>

using namespace std;

/***/
TreeNode::TreeNode() {
    TreeNode* parent = nullptr;
    TreeNode* _l_child = nullptr;
    TreeNode* _r_child = nullptr;
}

/***/
void TreeNode::set_char(unsigned char const character) {
    _char = character;
}

/***/
void TreeNode::set_freq(int const freq) {
    _frequency = freq;
}

/***/
void TreeNode::become_parent(TreeNode* lc_ptr, TreeNode* rc_ptr)) {
    set_l_child(lc_ptr);
    set_r_child(rc_ptr);
    lc_ptr->set_parent(this);
    rc_ptr->set_parent(this);
}

/***/
void TreeNode::set_parent(TreeNode* p_ptr) {
    _parent = p_ptr;
}

/***/
void TreeNode::set_l_child(TreeNode* lc_ptr) {
    _l_child = lc_ptr;
}

/***/
void TreeNode::set_r_child(TreeNode* rc_ptr) {
    _r_child = rc_ptr;
}

/***/
void TreeNode::find_path() {
    string bottom_top_path{};
    TreeNode *current_root = this;

    while (current_root->get_parent() != nullptr) {
        TreeNode *temp = current_root;
        current_node = current_root->get_parent();
        if (temp == current_root->get_l_child){
            bottom_top_path += '0';
        }
        else {
            bottom_top_path += '1';
        }
    }
}

/***/
unsigned char TreeNode::get_char() const {
    return _char;
}

/***/
int TreeNode::get_freq() const {
    return _frequency;
}

/***/
TreeNode* TreeNode::get_parent() const {
    return _parent;
}

/***/
TreeNode* TreeNode::get_l_child() const {
    return _l_child;
}

/***/
TreeNode* TreeNode::get_r_child() const {
    return _r_child;
}
