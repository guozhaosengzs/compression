/**
    Coding Assignment 4: Compression
    compress.cpp
    November 22, 2019

    @author Zhaosen Guo
    @collaboration Program skeleton by Darren Strash
*/

#include "Heap.h"
#include "TreeNode.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
    Reads file to collect character frequency, then make corresponding nodes.

    @param Ifsteam by reference.
    @param An array of TreeNode pointers by reference.
*/
void make_tree_nodes(ifstream &in_file_stream, TreeNode* (&nodes_array)[256]) {
    int char_freq [256] = {};
    unsigned char character = in_file_stream.get();
    while (in_file_stream) {
        char_freq[character]++;
        character = in_file_stream.get();
    }

    for (int index = 0; index < 256; index++) {
        if (char_freq[index] != 0) {
            unsigned char character = (unsigned char) index;
            TreeNode *new_node = new TreeNode();
            new_node->set_char(character);
            new_node->set_freq(char_freq[index]);
            nodes_array[index] = new_node;
        }
    }
}

/**
    Makes a Huffman tree based on a heap priority queue.

    @param The array of TreeNode pointers by reference.
    @return A pointer to the very root of the Huffman tree.
*/
TreeNode* make_huffman_tree(TreeNode* (&nodes_array)[256]) {
    Heap p_queue;
    for (int ind = 0; ind < 256; ind++) {
        if (nodes_array[ind]) {
            p_queue.add(nodes_array[ind]);
        }
    }

    while (p_queue.get_size() > 1) {
        TreeNode *smallest_node_1 = p_queue.remove();
        TreeNode *smallest_node_2 = p_queue.remove();
        TreeNode *new_node = new TreeNode();
        new_node->become_parent(smallest_node_1, smallest_node_2);
        p_queue.add(new_node);
    }
    return p_queue.remove();
}

/**
    Coverts Huffman tree into a string representation.

    @param The pointer to the root of Huffman tree.
    @param The string to store the transformation, passed by reference.
*/
void encode_huffman_tree(TreeNode *root, string &encoded_tree) {
    if (root == nullptr) {
        return;
    }
    else {
        if (root->get_l_child()) {
            encoded_tree += 'I';
            encode_huffman_tree(root->get_l_child(), encoded_tree);
            encode_huffman_tree(root->get_r_child(), encoded_tree);
        }
        else {
            encoded_tree += 'L';
            encoded_tree += root->get_char();
        }
    }
}

/**
    Upon recieving a string of eight 0 & 1s, converts it to a true 8 bits char.

    @param The string needed to be converted.
    @return A unsigned char type data.
*/
unsigned char bit_coversion(string str) {
    unsigned char eight_bits = 0;
    for (int id = 7; id >= 0; id--) {
        if (str[7-id] == '1') {
            unsigned char temp = 1;
            eight_bits = eight_bits | (temp << id);
        }
    }
    return eight_bits;
}

/**
    Reads the input file again, write encoded the tree, file length, and
    true bits representation of file contents to the compressed file.

    @param Ifsteam by reference.
    @param Ofsteam by reference.
    @param A pointer to the root of the Huffman tree.
    @param The array of TreeNode pointers by reference.
*/
void read_to_compress(ifstream &in_file_stream, ofstream &out_file_stream,
    TreeNode *root, TreeNode* (&nodes_array)[256]) {

    size_t file_length = 0;
    for (int index = 0; index < 256; index++) {
        if (nodes_array[index]) {
            file_length += nodes_array[index]->get_freq();
            nodes_array[index]->navigate(); //find out their paths in the tree
        }
    }
    string encoded_tree;
    encode_huffman_tree(root, encoded_tree);
    out_file_stream << encoded_tree << file_length;

    string buffer;
    unsigned char character = in_file_stream.get();
    while (in_file_stream || buffer.size() >= 8) {
        if (in_file_stream) {
            buffer += nodes_array[character]->get_path();
            character = in_file_stream.get();
        }
        if (buffer.size() >= 8) {
            out_file_stream << bit_coversion(buffer.substr(0,8));
            buffer.erase(0,8);
        }
    }
    out_file_stream << bit_coversion(buffer.append(8 - buffer.size(), '0'));
}

/**
    Recursive function to delete the tree under a given root.

    @param A pointer acting as the current root of the tree to be delete.
*/
void delete_tree(TreeNode *node) {
    if (!node) {
        return;
    }
    delete_tree(node->get_l_child());
    delete_tree(node->get_r_child());
    delete node;
}

/**
    compress text from a given input file to a given output file.

    @param argc the number of command-line arguments.
    @param argv an array of command-line-arguments.
    @return an error code.
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
    ifstream in_file_stream(input_file_name, ios::binary);

    if (!in_file_stream) { return 1;} // in case of empty file

    TreeNode *nodes_array[256] = {};
    make_tree_nodes(in_file_stream, nodes_array);
    in_file_stream.close();

    TreeNode *huffman_root = make_huffman_tree(nodes_array);

    in_file_stream.open(input_file_name, ios::binary);
    ofstream out_file_stream(output_file_name, ios::binary);

    read_to_compress(in_file_stream, out_file_stream,
                    huffman_root, nodes_array);

    in_file_stream.close();
    out_file_stream.close();
    delete_tree(huffman_root);

    return 0;
}
