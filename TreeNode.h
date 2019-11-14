/**
    Coding Assignment 4: Compression
    TreeNode.h
    November 22, 2019

    @author Zhaosen Guo
*/

#ifndef TREENODE_H
#define TREENODE_H

#include <string>

using namespace std;

class TreeNode {
public:
    TreeNode();

    void set_char(unsigned char const character);
    void set_freq(int const freq);

    void become_root(TreeNode* lc_ptr, TreeNode* rc_ptr));
    void set_parent(TreeNode* p_ptr);
    void set_l_child(TreeNode* lc_ptr);
    void set_r_child(TreeNode* rc_ptr);
    void find_path();

    unsigned char get_char()    const;
    int get_freq()              const;
    TreeNode* get_parent()      const;
    TreeNode* get_l_child()     const;
    TreeNode* get_r_child()     const;

private:
    unsigned char _char;
    int _frequency;
    string _path_to_root;

    TreeNode* _parent;
    TreeNode* _l_child;
    TreeNode* _r_child;
};

#endif // TREENODE_H
