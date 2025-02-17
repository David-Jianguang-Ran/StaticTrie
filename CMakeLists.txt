cmake_minimum_required(VERSION 3.10)

project(TrieTest)

# Find Google Test
find_package(GTest REQUIRED)

# Add the test library as a subdirectory
add_subdirectory(source)

# Create the trie_test executable
add_executable(trie_test test/trie_test.cpp)

# Link the trie_test executable with the test library and Google Test
target_link_libraries(trie_test trie gtest_main)

# Enable testing
enable_testing()

# Add a source target
add_test(NAME TrieTests COMMAND trie_test)