#ifndef BST_H
#define BST_H

#include "BSTNodeTemplate.h"
#include <fstream>
#include <string>

using std::fstream;
using std::string;

template <class T, class Y>
class BST
{
public:
	//construcctors and destructors
	BST();
	~BST();

	//setters
	void setRoot(BSTNode<T, Y> *& node);

	//getters
	BSTNode<T, Y> *& getRoot();

	//general member functions
	void insertNode(T const & morse, Y const & letter);
	bool isEmpty();
	void print();
	T& search(char target);
private:
	// member attributes
	BSTNode<T, Y> *mpRoot;

	//private Funtions
	T& search(BSTNode<T, Y> *&tree, Y target);
	void print(BSTNode<T, Y> *& tree);
	void deleteTree();
	void deleteTree(BSTNode<T, Y> *& tree);
	void insertHelper(BSTNode<T, Y> *& tree, T const & morse, Y const & letter);
	void read(fstream &infile);
};
//construcctors and destructors
template <class T, class Y>
BST<T, Y>::BST()
{
	mpRoot = nullptr;
	fstream file("MorseTable.txt", std::ios::in);
	read(file);
	file.close();
}
template <class T, class Y>
BST<T, Y>::~BST()
{
	deleteTree();
}
//setters
template <class T, class Y>
void BST<T, Y>::setRoot(BSTNode<T, Y> *& node)
{
	mpRoot = node;
}
//getters
template <class T, class Y>
BSTNode<T, Y> *& BST<T, Y>::getRoot()
{
	return mpRoot;
}
//general member functions
template <class T, class Y>
void BST<T, Y>::insertNode(T const & morse, Y const & letter)
{
	insertHelper(this->getRoot(), morse, letter);
}
template <class T, class Y>
bool BST<T, Y>::isEmpty()
{
	return (mpRoot == nullptr);
}
template <class T, class Y>
void BST<T, Y>::print()
{
	print(this->getRoot());
}
template <class T, class Y>
T& BST<T, Y>::search(char target)
{
	return search(mpRoot, target);
}
//private Funtions
template <class T, class Y>
T& BST<T, Y>::search(BSTNode<T, Y> *&tree, Y target)
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
template <class T, class Y>
void BST<T, Y>::print(BSTNode<T, Y> *& tree)
{
	if (tree != nullptr)
	{
		print(tree->getLeft());
		cout << tree->getLetter() <<  " = "  << tree->getMorse() << endl;
		//cout << *tree << endl; errors eith the friend function
		print(tree->getRight());
	}
}
template <class T, class Y>
void BST<T, Y>::deleteTree()
{
	deleteTree(this->getRoot());
}
template <class T, class Y>
void BST<T, Y>::deleteTree(BSTNode<T, Y> *& tree)
{
	if (tree != nullptr)
	{
		deleteTree(tree->getLeft());
		deleteTree(tree->getRight());
		delete tree;
	}
}
template <class T, class Y>
void BST<T, Y>::insertHelper(BSTNode<T, Y> *& tree, T const & morse, Y const & letter)
{
	if (tree == nullptr)
	{
		BSTNode<T, Y> * pMem = new BSTNode<T, Y>(morse, letter);
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
template <class T, class Y>
void BST<T, Y>::read(fstream &infile)
{
	while (!infile.eof())
	{
		Y letter;
		char morse[100];
		infile >> letter;
		infile.getline(morse, 100);
		insertNode((T)morse, letter);
	}
}
#endif // !BST_H