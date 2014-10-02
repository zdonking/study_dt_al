//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include "bst_fast_and_slow.hh"
#include "sys/time.h"
#include "iostream"
#include <fstream>

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

void test_fast_print(){
  BSTree_Fast<int> *bst=new BSTree_Fast<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  for(int i=0;i<9;i++){
    bst->insert(intarr[i]);
  }
  cout<<"print begin";
  bst->print();
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

void test_slow_insert(){
  BSTree_Slow<int> *bst=new BSTree_Slow<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  bst->insert(intarr[0]);
  bst->insert(intarr[1]);
  
}
void test_slow_findmax(){
  BSTree_Slow<int> *bst=new BSTree_Slow<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  for(int i=0;i<9;i++){
    bst->insert(intarr[i]);
  }
    
  int t=bst->findMax();
  cout<<"max number :"<<t<<endl;
}

void test_slow_print(){
  BSTree_Slow<int> *bst=new BSTree_Slow<int>();
  int intarr[9]={6,7,8,9,3,5,7,12,15};
  for(int i=0;i<9;i++){
    bst->insert(intarr[i]);
  }
  bst->print();
}

BSTree_Fast<string> create_fbst_by_file(string fileName){
  BSTree_Fast<string> fbst;
   ifstream in;
   //ofstream out;
   char c;
   in.open(fileName.c_str());
   if(in.fail()){
     cout<<"Filed to open File .There are some ex files, getty.txt sonnet.txt rj.txt \n";
     exit(1);
   }
   string temp;
   while(!in.eof()){
    in.get(c);
    if(!isspace(c)){
      if(ispunct(c) && c!='\'')
        c=' ';
      else if(isalpha(c))
        c=tolower(c);
      }
    if(c=='\n'||c=='\r'){
      c=' ';
    }
     if(c!=' '){
        temp+=c;
     }else{
        if(temp.length()>0){
          fbst.insert(temp);
          temp="";
        }
     }     
   }
   in.close();
   return fbst;
}

BSTree_Slow<string> create_slow_by_file(string fileName){
  BSTree_Slow<string> sbst;
   ifstream in;
   char c;
   in.open(fileName.c_str());
   if(in.fail()){
     cout<<"Filed to open File .There are some ex files, getty.txt sonnet.txt rj.txt \n";
     exit(1);
   }
   string temp;
   while(!in.eof()){
    in.get(c);
    if(!isspace(c)){
      if(ispunct(c) && c!='\'')
        c=' ';
      else if(isalpha(c))
        c=tolower(c);
      }
    if(c=='\n'||c=='\r'){
      c=' ';
    }
     if(c!=' '){
        temp+=c;
     }else{
        if(temp.length()>0){
          sbst.insert(temp);
          temp="";
        }
     }     
   }
   in.close();
   return sbst;
}

void output_fast(BSTree_Fast<string> *bst){
 int uq_number=bst->getUniqueNumber(); 
 int total_number=bst->getTotalNumber(); 
 string maxword=bst->findMax();
 int maxdepth=bst->getMaxDepth();
 cout<<"\tunique number: "<<uq_number<<endl;
 cout<<"\ttotal number: "<<total_number<<endl;
 cout<<"\tlast word: "<<maxword<<endl;
 cout<<"\tmax depth: "<<maxdepth<<endl;
}

void output_slow(BSTree_Slow<string> *bst){
 //int uq_number=bst->getUniqueNumber(); 
 //int total_number=bst->getTotalNumber(); 
 int uq_number=0;
 int total_number=0;
 string maxword=bst->findMax();
 cout<<"\tunique number: "<<uq_number<<endl;
 cout<<"\ttotal number: "<<total_number<<endl;
 cout<<"\tlast word: "<<maxword<<endl;
}

void drive_fast_by_file(string fileName){
  cout<<"begin create Fast_BSTree by file:"<<fileName<<endl;
  BSTree_Fast<string> fbst=create_fbst_by_file(fileName);
  cout<<"create Fast_BSTree finished."<<endl;
  cout<<"for file: "<<fileName<<endl;
  output_fast(&fbst);
}

void drive_slow_by_file(string fileName){
  cout<<"begin create Slow_BSTree by file:"<<fileName<<endl;
  BSTree_Slow<string> sbst=create_slow_by_file(fileName);
  cout<<"create Slow_BSTree finished."<<endl;
  cout<<"for file: "<<fileName<<endl;
  output_slow(&sbst);
}

void test_bst_by_files(){
  drive_fast_by_file("cleaned_bts.txt");
  drive_fast_by_file("cleaned_doi.txt");
  drive_fast_by_file("cleaned_greatexp.txt");
  drive_slow_by_file("cleaned_bts.txt");
  drive_slow_by_file("cleaned_doi.txt");
  drive_slow_by_file("cleaned_greatexp.txt");
}

void drive_fast_outtime(string fileName){
  cout<<"BSTree_Fast create / verfiy words / findMax from file:"<<fileName<<endl;
  timeval t1, t2;
  double elapsedTime;
  gettimeofday(&t1, NULL);
  BSTree_Fast<string> fbst=create_fbst_by_file(fileName);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tcreate fast tree  need "<< elapsedTime << " ms.\n";
  
  string key="love";
  gettimeofday(&t1, NULL);
  bool isContain=fbst.contains(key);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tverify \""<<key<<"\" "<<isContain<<" , need "<<elapsedTime << " ms.\n";

  key="death";
  gettimeofday(&t1, NULL);
  isContain=fbst.contains(key);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tverify \""<<key<<"\" "<<isContain<<" , need "<<elapsedTime << " ms.\n";

  key="tyranny";
  gettimeofday(&t1, NULL);
  isContain=fbst.contains(key);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tverify \""<<key<<"\" "<<isContain<<" , need "<<elapsedTime << " ms.\n";

  gettimeofday(&t1, NULL);
  string max=fbst.findMax();
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tget last word : "<<max<<" , need "<<elapsedTime << " ms.\n";
  
  cout<<"The file:"<<fileName<<" operate via BSTree_Fast end\n"<<endl;
}

void drive_slow_outtime(string fileName){
  cout<<"BSTree_Slow create / verfiy words / findMax from file:"<<fileName<<endl;
  timeval t1, t2;
  double elapsedTime;
  gettimeofday(&t1, NULL);
  BSTree_Slow<string> fbst=create_slow_by_file(fileName);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tcreate fast tree  need "<< elapsedTime << " ms.\n";
  
  string key="love";
  gettimeofday(&t1, NULL);
  bool isContain=fbst.contains(key);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tverify \""<<key<<"\" "<<isContain<<" , need "<<elapsedTime << " ms.\n";

  key="death";
  gettimeofday(&t1, NULL);
  isContain=fbst.contains(key);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tverify \""<<key<<"\" "<<isContain<<" , need "<<elapsedTime << " ms.\n";

  key="tyranny";
  gettimeofday(&t1, NULL);
  isContain=fbst.contains(key);
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tverify \""<<key<<"\" "<<isContain<<" , need "<<elapsedTime << " ms.\n";

  gettimeofday(&t1, NULL);
  string max=fbst.findMax();
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  cout <<"\tget last word : "<<max<<" , need "<<elapsedTime << " ms.\n";
  
  cout<<"The file:"<<fileName<<" operate via BSTree_Fast end\n"<<endl;
}

void test_bst_time()
{
  drive_fast_outtime("cleaned_bts.txt");
  drive_fast_outtime("cleaned_doi.txt");
  drive_fast_outtime("cleaned_greatexp.txt");
  drive_slow_outtime("cleaned_bts.txt");
  drive_slow_outtime("cleaned_doi.txt");
  drive_slow_outtime("cleaned_greatexp.txt");
} 


int main(int argc, char** argv)
{
  //test_fast_insert();
  // call your driver code here
  //finished
  test_fast_print();
  //test_contains();
  // test_findMax();
  //slow tree ..
  //test_slow_insert();
  //test_slow_findmax();
  test_slow_print();

  //compare fast bst to slow bst 
  //test_bst_by_files();
  string filename="cleaned_bts.txt";
  test_bst_time();
  return 0;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
