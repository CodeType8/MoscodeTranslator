#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class BSTNode
{
public:
	// constructors and destructors
	BSTNode();
	BSTNode(string const& morse, char const& letter);
	// getters
	char & getLetter() const;
	string & getMorse();
	BSTNode *& getLeft() const;
	BSTNode *& getRight() const;
	//setters
	void setLeft(BSTNode *const& node);
	void setRight(BSTNode *const& node);
	void setMorse(string const& newMorse);
	void setLetter(char const& newLetter);
private:
	// member attributes
	char mLetter;
	string mMorse;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};
///non-member functions
ostream &operator << (ostream &lhs, BSTNode &rhs);
#endif // ! BSTNODE_H