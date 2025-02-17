//
// Created by dran on 2/16/25.
//

#include "StaticTrie.h"

// I really want to hide the implementations because some might find it upsetting and scary :P
template <typename CharType>
struct ChildInfo {
    CharType next_char;
    struct StaticTrieNode* next_node;
};

template <typename CharType, typename ValType>
struct StaticTrieNode {
    CharType current_char;
    ValType value;
    struct ChildInfo<CharType>[1]; // the start of a variable length array of child info
};

template <typename CharType, typename ValType>
struct StaticTrieTempNode {
    CharType current_char;
    ValType value;
    std::vector<int> freq;
    std::vector<CharType> key;
    std::vector<struct StaticTrieTempNode<CharType, ValType>> children;
};
