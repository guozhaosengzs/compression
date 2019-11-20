/**
    Coding Assignment 4: Compression
    compress.cpp
    November 22, 2019

    @author Zhaosen Guo
    @collaboration Program skeleton by Darren Strash
*/

#include <fstream>
#include <iostream>
#include <string>
#include <string>
#include "TreeNode.h"
#include "Heap.h"

using namespace std;


/***/
TreeNode* make_tree_nodes(string input_file_name) {
    int char_freq [256] = {};
    unsigned char character;
    ifstream in_file_stream(input_file_name, ios::binary);
    while(in_file_stream.get(character)) {
        char_freq[character]++
    }

    TreeNode *node_ptrs[256] = {};
    for (unsigned char char = 0; char < 256; char++) {
        if (char_freq[char] != 0) {
            TreeNode *new_node = new TreeNode();
            new_node->set_char(char);
            new_node->set_freq(char_freq[char]);
            node_ptrs[char] = new_node;
        }
    return node_ptrs;
}

/***/
TreeNode* make_huffman_tree(TreeNode *nodes_array) {
    Heap p_queue;

    for (int ind = 0; ind < 256; ind++){
        if (nodes_array[ind] != nullptr){
            p_queue.add(nodes_array[ind]);
        }
    }

    while (p_queue.size > 1) {
        TreeNode *smallest_node_1 = p_queue.remove();
        TreeNode *smallest_node_2 = p_queue.remove();
        TreeNode *new_node = new TreeNode();
        new_node->become_parent(smallest_node_1, smallest_node_2);
        p_queue.add(new_node);
    }

    return p_queue.remove();
}

    // while queue size < 2
    // take the smallest two, pop them, make newnode, newnode->become_root
    // push back in

    // later..maybe not using this...
    for (unsigned char character = 0; character < 256; character++) {
        if (node_ptrs[character] != nullptr) {
            node_ptrs[character]->find_path();
        }
    }
}

/***/
void clean(TreeNode *tree_nodes_array) {
    for (int ind = 0; ind < 256; ind++){
        if (tree_nodes_array[ind] != nullptr){
            delete tree_nodes_array[ind];
        }
    }
}

/**
    compress text from a given input file to a given
    output file

    @param argc the number of command-line arguments
    @param argv an array of command-line-arguments
    @return an error code
*/
int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "usage: " << argv[0] << "<input file> <output file>" << endl;
        return 1;
    }

    string input_file_name(argv[1]);
    string output_file_name(argv[2]);
    cout << "Compressing " << input_file_name << " and writing to ";
    cout << output_file_name << endl;

    TreeNode *tree_nodes_array = make_tree_nodes(input_file_name);

    TreeNode *huffman_root = make_huffman_tree(tree_nodes_array);



    //next: if char_freq[n] != 0, make a character tree node as askii:freq
    // put all the treenodes into a priority queue construct
    // pop the two with fewest value, join to a new node with sum of both char_freq
    // push back... repeat until only 1 node is left

    // encode the document with tree key
    // encode the tree
    // note the # extra 0s put at the end

    unsigned char output_char;

    ofstream  out_file_stream(output_file_name, ios::binary);
    out_file_stream << output_char;
    out_file_stream.close();



    // deleting interdemiate node?
    clean(tree_nodes_array);

    return 0;
}
