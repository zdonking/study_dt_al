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

int main(int argc, char** argv)
{
  //test_fast_insert();
  // call your driver code here
  test_print_by_order();
  return 0;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
