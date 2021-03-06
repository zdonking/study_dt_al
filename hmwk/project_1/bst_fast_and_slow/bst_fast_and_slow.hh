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
//#include <itererator>

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
  void addnumber(){ number++; }
  int getNumber(){ return number; }

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

// this is only partial--there's no remove functionalitery, for example

template<typename T>
class BSTree_Fast
{
public:
  
  BSTree_Fast() { maxDepth = 0; root = NULL; }  // make an empty BST

  void insert(T &);                             // put a key into the BST 
  bool contains(T &);                           // does this BST contain a certain key?
  const T & findMax();                          // what is the smallest key in the BST?

  int getMaxDepth() { return maxDepth; }
  void print();
  int getTotalNumber();
  int getUniqueNumber();

private:

  int maxDepth;

  BSTNode<T> *root;                             // pointer to the node at the root of the tree
  int insertNode(BSTNode<T> *node,T &,int curtime);
  void print_node(BSTNode<T> *node );
  bool contains(BSTNode<T> *node,T & );
  int getTotalNumber(BSTNode<T> *node);
  int getUniqueNumber(BSTNode<T> *node);

};

//DONE
//print all keys from smallest to largest
template<typename T>
void BSTree_Fast<T>::print(){
  if(!root){
    cout<<"This is empty BSTree"<<endl;
    return ;
  }
  //print node from small to largest
  cout<<"all member from small to large:"<<endl;
  print_node(root);
  //print unique words number
  int unique_number=getUniqueNumber(root);
  cout<<"tree unique number:"<<unique_number<<endl;
  //print total words number
  int total_number=getTotalNumber(root);
  cout<<"tree total number:"<<total_number<<endl;
  //print maximum -depth
  cout<<"tree maximum:"<<maxDepth<<endl;

}
template<typename T>
int BSTree_Fast<T>::getUniqueNumber(){
  return getUniqueNumber(root);
}
template<typename T>
int BSTree_Fast<T>::getTotalNumber(){
  return getTotalNumber(root);
}

template<typename T>
int BSTree_Fast<T>::getUniqueNumber(BSTNode<T> *node){
  int total=0;
  if(node){
    total++;
    total+=getUniqueNumber(node->getLeft());
    total+=getUniqueNumber(node->getRight());
  }
  return total;
}

template<typename T>
int BSTree_Fast<T>::getTotalNumber(BSTNode<T> *node){
  int total=0;
  if(node){
    total+=node->getNumber();
    total+=getTotalNumber(node->getLeft());
    total+=getTotalNumber(node->getRight());
  }
  return total;
  
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
//DONE 
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
    }else {
      node=node->getLeft();
      curtime=insertNode(node,key,curtime);
    }
  }else if(key==node->getKey()){
    node->addnumber();
//    cout<<"insert failed. only add number :"<<key<<endl;;
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
// print error and exiter if BST is empty
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
  void print();                                 // print

private:

  vector < BSTNode<T> * > tree;                 // vector of pointers to nodes in the "tree"
};

//----------------------------------------------------------------------------

//TODO
template<typename T>
void BSTree_Slow<T>::insert(T & key)
{
  BSTNode<T> *node=new BSTNode<T>(key);
  if (tree.empty()){
    tree.push_back(node);
    return;
  }
  if(!contains(key)){
    tree.push_back(node);
    return;
  }else{
    typename vector<BSTNode< T > *>::iterator iter;
    for (iter=tree.begin();iter!=tree.end();++iter){
      if(key==(*iter)->getKey()){
        (*iter)->addnumber();
        return;
      }  
    }

  }
}

//----------------------------------------------------------------------------

template<typename T>
bool BSTree_Slow<T>::contains(T & key)
{
  typename vector<BSTNode< T > *>::iterator iter;
  for (iter=tree.begin();iter!=tree.end();++iter){
    if(key==(*iter)->getKey()){
      return true;
    }  
  }
  return false;
}

//----------------------------------------------------------------------------

// return largest key in BST
// print error and exiter if BST is empty

template<typename T>
const T & BSTree_Slow<T>::findMax()
{
  T max;
  if(!tree.empty()){
    max=tree[0]->getKey();
  }else{
    return NULL;
  } 
  typename vector<BSTNode< T > *>::iterator itt;
  for (itt=tree.begin();itt!=tree.end();itt++){
     if(max<(*itt)->getKey()){
       max=(*itt)->getKey();
     }
  }
  return max;
}
template<typename T>
void BSTree_Slow<T>::print()
{
  //order print
  cout<<" print in the order they are stored in the vector"<<endl;
  typename vector<BSTNode< T > *>::iterator itt;
  for (itt=tree.begin();itt!=tree.end();itt++){
    (*itt)->print();
  }
  //print unique size
  cout<<"unigue size:"<<tree.size()<<endl;
  //print total size
  typename vector<BSTNode< T > *>::iterator it;
  int total=0;
  for (it=tree.begin();it!=tree.end();it++){
    total+=(*it)->getNumber();
  }
  cout<<"total size:"<<total<<endl;
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif
