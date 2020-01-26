/**
    Compression
    TreeNode.cpp
    November 22, 2019

    @author Zhaosen Guo
*/

#include "TreeNode.h"
#include <string>
#include <bits/stdc++.h>

using namespace std;

/**
    The constructor for TreeNode class.
*/
TreeNode::TreeNode() {
    _parent = nullptr;
    _l_child = nullptr;
    _r_child = nullptr;
}

/**
    Stores the corresponding character in the node.

    @param A unsigned character.
*/
void TreeNode::set_char(unsigned char const character) {
    _char = character;
}

/**
    Stores the frequency of the character, or sum children nodes' frequencies.

    @param An integer representing frequency.
*/
void TreeNode::set_freq(int const freq) {
    _frequency = freq;
}

/**
    Becomes the parent nodes of the two provided nodes.

    @param Two pointers for TreeNode objects.
*/
void TreeNode::become_parent(TreeNode* lc_ptr, TreeNode* rc_ptr) {
    set_l_child(lc_ptr);
    set_r_child(rc_ptr);
    lc_ptr->set_parent(this);
    rc_ptr->set_parent(this);
    set_freq(lc_ptr->get_freq() + rc_ptr->get_freq());
}

/**
    Sets the parent of the object.

    @param A pointer for the intended parent node.
*/
void TreeNode::set_parent(TreeNode* p_ptr) {
    _parent = p_ptr;
}

/**
    Sets the left child of the object.

    @param A pointer for the intended left child node.
*/
void TreeNode::set_l_child(TreeNode* lc_ptr) {
    _l_child = lc_ptr;
}

/**
    Sets the right child of the object.

    @param A pointer for the intended right child node.
*/
void TreeNode::set_r_child(TreeNode* rc_ptr) {
    _r_child = rc_ptr;
}

/**
    Finds the path from the root to the current leaf.
*/
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

/**
    Provides a string that represents the path from root to object.

    @return A string with 0s & 1s.
*/
string TreeNode::get_path() const {
    return _path_from_root;
}

/**
    Provides the character stored in the object.

    @return An unsigned character.
*/
unsigned char TreeNode::get_char() const {
    return _char;
}

/**
    Provides the frequency stored in the object.

    @return An integer representing frequency.
*/
int TreeNode::get_freq() const {
    return _frequency;
}

/**
    Provides the parent node of the current object.

    @return A pointer to the parent.
*/
TreeNode* TreeNode::get_parent() const {
    return _parent;
}

/**
    Provides the left child node of the current object.

    @return A pointer to the left child.
*/
TreeNode* TreeNode::get_l_child() const {
    return _l_child;
}

/**
    Provides the right child node of the current object.

    @return A pointer to the right child.
*/
TreeNode* TreeNode::get_r_child() const {
    return _r_child;
}
