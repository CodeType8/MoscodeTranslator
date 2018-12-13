#ifndef BSTNODETEMPLATE_H
#define BSTNODETEMPLATE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

//template <class T, class Y>
//class BSTNode;
//template <class T, class Y>
//ostream &operator << (ostream &lhs, BSTNode<T, Y> &rhs);

template <class T, class Y>
class BSTNode
{
public:
	// constructors and destructors
	BSTNode();
	BSTNode(T const& morse, Y const& letter);
	// getters
	Y & getLetter();
	T & getMorse();
	BSTNode *& getLeft();
	BSTNode *& getRight();
	//setters
	void setLeft(BSTNode *const& node);
	void setRight(BSTNode *const& node);
	void setMorse(T const& newMorse);
	void setLetter(Y const& newLetter);
	//general
	friend ostream &operator << (ostream &lhs, BSTNode<T, Y> &rhs);
private:
	// member attributes
	Y mLetter;
	T mMorse;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};
// constructors and destructors
template <class T, class Y>
BSTNode<T, Y>::BSTNode()
{
	mMorse;
	mLetter;
	mpLeft = nullptr;
	mpRight = nullptr;
}
template <class T, class Y>
BSTNode<T, Y>::BSTNode(T const& morse, Y const& letter)
{
	setMorse(morse);
	setLetter(letter);
	mpLeft = nullptr;
	mpRight = nullptr;
}
// getters
template <class T, class Y>
Y & BSTNode<T, Y>::getLetter()
{
	return mLetter;
}
template <class T, class Y>
T & BSTNode<T, Y>::getMorse()
{
	return mMorse;
}
template <class T, class Y>
BSTNode<T, Y> *& BSTNode<T, Y>::getLeft()
{
	return mpLeft;
}
template <class T, class Y>
BSTNode<T, Y> *& BSTNode<T, Y>::getRight()
{
	return mpRight;
}
//setters
template <class T, class Y>
void BSTNode<T, Y>::setLeft(BSTNode *const& node)
{
	mpLeft = node;
}
template <class T, class Y>
void BSTNode<T, Y>::setRight(BSTNode *const& node)
{
	mpRight = node;
}
template <class T, class Y>
void BSTNode<T, Y>::setMorse(T const& newMorse)
{
	mMorse = newMorse;
}
template <class T, class Y>
void BSTNode<T, Y>::setLetter(Y const& newLetter)
{
	mLetter = newLetter;
}
template <class T, class Y>
ostream &operator << (ostream &lhs, BSTNode<T, Y> &rhs)
{
	cout << rhs.getLetter() << " = " << rhs.getMorse();
	return lhs;
}
#endif // ! BSTNODETEMPLATE_H