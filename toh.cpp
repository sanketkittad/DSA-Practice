#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<utility>
using namespace std;
#define ll long long int
void TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        cout<<"("<<A<<","<<C<<")\n";
        TOH(n-1,B,A,C);
    }
}
int main()
{   int n;
    cout<<"Enter number of discs";
    cin>>n;
    TOH(n,1,2,3);
    return 0;
}