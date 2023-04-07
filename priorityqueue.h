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
        
        
        // TO DO: write this function.
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
        
        
        // TO DO: write this function.
        T valueOut;
        return valueOut; // TO DO: update this return
        
        
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
        
        
        // TO DO: write this function.
        
        
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
        
        
        // TO DO: write this function.
        return true; // TO DO: update this return
        
        
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
        
        
        // TO DO: write this function.
        T valueOut;
        return valueOut; // TO DO: update this return
        
        
    }
    
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {
        
        
        // TO DO: write this function.
        return true; // TO DO: update this return
        
        
    }
    
    //Helper function to push a node to the back of a linked list of duplicate priorities
    void LinkedPushBack(NODE* currNode, NODE* newNode){

        //Create a pointer to the head of the linked list to make sure we dont lose the head of the linked list
        NODE* linkedHead = currNode;

        //If the current node is the last node in the linked list, set the current node's link to the new node
        if(linkedHead->link == nullptr){
            linkedHead->link = newNode;
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

    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};
