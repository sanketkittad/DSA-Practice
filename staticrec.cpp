#include <iostream>
using namespace std;
int rc(int n){
    static int x=0;
    if(n){
        ++x;
        return rc(n-1)+x;
    }
    return 0;
}
int main()
{
    int n=5;
    cout<<rc(5);
    return 0;
}