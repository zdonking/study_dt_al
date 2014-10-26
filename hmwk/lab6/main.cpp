//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include "avl.hh"

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// define your driver code here

void driver(char *filename)
{
  AVLTree<string> my_avl;

  my_avl.insertFileWords(filename);
  my_avl.print_level_and_pretty();
cout<<"begin in order"<<endl;
my_avl.print_inorder();
cout<<"---------END in order------"<<endl;

  // Statistics

  cout << "nodes = " << my_avl.size() << endl;
  cout << "keys = " << my_avl.getNumKeys() << endl;
  cout << "height = " << my_avl.computeHeight() << endl;
  cout << "worst balance factor = " << my_avl.worstBalanceFactor << endl;
  cout << "min key = " << my_avl.findMin() << endl;
  cout << "max key = " << my_avl.findMax() << endl;

}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

int main(int argc, char** argv)
{
 if (argc < 2) {
    cout << "Please specify filename on command line\n";
    exit(1);
  }

  // call your driver code here

  driver(argv[1]);

  return 1;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
