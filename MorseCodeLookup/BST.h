#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <fstream>
#include <string>

using std::fstream;

class BST
{
public:
	//construcctors and destructors
	BST();
	~BST();

	//operators
	BST &operator = (BST &rhs);

	//setters
	void setRoot(BSTNode *& node);

	//getters
	BSTNode *& getRoot() const;

	//general member functions
	void insertNode(string const & morse, char const & letter);
	void inOrderTransversal();
	void preOrderTransversal();
	void postOrderTransversal();
	bool isEmpty();
	void print();
	string& search(char target);
private:
	// member attributes
	BSTNode *mpRoot;

	//private Funtions
	string& search(BSTNode *&tree, char target);
	void print(BSTNode *& tree);
	void inOrderTransversal(BSTNode *& tree);
	void preOrderTransversal(BSTNode *& tree);
	void postOrderTransversal(BSTNode *& tree);
	void deleteTree();
	void deleteTree(BSTNode *& tree);
	void copyHelper(BSTNode *& copyTree, BSTNode *& destTree);
	void insertHelper(BSTNode *& tree, string const & morse, char const & letter);
	void readHelper(fstream &infile);
};

#endif // !BST_H