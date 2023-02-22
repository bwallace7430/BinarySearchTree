#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "NodeInterface.h"

class Node : public NodeInterface
{
private:
    int data;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;

public:
    Node() {}
    ~Node() {}

    /*
     * Returns the data that is stored in this node
     *
     * @return the data that is stored in this node.
     */
    int getData() const override;
    void setData(int value);

    /*
     * Returns the left child of this node or null if it doesn't have one.
     *
     * @return the left child of this node or null if it doesn't have one.
     */
    Node *getLeftChild() const override;
    void setLeftChild(Node *givenPointer);

    /*
     * Returns the right child of this node or null if it doesn't have one.
     *
     * @return the right child of this node or null if it doesn't have one.
     */
    Node *getRightChild() const override;
    void setRightChild(Node *givenPointer);
};
#endif