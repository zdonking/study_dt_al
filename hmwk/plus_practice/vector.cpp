#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


//class VectorTest {
//  private{
//    Vector vec=new 
//  }
//}


int main(){
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  //cout<< vec <<endl;
  // loop vector
  for (int i=0;i<3;++i){
    cout<<"the " <<i<<" element:"<<vec[i]<<endl;
  }
  // loop vector by iterator
  vector<int> v=vec;
  for (vector<int>::iterator it =v.begin();it!=v.end();it++){
    cout<<v.capacity()<<endl;
    cout <<"current iterator :"<< (*it)<<endl;
  }


  //vector has rich api for operate the element. 
  vector<int> v2=v;
  cout<<"use index get element:vector[index]: "<<v2[2]<<endl;
  cout<<"use at func get element:vector.at(index): "<<v2.at(2)<<endl;
  cout<<"get first element by front :vector.front(): "<<v2.front()<<endl;
  cout<<"back():"<<v2.back()<<endl;
  cout<<"pop_back():"<<endl;
  v2.pop_back()
  




  return 0;

  
}
