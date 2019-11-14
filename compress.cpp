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

using namespace std;

/***/
TreeNode* make_huffman_code(int char_freq[256]){
    TreeNode *node_ptrs[256] = {}; // for second run

    // make heap priority queue strucutre

    for (unsigned char character = 0; character < 256; character++) {
        if (char_freq[character] != 0) {
            TreeNode *new_node = new TreeNode();
            new_node->set_char(character);
            new_node->set_freq(char_freq[index]);
        }
        node_ptrs[character] = new_node; // to get the bottom leave of character

        p_queue_add(new_node);
    }

    // while queue size < 2
    // take the smallest two, pop them, make newnode, newnode->become_root
    // push back in


    for (unsigned char character = 0; character < 256; character++) {
        if (node_ptrs[character] != nullptr) {
            node_ptrs[character]->find_path();
        }
    }
}




// make huffman_code

// make a "call back function"

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

    //TODO: Compress


    string file_str;
    unsigned char character;

    ifstream inf(input_file_name);
    while(inf.get(character)) {
        file_str += character;
    }

    string file_str;
    size = str.size();

    int char_freq [256] = {};

    for (int index = 0; index < size; index++) {
        char_freq[file_str[index]]++;
    }

    TreeNode *make_tree(char_freq);

    //next: if char_freq[n] != 0, make a character tree node as askii:freq
    // put all the treenodes into a priority queue construct
    // pop the two with fewest value, join to a new node with sum of both char_freq
    // push back... repeat until only 1 node is left

    // encode the document with tree key
    // encode the tree
    // note the # extra 0s put at the end


    return 0;
}
