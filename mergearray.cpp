#include<iostream>
#include <iostream>
#include<algorithm>
using namespace std;
void merge(){
    cout<<"size 1: ";
    int n;
    cin>>n;
    cout<<"size 2: ";
    int m;
    cin>>m;
    int first[n],second[m],final[m+n];
    cout<<"\nEnter 1st array: ";
    for(int i=0;i<n;++i){
        cin>>first[i];
    }sort(first,first+n);
    cout<<"\nEnter 2nd array: ";
    for(int i=0;i<m;++i){
        cin>>second[i];
    } 
    sort(second,second+m);
    int i=0,j=0,k=0;
    while(k<(m+n) && j<m && i<n){
        if(first[i]>second[j])
            final[k++]=second[j++];
        
        else
            final[k++]=first[i++];
    }
    for(;i<n;++i){
        final[k++]=first[i];
    }
    for(;j<m;++j){
        final[k++]=second[j];
    }
    cout<<"\nmerged";
    for(int i=0;i<n+m;++i)cout<<final[i]<<' ';
}
void setintersect(){
      cout<<"size 1: ";
    int n;
    cin>>n;
    cout<<"size 2: ";
    int m;
    cin>>m;
    int first[n],second[m],final[m+n]{0};
    cout<<"\nEnter 1st array: ";
    for(int i=0;i<n;++i){
        cin>>first[i];
    }sort(first,first+n);
    cout<<"\nEnter 2nd array: ";
    for(int i=0;i<m;++i){
        cin>>second[i];
    } 
    sort(second,second+m);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(first[i]==second[j]){
            final[k++]=first[i++];
            ++j;
        }
        else if(first[i]<second[j]){
            ++i;
        }
        else ++j;
    }
    cout<<"\nmerged";
    for(int i=0;i<k;++i)cout<<final[i]<<' ';
}
void aSubb(){
    cout<<"size 1: ";
    int n;
    cin>>n;
    cout<<"size 2: ";
    int m;
    cin>>m;
    int first[n],second[m],final[m+n]{0};
    cout<<"\nEnter 1st array: ";
    for(int i=0;i<n;++i){
        cin>>first[i];
    }sort(first,first+n);
    cout<<"\nEnter 2nd array: ";
    for(int i=0;i<m;++i){
        cin>>second[i];
    } 
    sort(second,second+m);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(first[i]<second[j]){
            final[k++]=first[i++];
        }
        else if(second[j]<first[i]){
            ++j;
        }
        else {
            ++i;
            ++j;
        }
    }
    cout<<"\nmerged";
    for(int i=0;i<k;++i)cout<<final[i]<<' ';
}
void setunion(){
      cout<<"size 1: ";
    int n;
    cin>>n;
    cout<<"size 2: ";
    int m;
    cin>>m;
    int first[n],second[m],final[m+n]{0};
    cout<<"\nEnter 1st array: ";
    for(int i=0;i<n;++i){
        cin>>first[i];
    }sort(first,first+n);
    cout<<"\nEnter 2nd array: ";
    for(int i=0;i<m;++i){
        cin>>second[i];
    } 
    sort(second,second+m);
    int i=0,j=0,k=0;
   
    while(i<n && j<m){
        if(first[i]>second[j]){
            final[k++]=second[j++];
        }
        else if(first[i]<second[j]){
            final[k++]=first[i++];
        }
        else{
            final[k++]=first[i++];
            ++j;
        }
    }
    cout<<"\nmerged";
    for(int i=0;i<k;++i)cout<<final[i]<<' ';     
}
int main(){
    setintersect();
    return 0;
}