#include <iostream>
#include "BinaryTree.h"
#include <string>

BinaryTree::BinaryTree()
{
    value = "";
    repetitions = 0;
    left = nullptr;
    right = nullptr;
}

BinaryTree::BinaryTree(std::string val) {
    value = val;
    repetitions = 1;
    left = nullptr;
    right = nullptr;
}

std::string BinaryTree::getValue() {
    return value;
}

void BinaryTree::add(std::string element)
{
    if (value == "") {
        value = element;
        repetitions++;
    }
    else {
        BinaryTree* node = new BinaryTree(element);
        addElement(node);
    }
}

void BinaryTree::addElement(BinaryTree* element) {
    for (int i = 0; i < value.length(); i++) {
        if (value[i] > element->getValue()[i]) {
            if (left != nullptr) {
                left->addElement(element);
            }
            else {
                left = element;
            }
            return;
        }
        else if (value[i] < element->getValue()[i]) {
            if (right != nullptr) {
                right->addElement(element);
            }
            else {
                right = element;
            }
            return;
        }
    }
    repetitions++;
}

void BinaryTree::display(BinaryTree* abranch, int counter)
{
    if (!abranch) return;
    counter+= 11;
    display(abranch->left, counter);
    for (int i = 0; i < counter; i++){
        std::cout << " ";
    }
    std::cout << abranch->getValue() << std::endl;
    display(abranch->right, counter);
    counter = counter - 5;
    return;
}

std::list<std::string> BinaryTree::sort(std::list<std::string> sortedList)
{
    if (left == right and right == nullptr) {
        sortedList.push_back(getValue() + " - " + std::to_string(repetitions));
        return sortedList;
    }
    else {
        if (left != nullptr) {
            sortedList = left->sort(sortedList);
        }
        sortedList.push_back(getValue() + " - " + std::to_string(repetitions));
        if (right != nullptr) {
            sortedList = right->sort(sortedList);
        }
    }
    return sortedList;
}
