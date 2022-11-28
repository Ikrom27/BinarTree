#include <iostream>
#include "BinaryTree.h"
#include <vector>
#include <fstream>
#include <regex>

std::string textFormat(std::string word) {
	std::string formated = "";
	for (auto i : word) {
		if ((i > 'A' and i < 'Z') or
			(i > 'a' and i < 'z') or
			(i > '0' and i < '9'))
		{
			formated += i;
		}
		else { return formated; }
	}
	return	formated;
}

void reader() {
	std::fstream file;
	std::string word, filename;
	BinaryTree* tree = new BinaryTree();

	filename = "text.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		if (textFormat(word).length() > 0) {
			tree->add(textFormat(word));
		}
	}
	tree->display(tree, 0);
	std::list<std::string> sl;
	sl = tree->sort(sl);
	for (auto i : sl) {
		std::cout << i << std::endl;
	}
}

int main()
{
	reader();
}
