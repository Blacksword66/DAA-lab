#include<iostream> 
#include<fstream>
#include<vector> 
#include<ctime> 
using namespace std;
int main() {
  vector<int> elements; // NO NEED TO DEFINE SIZE OF VECTOR LIST 
  int key,i,j,n,ele;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>ele;
    elements.push_back(ele);
  }
  clock_t tStart = clock();
  for(j=1;j<n;j++){
    key = elements[j];
    i = j-1; 
    while((i>=0)&&(elements[i]>key)){
      elements[i+1] = elements[i];
      i = i-1; 
    }
    elements[i+1] = key;
  }
  double time1=(double)(clock() - tStart);//CLOCKS_PER_SEC;
  cout<<"Time taken is "<<time1<<endl;
/*for(i=0;i<n;i++) {
cout<<elements[i]<<" "; }*/
}
