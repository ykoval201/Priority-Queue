/// @file priorityqueue.h
///
///
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

#pragma once

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)
    
public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {

        root = nullptr;
        size = 0;
        curr = nullptr;

    }
    
    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other) {
        
        // Check for self-assignment
    if (this == &other) {
        return *this;
    }

    // Clear the current priority queue
    this->clear();

    // Perform a deep copy of the other priority queue
    this->root = recursiveCopy(other.root);
    this->size = other.size;
    this->curr = nullptr; // Reset the curr pointer as it's not needed for deep copy

    return *this;
    }
    
    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() {

        recursiveClear(root);
        root = nullptr;
        size = 0;
   
    }
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {
        
        
      clear();
        
        
    }
    
    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    void enqueue(T value, int priority) {

        //Create a new Node to be put into a tree
        NODE* newNode = new NODE;
        newNode->value = value;
        newNode->priority = priority;
        newNode->dup = false;
        newNode->parent = nullptr;
        newNode->link = nullptr;
        newNode->left = nullptr;
        newNode->right = nullptr;

        //If this node is firt node in tree, set root to equall to this node
        if (root == nullptr) {
            root = newNode;
            size++;
            return;
        }

        //Create a pointer to the root node to traverse the tree
        NODE* currNode = root;
        NODE* prevNode = nullptr;


        //STEP 1: SEARCH
        //Traverse the tree until we find the correct location to insert the new node
        while(currNode  != nullptr){

            if(currNode->priority == priority){ //Duplicate priority found 

            //Emplace the node into the linked list of the same priority of the current node
            LinkedPushBack(currNode, newNode);
            currNode->dup = true;//Mark the current node as having duplicate priorities
            size++;
            return;

            }

            if(currNode->priority > priority){ //go left

                prevNode = currNode;
                currNode = currNode->left;
            }

            else{ //go right

                prevNode = currNode;
                currNode = currNode->right;
            }
            
        }
        //STEP 2: INSERT

       if(priority < prevNode->priority){
         prevNode->left = newNode;
         newNode->parent = prevNode;
       }
       else{
            prevNode->right = newNode;
            newNode->parent = prevNode;
       }


       //Step 3: Update size

         size++;
 
    }
    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T dequeue() {
    // Check if the priority queue is empty
    if (root == nullptr) {
        T value = T();
        return value;
    }

    // Find the first node (minimum priority) in the priority queue
    NODE* firstNode = root;
    while (firstNode->left != nullptr) {
        firstNode = firstNode->left;
    }

    // Save the value to be returned
    T valueOut = firstNode->value;

    // If the first node has a linked list of duplicate priorities
    if (firstNode->link != nullptr) {
        NODE* nextNode = firstNode->link;
        // Update the links and pointers
        if (firstNode->right != nullptr) {
            nextNode->right = firstNode->right;
            firstNode->right->parent = nextNode;
        }
        nextNode->parent = firstNode->parent;
        if (firstNode->parent != nullptr) {
            if (firstNode->parent->left == firstNode) {
                firstNode->parent->left = nextNode;
            } else {
                firstNode->parent->right = nextNode;
            }
        } else {
            root = nextNode;
        }
    } else {
        // If the first node has a right child, update the links and pointers
        if (firstNode->right != nullptr) {
            firstNode->right->parent = firstNode->parent;
            if (firstNode->parent != nullptr) {
                firstNode->parent->left = firstNode->right;
            } else {
                root = firstNode->right;
            }
        } else {
            // If the first node is a leaf node, update the parent's link
            if (firstNode->parent != nullptr) {
                firstNode->parent->left = nullptr;
            } else {
                root = nullptr;
            }
        }
    }

    // Delete the first node and decrement the size
    delete firstNode;
    size--;

    return valueOut;
}

    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        
        return size;
    }
    
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
        
        curr = root;
    while (curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
    }

    }
    
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority) {
    // If curr is nullptr, we've reached the end of the inorder traversal
    if (curr == nullptr) {
        return false;
    }
    
    // Set the value and priority to the current node's value and priority
    value = curr->value;
    priority = curr->priority;

    // Check if there is any node left in the linked list of duplicate priorities
    if (curr->link != nullptr) {
        curr = curr->link;
    } else {
        // Move back to the root of the linked list of nodes with the same priority
        while (curr->parent != nullptr && curr->parent->link == curr) {
            curr = curr->parent;
        }
        // If the current node has a right child, find the leftmost node in the right subtree
        if (curr->right != nullptr) {
            curr = curr->right;
            while (curr->left != nullptr) {
                curr = curr->left;
            }
        } else {
            // If the current node has no right child, move up the tree until we find a node that is the left child of its parent
            while (curr->parent != nullptr && curr == curr->parent->right) {
                curr = curr->parent;
            }
            // If the parent exists, move to the parent
            if (curr->parent != nullptr) {
                curr = curr->parent;
            } else {
                // If the parent is nullptr, we've reached the end of the inorder traversal
                curr = nullptr;
                return false;
            }
        }
    }
    
    return true;
}
    
    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {
        
        
        stringstream ss;
        buildStream(root, ss);
        return ss.str();
        
    }
    
    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T peek() {
        
      // Check if the priority queue is empty
    if (root == nullptr) {
        T value = T();
        return value;
    }

    NODE* firstNode = root;
    while(firstNode->left != nullptr) {
        firstNode = firstNode->left;
    }   

    return firstNode->value;
        
    }
    
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {
        
        return recursiveEqual(root, other.root);
        
    }

    //*************************HELPER FUNCTIONS************************************//
    
    //Helper function to push a node to the back of a linked list of duplicate priorities
    void LinkedPushBack(NODE* currNode, NODE* newNode){

        //Create a pointer to the head of the linked list to make sure we dont lose the head of the linked list
        NODE* linkedHead = currNode;

        //If the current node is the last node in the linked list, set the current node's link to the new node
        // and set its parent to the current node
        if(linkedHead->link == nullptr){
            linkedHead->link = newNode;
            newNode->parent = linkedHead;
            return;
        }

        //If the current node is not the last node in the linked list, traverse the linked list until the last node is found
        LinkedPushBack(linkedHead->link, newNode);

    }

    //Helper function to build a string recursively into a stream and return the stream
    // Helper function
    void buildStream(NODE* node, ostream& output) {
        if (node == nullptr) {
            return;
        }

        // Traverse the left subtree
        buildStream(node->left, output);

        // Output the current node's priority and value
        output << node->priority << " value: " << node->value << endl;

        // Output the linked list of duplicate priorities
        NODE* dupNode = node->link;
        while (dupNode != nullptr) {
            output << dupNode->priority << " value: " << dupNode->value << endl;
            dupNode = dupNode->link;
        }

        // Traverse the right subtree
        buildStream(node->right, output);
    }
    
    //Helper function to recursively delete all nodes in the tree
    void recursiveClear(NODE* node) {
    if (node == nullptr) {
        return;
    }

    // Traverse the left subtree
    recursiveClear(node->left);

    // Traverse the right subtree
    recursiveClear(node->right);

    // Delete the linked list of duplicate priorities
    NODE* dupNode = node->link;
    NODE* nextDupNode = nullptr;

    while (dupNode != nullptr) {
        nextDupNode = dupNode->link;
        delete dupNode;
        dupNode = nextDupNode;
    }

    // Delete the current node
    delete node;
}

    //Helper function to recursively copy all nodes in the tree
   NODE* recursiveCopy(NODE* otherNode) {
    if (otherNode == nullptr) {
        return nullptr;
    }

    // Create a new node and copy the data
    NODE* newNode = new NODE;
    newNode->priority = otherNode->priority;
    newNode->value = otherNode->value;
    newNode->dup = otherNode->dup;
    newNode->parent = nullptr;
    newNode->link = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Copy the linked list of nodes with duplicate priorities
    NODE* otherDupNode = otherNode->link;
    NODE* newDupNode = nullptr;

    while (otherDupNode != nullptr) {
        NODE* tempDupNode = new NODE;
        tempDupNode->priority = otherDupNode->priority;
        tempDupNode->value = otherDupNode->value;
        tempDupNode->dup = otherDupNode->dup;
        tempDupNode->parent = nullptr;
        tempDupNode->link = nullptr;
        tempDupNode->left = nullptr;
        tempDupNode->right = nullptr;

        if (newNode->link == nullptr) {
            newNode->link = tempDupNode;
        } else {
            newDupNode->link = tempDupNode;
        }

        newDupNode = tempDupNode;
        otherDupNode = otherDupNode->link;
    }

    // Copy the left and right subtrees
    newNode->left = recursiveCopy(otherNode->left);
    newNode->right = recursiveCopy(otherNode->right);

    return newNode;
}
    
   //Helper function to determine if two trees are equal
    bool recursiveEqual(NODE* node, NODE* otherNode) const {
    //Base cases
    if (node == nullptr && otherNode == nullptr) {
        return true;
    } 
    else if (node == nullptr || otherNode == nullptr) {
        return false;
    }
    else{

        if( node->value != otherNode->value ||
            node->priority != otherNode->priority ||
            node->dup != otherNode->dup){
            return false;
        }

        if(recursiveEqual(node->left, otherNode->left) && recursiveEqual(node->right, otherNode->right) && recursiveEqual(node->link, otherNode->link)){ 
            return true;
        }
        else{
            return false;
        }

    }
 }
    


    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};
