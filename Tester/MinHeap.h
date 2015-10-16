//
//  MinHeap.h
//  
//
//  Created by Gavin Scheele on 10/11/15.
//
//

#ifndef ____MinHeap__
#define ____MinHeap__

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

template <typename T>

class MinHeap{
public:
    MinHeap();
    ~MinHeap();
    bool insert(T data);
    void printMin();
    void removeMin();
    void printMH();

    struct Node{
        Node(T data, Node *left, Node *right, Node *parent, bool isLeftNode){
            this->data = new T(data);
            this->left = left;
            this->right = right;
            this->parent = parent;
            this->isLeftNode = isLeftNode;
        }
        ~Node(){
            delete[] this->data;
        }
        void print(){
            std::cout << *this->data;
        }

        T *data;
        Node *left;
        Node *right;
        Node *parent;
        bool isLeftNode;
    };
    

private:
    Node* findInsertionPoint(char &leftOrRight);
    Node* findInsertionPointRight(int &level, char &leftOrRight);
    void postOrder(Node* n, int indent=50);
    Node *min;
    Node *newestNode; //node that was most recently added to the heap.
    void swapNodes(Node *child, Node *parent);

};





//Implementation
template<typename T>
MinHeap<T>::MinHeap(){
    
}

template<typename T>
MinHeap<T>::~MinHeap(){
    
}

template<typename T>
void MinHeap<T>::printMH(){
    if(min == nullptr){
        std::cout << "The heap is empty" << std::endl;
    }
    postOrder(min);
}

template<typename T>
bool MinHeap<T>::insert(T data){
    if (this->min == nullptr) {
        Node *newMin = new Node(data, nullptr, nullptr, nullptr, false);
        min = newMin;
        newestNode = newMin;
    }
    else{
        char leftOrRight = 'z';
        Node *insertionPoint = findInsertionPoint(leftOrRight);
        Node *newNode;
        if(leftOrRight == 'l'){
            insertionPoint->left = new Node(data, nullptr, nullptr, insertionPoint, true);
            newNode = insertionPoint->left;
        }
        else if(leftOrRight == 'r'){
            insertionPoint->right = new Node(data, nullptr, nullptr, insertionPoint, false);
            newNode = insertionPoint->right;
        }

        
        while (newNode->parent && (*newNode->data < *newNode->parent->data) ) {
            swapNodes(newNode, newNode->parent);
        }
        newestNode = newNode;

    }
    return true;
}


template<typename T>
void MinHeap<T>::swapNodes(Node *child, Node *parent){
    T *temp = child->data;
    child->data = parent->data;
    parent->data = temp;
}


template<typename T>
void MinHeap<T>::printMin(){
    if(min)
        std::cout << *min->data << std::endl;
    else
        std::cout << "The heap is empty" << std::endl;
}

template<typename T>
void MinHeap<T>::removeMin(){
    if(min == nullptr){
        std::cout << "The heap is empty" << std::endl;
        return;
    }
    if(*newestNode->data == *min->data){
        std::cout << *min->data << " has been deleted" << std::endl;
        min = nullptr;
        return;
    }
    
    if (newestNode->isLeftNode) {
        newestNode->parent->left = nullptr;
    }
    else
        newestNode->parent->right = nullptr;
    
    std::cout << *min->data << " has been deleted" << std::endl;
    
    //make the newest node the new root
    min->data = newestNode->data;
    
    bool done = false;
    Node *temp = min;
    while(!done){
        if(temp->left && temp->right){
            if (*temp->left->data < *temp->right->data &&
                *temp->left->data < *temp->data) {
        
                swapNodes(temp->left, temp);
                temp = temp->left;
            }
            else if(*temp->right->data < *temp->left->data &&
                    *temp->right->data < *temp->data){
        
                swapNodes(temp->right, temp);
                temp = temp->right;
            }
        }
        else if(temp->left && !temp->right &&
                (*temp->left->data < *temp->data)){
                
            swapNodes(temp->left, temp);
            temp = temp->left;
        }
        else if(!temp->left && temp->right &&
                (*temp->right->data < *temp->data)){
            
            swapNodes(temp->right, temp);
            temp = temp->right;
        }
        else
            done = true;
        
        }

    
    
}



template<typename T>
void MinHeap<T>::postOrder(Node* n, int indent)
{
    if(n) {
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        n->print();
        std::cout << "\n";

        if(n->left != nullptr) postOrder(n->left, indent-4);
        if(indent == 50) indent = 60;
        if(n->right != nullptr) postOrder(n->right, indent+4);
    }
}


template<typename T>
typename MinHeap<T>::Node* MinHeap<T>::findInsertionPoint(char &leftOrRight){
    int leftLevel = 0;
    Node *temp = min;
    while (temp->left != nullptr && temp->right != nullptr) {
        leftLevel++;
        temp = temp->left;
    }
    
    int rightLevel = 0;
    Node *insertionPointRight = findInsertionPointRight(rightLevel, leftOrRight);
    
    if(leftLevel <= rightLevel){
        if(temp->left == nullptr){
            leftOrRight = 'l';
            return temp;
        }
        else if(temp->right == nullptr){
            leftOrRight = 'r';
            return temp;
        }
    }
    else
        return insertionPointRight;
    
    return nullptr;
}

template<typename T>
typename MinHeap<T>::Node* MinHeap<T>::findInsertionPointRight(int &level, char &leftOrRight){
    Node *temp = min;
    while (temp->left != nullptr && temp->right != nullptr) {
        level++;
        temp = temp->right;
    }
    
    if(temp->left == nullptr){
        leftOrRight = 'l';
        return temp;
    }
    else if(temp->right == nullptr){
        leftOrRight = 'r';
        return temp;
    }
    else return nullptr;
}

#endif /* defined(____MinHeap__) */
