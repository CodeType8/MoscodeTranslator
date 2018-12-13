#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
	fstream file("MorseTable.txt", std::ios::in);
	readHelper(file);
	file.close();
}
BST::~BST()
{
	deleteTree();
}
//operators
BST & BST::operator = (BST &rhs)
{
	this->deleteTree();
	this->copyHelper(rhs.getRoot(), this->getRoot());
	return *this;
}
//setters
void BST::setRoot(BSTNode *& node)
{
	mpRoot = node;
}
//getters
BSTNode *& BST::getRoot() const
{
	return (BSTNode *)mpRoot;
}
//general member functions
void BST::insertNode(string const& morse, char const& letter)
{
	insertHelper(this->getRoot(), morse, letter);
}
void BST::print()
{
	print(this->getRoot());
}

bool BST::isEmpty()
{
	return (mpRoot == nullptr);
}
string& BST::search(char target)
{
	return search(mpRoot, target);
}

void BST::deleteTree()
{
	deleteTree(this->getRoot());
}
void BST::deleteTree(BSTNode *& tree)
{
	if (tree != nullptr)
	{
		deleteTree(tree->getLeft());
		deleteTree(tree->getRight());
		delete tree;
	}
}
void BST::copyHelper(BSTNode *& copyTree, BSTNode *& destTree)
{
	if (copyTree != nullptr)
	{
		BSTNode *pMem = new BSTNode(copyTree->getMorse(), copyTree->getLetter());
		destTree = pMem;
		copyHelper(copyTree->getLeft(), destTree->getLeft());
		copyHelper(copyTree->getRight(), destTree->getRight());
	}

}
void BST::insertHelper(BSTNode *& tree, string const& morse, char const& letter)
{
	if (tree == nullptr)
	{
		BSTNode * pMem = new BSTNode(morse, letter);
		tree = pMem;
	}
	else if (letter > tree->getLetter())
	{
		insertHelper(tree->getRight(), morse, letter);
	}
	else if (letter < tree->getLetter())
	{
		insertHelper(tree->getLeft(), morse, letter);
	}
	else
	{
		cout << "Value is a copy" << endl;
	}

}
void BST::print(BSTNode *& tree)
{
	if (tree != nullptr)
		{
			print(tree->getLeft());
			cout << *tree << endl;
			print(tree->getRight());
		}
}
void  BST::readHelper(fstream &infile)
{
	while (!infile.eof())
	{
		char letter;
		char morse[100];
		infile >> letter;
		infile.getline(morse, 100);
		insertNode((string)morse, letter);
	}
}
string& BST::search(BSTNode *&tree, char target)
{	
	if (tree->getLetter() == target)
	{
		return tree->getMorse();
	}
	else if (target < tree->getLetter())
	{
		return search(tree->getLeft(), target);
	}
	else
	{
		return search(tree->getRight(), target);
	}
}