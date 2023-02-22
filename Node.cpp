#include <iostream>
#include "Node.h"

using namespace std;

/*
 * Returns the data that is stored in this node
 *
 * @return the data that is stored in this node.
 */
int Node::getData() const { return data; }

void Node::setData(int value)
{
    cout << "set data function has been called" << endl;
    cout << "setting data to " << value << endl;
    cout << "data equals " << data << endl;
    data = value;
    cout << "data equals " << data << endl;
}

/*
 * Returns the left child of this node or null if it doesn't have one.
 *
 * @return the left child of this node or null if it doesn't have one.
 */
Node *Node::getLeftChild() const { return leftChild; }

void Node::setLeftChild(Node *givenPointer) { leftChild = givenPointer; }
/*
 * Returns the right child of this node or null if it doesn't have one.
 *
 * @return the right child of this node or null if it doesn't have one.
 */
Node *Node::getRightChild() const { return rightChild; }

void Node::setRightChild(Node *givenPointer) { rightChild = givenPointer; }