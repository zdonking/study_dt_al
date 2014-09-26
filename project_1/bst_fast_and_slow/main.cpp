//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include "bst_fast_and_slow.hh"

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// define your driver code here

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

void test_fast_insert(){
  BSTree_Fast<int> *bst=new BSTree_Fast<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  for(int i=0;i<9;i++){
    bst->insert(intarr[i]);
    cout<<intarr[i]<<endl;
  }
  cout<<"max_depth:"<<bst->getMaxDepth()<<endl;
}

void test_print_by_order(){
  BSTree_Fast<int> *bst=new BSTree_Fast<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  for(int i=0;i<9;i++){
    bst->insert(intarr[i]);
  }
  cout<<"print begin";
  bst->print_by_order();
}

void test_contains(){
  BSTree_Fast<int> *bst=new BSTree_Fast<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  for(int i=0;i<9;i++){
    bst->insert(intarr[i]);
  }
  int povit=10;
  bool isContain=bst->contains(povit);
  cout<<"the BSTree contain the number:"<<povit<<" or not?"<<boolalpha<<isContain<<endl;
  povit=12;
  isContain=bst->contains(povit);
  cout<<"the BSTree contain the number:"<<povit<<" or not?"<<boolalpha<<isContain<<endl;

}
void test_findMax(){
  BSTree_Fast<int> *bst=new BSTree_Fast<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  for(int i=0;i<9;i++){
    bst->insert(intarr[i]);
  }
  int maxKey=bst->findMax();
  cout<<"max-key : "<<maxKey<<endl;
}

int main(int argc, char** argv)
{
  //test_fast_insert();
  // call your driver code here
  //test_print_by_order();
  //test_contains();
  test_findMax();
  return 0;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
