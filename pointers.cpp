 #include<iostream>
 using namespace std;
int main()
{
    int a=10;
    int *p=&a;
    cout<<"Val a: "<<endl;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Ponter p: "<<p<<endl;
    cout<<"Value pointed by p: "<<*p<<endl;
    return 0;
}