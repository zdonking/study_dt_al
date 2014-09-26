//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// two ways to implement a binary search tree...

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#ifndef BST_HH
#define BST_HH

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// the BSTNode class is what we're making the binary search tree out of

template<typename T>
class BSTNode
{
public: 

  BSTNode(T theKey) { key = theKey; left = NULL; right = NULL; number = 1; }
  BSTNode(T theKey, BSTNode<T> *theLeft, BSTNode<T> *theRight) { key = theKey; left = theLeft; right = theRight; number = 1; }

  const T & getKey() { return key; }
  void setKey(T theKey) { key = theKey; }

  BSTNode<T> *getLeft() { return left; }
  void setLeft(BSTNode<T> * theLeft) { left = theLeft; }

  BSTNode<T> *getRight() { return right; }
  void setRight(BSTNode<T> * theRight) { right = theRight; }

  void print() { cout << key << " (" << number << ")" << endl; }

private:

  T key;

  BSTNode<T> *left;   // link to left child
  BSTNode<T> *right;  // link to right child
  int number;         // how many occurrences of key there are

};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// BSTREE_FAST
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// a binary search tree, implemented as a linked structure

// this is only partial--there's no remove functionality, for example

template<typename T>
class BSTree_Fast
{
public:
  
  BSTree_Fast() { maxDepth = 0; root = NULL; }  // make an empty BST

  void insert(T &);                             // put a key into the BST 
  bool contains(T &);                           // does this BST contain a certain key?
  const T & findMax();                          // what is the smallest key in the BST?

  int getMaxDepth() { return maxDepth; }
  void print_by_order();

private:

  int maxDepth;

  BSTNode<T> *root;                             // pointer to the node at the root of the tree
  int insertNode(BSTNode<T> *node,T &,int curtime);
  void print_node(BSTNode<T> *node );
  bool contains(BSTNode<T> *node,T & );
  int getTotalNumber(BSTNode<T> *node);

};

//DONE
//print all keys from smallest to largest
template<typename T>
void BSTree_Fast<T>::print_by_order(){
  if(!root){
    cout<<"This is empty BSTree"<<endl;
    return ;
  }
  print_node(root);
  int total_number=getTotalNumber(root);
  cout<<"tree maximum:"<<maxDepth<<endl;

}

template<typename T>
void BSTree_Fast<T>::print_node(BSTNode<T> *node ){
  if(node->getLeft()){
     print_node(node->getLeft());
  }
  if(node->getRight()){
    node->print();
    print_node(node->getRight());
  }
  if(!(node->getLeft())&&!(node->getRight())){
    node->print();
  }
}
//----------------------------------------------------------------------------
//TODO need test 
template<typename T>
void BSTree_Fast<T>::insert(T & key)
{
  if(!root){
    BSTNode<T> *r=new BSTNode<T>(key);
    root=r;
    maxDepth=1;
    return ;
  }
  int temp=1;
  int curtime=insertNode(root,key,temp);
  if(curtime>maxDepth){
    maxDepth=curtime;
  }
}
template<typename T>
int BSTree_Fast<T>::insertNode(BSTNode<T> *node,T & key,int curtime ){
  curtime++;
  if(key<node->getKey()){
    if(!node->getLeft()){
      node->setLeft(new BSTNode<T>(key));
    }else{
      node=node->getLeft();
      curtime=insertNode(node,key,curtime);
    }
  }else if(key==node->getKey()){
    cout<<"insert failed.because key exist:"<<key<<endl;;
    return curtime;
  }else{
    if(!node->getRight()){
      node->setRight(new BSTNode<T>(key));
    }else{
      node=node->getRight();
      curtime=insertNode(node,key,curtime);
    }
  }
  return curtime;
}


//----------------------------------------------------------------------------
//DONE
template<typename T>
bool BSTree_Fast<T>::contains(T & key)
{
  if(!root){
    return false;
  }
  bool isContain=contains(root,key);
  return isContain;
}
template<typename T>
bool BSTree_Fast<T>::contains(BSTNode<T> *node,T & key){
  if(!node){
    return false;
  }
  if(node->getKey()==key){
    return true;
  }else if(node->getKey()>key){
    return contains(node->getLeft(),key);
  }else if(node->getKey()<key){
    return contains(node->getRight(),key);
  }
}

//----------------------------------------------------------------------------

// return largest key in BST
// print error and exit if BST is empty
//DONE find the right leaf
template<typename T>
const T & BSTree_Fast<T>::findMax()
{
  if(!root){
    cout<<"error,the tree is empty ";
    exit(1);
  }
  BSTNode<T> *node=root;
  while(node){
    if(node->getRight()){
      node=node->getRight();
    }else{
      return node->getKey();
    }
  }
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// BSTREE_SLOW
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// a binary search tree, implemented as an unordered STL vector

// once again, this is only partial

template<typename T>
class BSTree_Slow
{
public:
  
  BSTree_Slow() { tree.clear(); }               // make an empty BST

  void insert(T &);                             // put a key into the BST 
  bool contains(T &);                           // does this BST contain a certain key?
  const T & findMax();                          // what is the smallest key in the BST?

private:

  vector < BSTNode<T> * > tree;                 // vector of pointers to nodes in the "tree"

};

//----------------------------------------------------------------------------

template<typename T>
void BSTree_Slow<T>::insert(T & key)
{
  // ???
}

//----------------------------------------------------------------------------

template<typename T>
bool BSTree_Slow<T>::contains(T & key)
{
  // ???
}

//----------------------------------------------------------------------------

// return largest key in BST
// print error and exit if BST is empty

template<typename T>
const T & BSTree_Slow<T>::findMax()
{
  // ???
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif
