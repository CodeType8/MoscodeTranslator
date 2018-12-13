#include "BSTNode.h"

BSTNode::BSTNode()
{
	mMorse = "";
	mLetter = '\0';
	mpLeft = nullptr;
	mpRight = nullptr;
}
BSTNode::BSTNode(string const& morse, char const& letter)
{
	setMorse(morse);
	setLetter(letter);
	mpLeft = nullptr;
	mpRight = nullptr;
}
// getters
string& BSTNode::getMorse()
{
	return mMorse;
}
BSTNode *& BSTNode::getLeft() const
{
	return (BSTNode *&)mpLeft;
}
BSTNode *& BSTNode::getRight() const
{
	return (BSTNode *&)mpRight;
}
char & BSTNode::getLetter() const
{
	return (char)mLetter;
}
//setters
void BSTNode::setLeft(BSTNode *const& node)
{
	mpLeft = node;
}
void BSTNode::setRight(BSTNode *const& node)
{
	mpRight = node;
}
void BSTNode::setMorse(string const& newMorse)
{
	mMorse = newMorse;
}
void BSTNode::setLetter(char const& newLetter)
{
	mLetter = newLetter;
}

ostream &operator << (ostream &lhs, BSTNode &rhs)
{
	cout << rhs.getLetter() << '=' << rhs.getMorse();
	return lhs;
}