/**
    Coding Assignment 4: Compression
    Heap.cpp
    November 22, 2019

    @author Zhaosen Guo
*/

#include "Heap.h"

using namespace std;

/***/
Heap::Heap() {
    _size = 0;
    for (int index; index < 256; index++) {
        _array[index] = nullptr;
    }
}

/***/
int Heap::get_size() const{
    return _size;
}

/***/
int Heap::get_left(int const index) const{
    return (2 * index) + 1;
}

/***/
int Heap::get_right(int i) const {
    return (2 * index) + 2;
}

/***/
int Heap::get_parent(int const index) const {
    return (index - 1) / 2;
}

/***/
int Heap::get_freq_diff(int const index_a, int const index_b) const {
    return _array[index_a]->get_freq - _array[index_b]->get_freq;
}

/***/
void Heap::switch_order(int const index_a, int const index_b) {
    TreeNode *temp_prt;
    temp_prt = _array[index_b];
    _array[index_b] = _array[index_a];
    _array[index_a] = temp_prt;
}

/***/
void Heap::add(TreeNode *node_ptr) {
    _array[_size++] = node_ptr; //? change size? put it in then add?
    bubble_up(_size - 1);
}

/***/
void Heap::bubble_up(int current_index) {
    int parent = get_parent(current_index);
    while (current_index > 0 && get_freq_diff(current_index, parent) < 0) {
        switch_order(current_index, parent);
        current_index = parent;
        parent = get_parent(current_index);
    }
}

/***/
TreeNode* Heap::remove() { //delete bottom necessary?
    TreeNode *smallest = _array[0];
    _array[0] = _array[--_size]; // ? same question as add
    _array[_size] = nullptr;

    trickleDown(0);
    return smallest;
    }
}

/***/
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
