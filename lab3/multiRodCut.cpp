#include<iostream>
using namespace std;

int cutRod(int price[], int n){
	if(n == 0){
		return 0;
	}
	int res = 0;
	for(int i = 0; i<n; i++){
		res = max(res,price[i]+cutRod(price, n-i-1));
	}
	return res;
}

int main(){
	int price[] = {1,5,8,9,10,17,17,20,24,30};
	int n;
	cout<<"How many rods do you have"<<endl;
	cin>>n;
	for(int i = 0; i<n; i++){
		int len;
	cout<<"Enter the length of rod no "<<i+1<<" ";
		cin>>len;
		int result = cutRod(price, len);
		cout<<"Rod len "<<len<<"\t"<<"Price "<<result<<"\n"<<endl;
	}
	return 0;
}

