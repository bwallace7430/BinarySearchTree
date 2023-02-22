#include "Node.h"
#include "BST.h"
#include <iostream>

using namespace std;

// Please note that the class that implements this interface must be made
// of objects which implement the NodeInterface

BST::~BST()
{
    clear(rootNode);
}
/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
Node *BST::getRootNode() const { return rootNode; }

/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool BST::add(int data)
{
    cout << "Entering add function" << endl;

    if (rootNode == NULL)
    {
        cout << "rootNode equals NULL" << endl;
        rootNode = new Node();
        rootNode->setData(data);
        cout << "data has been set" << endl;
        cout << "returning true" << endl;
        return true;
        cout << "did not return true" << endl;
    }

    // Node *tracker = rootNode; ASK JONAH AB WHY THIS DOESNT WORK IF ROOTNODE IS NULL

    Node *tracker = rootNode;

    cout << "tracker->getData equals " << tracker->getData() << endl;
    cout << "Entering while loop" << endl;
    while (true)
    {
        if (data < tracker->getData())
        {
            cout << "Checking if trackerLeftCHild is NULL" << endl;
            if (tracker->getLeftChild() == nullptr)
            {
                tracker->setLeftChild(new Node());
                tracker->getLeftChild()->setData(data);

                cout << "tracker value has been switched to: " << tracker->getLeftChild()->getData() << endl;
                cout << "Exiting add function: true" << endl;
                return true;
            }

            cout << "tracker switching values: left" << endl;
            tracker = tracker->getLeftChild();
            cout << "tracker value is now: " << tracker->getData() << endl;
        }
        else if (data > tracker->getData())
        {
            if (tracker->getRightChild() == nullptr)
            {
                cout << "Checking if trackerrightCHild is NULL" << endl;
                tracker->setRightChild(new Node());
                tracker->getRightChild()->setData(data);

                cout << "tracker value has been switched to: " << tracker->getRightChild()->getData() << endl;
                cout << "Exiting add function: true" << endl;
                return true;
            }

            cout << "tracker switching values: right" << endl;
            tracker = tracker->getRightChild();
            cout << "tracker value is now: " << tracker->getData() << endl;
        }

        else if (data == tracker->getData())
        {
            cout << "value is already in tree" << endl;
            return false;
        }
    }
}

/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool BST::remove(int data)
{
    cout << "removing " << data << endl;
    cout << "checking if data equals rootNode" << endl;
    if (data == rootNode->getData())
    {
        cout << "checking if rootNode has children" << endl;
        if (rootNode->getLeftChild() == nullptr && rootNode->getRightChild() == nullptr)
        {
            cout << "rootNode has no children. deleting rootNode" << endl;
            delete rootNode;
            rootNode = nullptr;
            return true;
        }
        if (rootNode->getLeftChild() == nullptr)
        {
            Node *temporary = rootNode;
            rootNode = rootNode->getRightChild();
            delete temporary;
            return true;
        }
        if (rootNode->getRightChild() == nullptr)
        {
            Node *temporary = rootNode;
            rootNode = rootNode->getLeftChild();
            delete temporary;
            return true;
        }
    }
    remove(data, rootNode);
    cout << "something strange... in my neighborhood... whom i gonna call?" << endl;
    return true;
    cout << "past the point of no return" << endl;
}

bool BST::remove(int data, Node *currentNode)
{
    cout << "entering recursive remove function" << endl;
    Node *child = rootNode;
    if (data > currentNode->getData())
    {
        cout << "setting child to currentNode->getRightChild" << endl;
        child = currentNode->getRightChild();
    }
    else if (data < currentNode->getData())
    {
        cout << "setting child to currentNode->getLeftChild" << endl;
        child = currentNode->getLeftChild();
    }

    if (child == nullptr)
    {
        cout << "data was not found" << endl;
        return false;
    }
    else if (data == child->getData())
    {
        cout << "data has been found." << endl;
        if (child->getLeftChild() == nullptr && child->getRightChild() == nullptr)
        {
            cout << "no children are had" << endl;
            if (child == currentNode->getLeftChild())
            {
                currentNode->setLeftChild(nullptr);
            }
            else if (child == currentNode->getRightChild())
            {
                currentNode->setRightChild(nullptr);
            }

            delete child;
            return true;
        }
        else if (child->getLeftChild() == nullptr)
        {
            cout << "it has one right child" << endl;
            if (child == currentNode->getLeftChild())
            {
                currentNode->setLeftChild(child->getRightChild());
            }
            else if (child == currentNode->getRightChild())
            {
                currentNode->setRightChild(child->getRightChild());
            }

            Node *temporary = child;
            child = child->getRightChild();
            delete temporary;
            return true;
        }
        else if (child->getRightChild() == nullptr)
        {
            cout << "it has one left child" << endl;
            if (child == currentNode->getLeftChild())
            {
                currentNode->setLeftChild(child->getLeftChild());
            }
            else if (child == currentNode->getRightChild())
            {
                currentNode->setRightChild(child->getLeftChild());
            }

            Node *temporary = child;
            child = child->getLeftChild();
            delete temporary;
            return true;
        }
        else
        {
            cout << "it has two children... sucks to suck." << endl;
            Node *temporary = child->getLeftChild();
            Node *parent = nullptr;
            while (temporary->getRightChild() != nullptr)
            {
                cout << "infinite loop" << endl;
                parent = temporary;
                temporary = temporary->getRightChild();
            }

            child->setData(temporary->getData());
            if (parent != nullptr)
            {
                parent->setRightChild(temporary->getLeftChild());
            }
            else
            {
                child->setLeftChild(temporary->getLeftChild());
            }
            delete temporary;

            return true;
            cout << "we are past the point of no return." << endl;
        }
    }
    else
    {
        remove(data, child);
        cout << "unwinding recursion" << endl;
    }
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void BST::clear()
{
    clear(rootNode);
    cout << "rootNode being set to nullptr" << endl;
    rootNode = nullptr;
}

void BST::clear(Node *currentNode)
{
    cout << "entering clear recursive function" << endl;
    if (currentNode == nullptr)
    {
        return;
    }
    if (currentNode->getLeftChild() != nullptr)
    {
        cout << "clearing left tree of " << currentNode->getData();
        clear(currentNode->getLeftChild());
    }
    else if (currentNode->getRightChild() != nullptr)
    {
        cout << "clearing right tree of " << currentNode->getData();
        clear(currentNode->getRightChild());
    }
    cout << "deleting " << currentNode->getData();
    delete currentNode;
}