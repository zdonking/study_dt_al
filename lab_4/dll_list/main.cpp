//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include "dll_list.hh"
#include <fstream>
#include <cstdlib>
#include <typeinfo>



//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

void char_test()
{
  char next;
  MyList<char> L;
  cout << "Enter some text\n";
  // reads from terminal character by character until newline reached
  cin.get(next);
  while (next != '\n') {

    cout <<next;
    // put last character read into list

    L.push_back(next);
    cin.get(next);
  }

  cout << "Written forward that is:\n";

  while (!L.empty()) {
    cout << L.front();
    L.pop_front();
  }

  cout << "\n";
}

//----------------------------------------------------------------------------

void string_test()
{
  string next;
  char c;

  MyList<string> L;

  cout << "Enter a sentence or two\n";

  // read a word

  while (cin >> next) {

    // put it into the list

    L.push_back(next);

    // was that the last word on the line?

    c = cin.get();

    if (c == '\n')
      break;
    else
      cin.putback(c);

  }

  cout << "Written forward that is:\n";
  
  while (!L.empty()) {
    cout << L.front() << " ";
    L.pop_front();
  }
  cout << "\n";
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void reverse_char_test()
{
  char next;

  MyList<char> L;

  cout << "Enter some text\n";

  // reads from terminal character by character until newline reached

  cin.get(next);
  while (next != '\n') {

    // put last character read into list

    cout <<next;
    L.push_front(next);
    cin.get(next);
  }

  cout << "Written forward that is:\n";
  
  while (!L.empty()) {
    cout << L.front();
    L.pop_front();
  }
  cout<<"\n";
}

void reverse_string_test()
{
  string next;
  char c;

  MyList<string> L;

  cout << "Enter a sentence or two\n";

  // read a word

  while (cin >> next) {

    // put it into the list

    L.push_back(next);

    // was that the last word on the line?

    c = cin.get();

    if (c == '\n')
      break;
    else
      cin.putback(c);

  }

  cout << "Written forward that is:\n";
  
  while (!L.empty()) {
    cout << L.back()<<"\n" ;
    L.pop_back();
  }
  cout << "\n";
}
void ordering_test(string fileName)
{
   MyList<string> L; 
   cout <<"Let's begin....";
   ifstream in;
   ofstream out;
   char c;
   in.open(fileName.c_str());
   if(in.fail()){
     cout<<"Filed to open File .There are some ex files, getty.txt sonnet.txt rj.txt \n";
     exit(1);
   }
   string outputFilename("cleaned_"+fileName);
   out.open(outputFilename.c_str());
   string temp;
   while(!in.eof()){
    in.get(c);
    if(!isspace(c)){
      if(ispunct(c) && c!='\'')
        c=' ';
      else if(isalpha(c))
        c=tolower(c);
      }
    if(c=='\n'||c=='\r'||c=='\n\r'){
      c=' ';
    }
     if(c!=' '){
        temp+=c;
     }else{
        if(temp.length()>0){
          L.insert_ordered(temp);
          temp="";
        }
     }     
   }
   in.close();
   out.close();
   /*iter and output*/
   int i=1;
   cout<<"begin output all file word as ordered:\n";
   while(!L.empty()){
      string value=L.front();
      cout <<value<<" ";
      L.pop_front();
      i++;
   }
   cout<<"\n";


}
void readme(){
    cout << "please enter the 2nd argument as the different test model "<<endl;
    cout << "enter 2nd argv 1                       : reverse_char_test "<<endl;
    cout << "enter 2nd argv 2                       : reverse_string_test  "<<endl;
    cout << "enter 2nd argv 3 and 3th argv filename : run ordering_test function" <<endl;
}
int main(int argc, char** argv)
{
 if(argc<2){
    readme();
    exit(1);
 }
 string model =argv[1];
 if(model=="1"){
   reverse_char_test();
 }else if (model=="2"){
   reverse_string_test();
 }else if(model=="3"){
   if(argc!=3){
      cout<<"please enter 3 and the filename for ordering_test function "
              <<endl;
      exit(1);
   }
  string inputFilename(argv[2]);
  ordering_test(inputFilename);
 }else{
    readme();
    exit(1);
   
 }

  //lab-4 1
 // reverse_char_test();
  //reverse_string_test();

  //lab-4 2
  
  //ordering_test(inputFilename.c_str());

  return 1;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
