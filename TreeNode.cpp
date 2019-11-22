/**
    Coding Assignment 4: Compression
    TreeNode.cpp
    November 22, 2019

    @author Zhaosen Guo
*/

#include "TreeNode.h"
#include <string>
#include <bits/stdc++.h>

using namespace std;

/***/
TreeNode::TreeNode() {
    _parent = nullptr;
    _l_child = nullptr;
    _r_child = nullptr;
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
void TreeNode::become_parent(TreeNode* lc_ptr, TreeNode* rc_ptr) {
    set_l_child(lc_ptr);
    set_r_child(rc_ptr);
    lc_ptr->set_parent(this);
    rc_ptr->set_parent(this);
    set_freq(lc_ptr->get_freq() + rc_ptr->get_freq());
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
void TreeNode::navigate() {
    string bottom_to_top;
    TreeNode *current_root = this;

    while (current_root->get_parent()) {
        if ((current_root->get_parent())->get_l_child() == current_root) {
            bottom_to_top += '0';
        }
        else {
            bottom_to_top += '1';
        }
        current_root = current_root->get_parent();
    }
    reverse(bottom_to_top.begin(),bottom_to_top.end());
    _path_from_root = bottom_to_top;
}

/***/
string TreeNode::get_path() const {
    return _path_from_root;
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
