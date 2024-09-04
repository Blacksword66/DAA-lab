#include<iostream>
using namespace std;
#define MAXROWS = 100;
#define MAXCOLS = 100;

int Max(int a, int b){
  if(a>b) return a;
  else if (b>a) return b;
  else return a;
}

int kadaneAlgo(int a[], int n){
  int max = -100, curr = 0;
  for(int i = 0; i<n; i++){
    curr = Max(a[i], curr+a[i]);
    max = Max(max, curr);
  }
  return max;
}

int main(){
  int n;
  cout<<"Enter n"<<endl;
  cin>>n;

  int arr[n][n];

  for(int i = 0; i<n; i++){
    cout<<"Enter elements of row "<<i+1<<endl;
    for(int j = 0; j<n; j++){
      int ele;
      cin>>ele;
      arr[i][j] = ele;
    }
  }
  
  cout<<"Maximum sums for all rows are as follows"<<endl;
  for(int i = 0; i<n; i++){
    cout<<"Row "<<i+1<<" : "<<kadaneAlgo(arr[i], n)<<endl;
  }
  return 0;
}
