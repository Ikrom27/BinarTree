#pragma once
#include <list>


class BinaryTree
{
private:
    std::string value;
    int repetitions;
    BinaryTree* left;
    BinaryTree* right;
public:
    BinaryTree();
    BinaryTree(std::string val);
    std::string getValue();
    void add(std::string element);
    void addElement(BinaryTree* element);
    void display(BinaryTree* abranch, int counter);
    std::list<std::string> sort(std::list<std::string> sortedList);
};