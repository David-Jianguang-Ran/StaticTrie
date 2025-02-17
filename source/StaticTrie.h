//
// Created by dran on 2/16/25.
//

#ifndef STATICTRIE_STATICTRIE_H
#define STATICTRIE_STATICTRIE_H

#include <memory>
#include <vector>


template <typename CharType, typename ValType>
struct StaticTrieNode;

template <typename CharType, typename ValType>
struct StaticTrieTempNode;

template <typename CharType, typename StringType, typename ValType>
class StaticTrie {
public:
    StaticTrie();
    ~StaticTrie();

    bool add_entry(StringType s, ValType v);

    // Marking this trie ready for lookup
    // internally there are a lot of reordering and copying to make sure this trie is small and cache friendly
    // adding before commit or looking up before commit will throw exceptions
    bool commit();

    std::vector<std::pair<StringType,ValType>> lookup_all_prefix(StringType s);

    ValType lookup_exact(StringType s);
private:
    std::shared_ptr<struct StaticTrieNode<CharType, ValType>> storage;
    std::vector<struct StaticTrieTempNode<CharType, ValType>> temp_nodes;
    bool committed;
};

#endif //STATICTRIE_STATICTRIE_H
