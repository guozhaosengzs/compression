/**
    Coding Assignment 4: Compression
    uncompress.cpp
    November 22, 2019

    @author Zhaosen Guo
    @collaboration Program skeleton by Darren Strash
*/

#include "TreeNode.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/***/
TreeNode* rebuild_tree(ifstream &inf_stream) {
    if (inf_stream.get() == 'I') {
        TreeNode *root = new TreeNode();

        root->set_l_child(rebuild_tree(inf_stream));
        root->set_r_child(rebuild_tree(inf_stream));
        //root->become_parent(rebuild_tree(inf_stream), rebuild_tree(inf_stream));
        return root;
    }
    else {
        unsigned char character = inf_stream.get();
        TreeNode *leaf = new TreeNode();
        leaf->set_char(character);
        return leaf;
    }
}

/***/
void refill_buffer(ifstream &inf_stream, string &buffer){
    unsigned char eight_bits = inf_stream.get();
    for (int id = 7; id >= 0; id--) {
        unsigned char temp = eight_bits & (1 << id);
        temp = temp >> id;
        if (temp) {
            buffer += '1';
        }
        else {
            buffer += '0';
        }
    }
}

/***/
unsigned char traverse(ifstream &inf_stream, TreeNode *ptr, string &buffer) {
    while ((ptr->get_l_child() != nullptr) | (ptr->get_r_child()!= nullptr)) {
        if (buffer.size() < 1) {
            refill_buffer(inf_stream, buffer);
        }
        if (buffer[0] == '0') {
            ptr = ptr->get_l_child();
        }
        if (buffer[0] == '1') {
            ptr = ptr->get_r_child();
        }
        buffer.erase(0,1);
    }
    return ptr->get_char();
}


/***/
void read_to_uncompress(ifstream &inf_stream, ofstream &of_stream,
    size_t file_remain_len, TreeNode *root) {
    string buffer;

    while (file_remain_len > 0) {
        TreeNode *ptr = root;
        unsigned char ch = traverse(inf_stream, ptr, buffer);
        cout << int(ch);
        of_stream << ch;

        file_remain_len--;
    }
}

void delete_tree(TreeNode *node) {
    if (!node) {
        return;
    }
    delete_tree(node->get_l_child());
    delete_tree(node->get_r_child());
    delete node;
}

/**
    decompress encoded text from a given input file to a given
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
    cout << "Uncompressing " << input_file_name << " and writing to ";
    cout << output_file_name << endl;

    ifstream inf_stream(input_file_name, ios::binary);
    ofstream of_stream(output_file_name, ios::binary);

    TreeNode *huffman_root = rebuild_tree(inf_stream);

    size_t file_length = 0;
    inf_stream >> file_length;

    read_to_uncompress(inf_stream, of_stream, file_length, huffman_root);

    delete_tree(huffman_root);

    return 0;
}
