/**
    Compression
    Heap.cpp
    November 22, 2019

    @author Zhaosen Guo
*/

#include "Heap.h"
#include "TreeNode.h"

using namespace std;

/**
    The constructor of a Heap class.
*/
Heap::Heap() {
    _size = 0;
    for (int index = 0; index < 256; index++) {
        _array[index] = nullptr;
    }
}

/**
    Provides the actual size of the heap.

    @return An integer representing the size.
*/
int Heap::get_size() const{
    return _size;
}

/**
    Provides the index of the left child for the given index,

    @param An int index.
    @return the index of the left child.
*/
int Heap::get_left(int const index) const {
    return (2 * index) + 1;
}

/**
    Provides the index of the right child for the given index,

    @param An int index.
    @return the index of the right child.
*/
int Heap::get_right(int const index) const {
    return (2 * index) + 2;
}

/**
    Provides the index of the parent for the given index,

    @param An int index.
    @return the index of the parent.
*/
int Heap::get_parent(int const index) const {
    return (index - 1) / 2;
}

/**
    Calculates the differences in frequencies between the two TreeNode object.

    @param A pointer for TreeNode object.
    @param A pointer for TreeNode object.
*/
int Heap::get_freq_diff(int const index_a, int const index_b) const {
    return (_array[index_a]->get_freq() - _array[index_b]->get_freq());
}

/**
    Swaps the two object on the given index.

    @param An int index.
    @param An int index.
*/
void Heap::switch_order(int const index_a, int const index_b) {
    TreeNode *temp_prt;
    temp_prt = _array[index_b];
    _array[index_b] = _array[index_a];
    _array[index_a] = temp_prt;
}

/**
    Adds a new object to Heap.

    @param A pointer to the TreeNode to add.
*/
void Heap::add(TreeNode *node_ptr) {
    _array[_size++] = node_ptr;
    bubble_up(_size - 1);
}

/**
    If the object on the given index is violating the Heap rule (less than its
    parent), then send it up the chain.

    @param An index for the object in question.
*/
void Heap::bubble_up(int current_index) {
    int parent = get_parent(current_index);
    while (current_index > 0 && get_freq_diff(current_index, parent) < 0) {
        switch_order(current_index, parent);
        current_index = parent;
        parent = get_parent(current_index);
    }
}

/**
    Removes the top of the heap.

    @return A pointer to the removed TreeNode object.
*/
TreeNode* Heap::remove() {
    TreeNode *smallest = _array[0];
    _array[0] = _array[--_size];
    _array[_size] = nullptr;

    trickle_down(0);
    return smallest;
}

/**
    If the object on the given index is violating the Heap rule (greater than
    its children), then send it down.

    @param An index for the object in question.
*/
void Heap::trickle_down(int current_index) {
    do {
        int target_index = -1;
        int right = get_right(current_index);
        if (right < _size && get_freq_diff(right, current_index) < 0) {
            int left = get_left(current_index);
            if (get_freq_diff(left, right) < 0) {
                target_index = left;
            }
            else {
                target_index = right;
            }
        }
        else {
            int left = get_left(current_index);
            if (left < _size && get_freq_diff(left, current_index) < 0) {
                target_index = left;
            }
        }
        if (target_index >= 0) {
            switch_order(current_index, target_index);
        }
        current_index = target_index;
    }
    while(current_index >= 0);
}
