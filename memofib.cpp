#include<iostream>
using namespace std;
int fib[10]{-1};
int mefib(int n){
	if(n<=1){
		fib[n]=n;
		return n;
	}
	else{
		if(fib[n-2]==-1) fib[n-2]=mefib(n-2);
		if(fib[n-1]==-1) fib[n-1]=mefib(n-1);
		fib[n]=fib[n-2]+fib[n-1];
		return fib[n-1]+fib[n-2];
	}
}

int main(){
	
	for(int i=0;i<9;++i)cout<<mefib(i)<<'\n';
	return 0;
}