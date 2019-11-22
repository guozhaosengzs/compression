/**
    Coding Assignment 4: Compression
    Heap.h
    November 22, 2019

    @author Zhaosen Guo
*/

#include "TreeNode.h"

using namespace std;

class Heap {
public:
    Heap();

    int       get_size()                                    const;
    TreeNode* remove();
    void      add(TreeNode *node_ptr);

private:
    int get_left(int const index)                           const;
    int get_right(int const index)                          const;
    int get_parent(int const index)                         const;
    int get_freq_diff(int const index_a, int const index_b) const;

    void bubble_up(int current_index);
    void trickle_down(int current_index);
    void switch_order(int const index_a, int const index_b);

    TreeNode *_array[256];
    int _size;
};
