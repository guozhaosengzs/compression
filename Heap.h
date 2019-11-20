/**
    Coding Assignment 4: Compression
    Heap.h
    November 22, 2019

    @author Zhaosen Guo
*/

#ifndef HEAP_H
#define HEAP_H

// include TreeNode?
using namespace std;

class Heap {
public:
    Heap();

    int get_size()                                          const;
    int get_left(int const index)                           const;
    int get_right(int const index)                          const;
    int get_parent(int const index)                         const;
    int get_freq_diff(int const index_a, int const index_b) const;

    TreeNode* remove();
    void add(TreeNode *node_ptr);
    void bubble_up(int current_index);
    void trickle_down(int current_index);
    void switch_order(int const index_a, int const index_b);

private:
    TreeNode *_array[256];
    int _size;

};

#endif // TREENODE_H
