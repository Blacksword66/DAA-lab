#include<iostream>
using namespace std;

bool isAlpha(int a, int b){//Checks if alpha(a)<alpha(b)
  int temp1 = a, temp2 = b, sum1 = 0, sum2 = 0;
  while(temp1>0){
    sum1 += temp1%10;
    temp1 /= 10;
  }

  while(temp2>0){
    sum2 += temp2%10;
    temp2 /= 10;
  }

  if(sum1<sum2) return true;
  else return false;
}

void insertionSortAlpha(int a[], int n){//Sorts the array on the basis of alpha
  int len = n;
  for(int i = 1; i<len; i++){
    int key = a[i];
    int j = i-1;
    while(j>=0 && isAlpha(key, a[j])){
      a[j+1] = a[j];
      j-=1;
    }
    a[j+1] = key;
  }

  for(int i = 0; i<len; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int a[4] = {22,1111,11,9};
  for(int i = 0; i<4; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<"The Alpha Sorted Array is: "<<endl;
  insertionSortAlpha(a,4);
  return 0;
}
