#include<iostream>
using namespace std;
int main(){
    int a[100];
    int n;
    cin>>n;
    int k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    
    }
    for(int i=0;i<n;i++){
if(a[i]%400==0){
    k=a[i];
    cout<<" It's a leap year"<<k<<endl;
}else if (a[i] % 100 == 0) {
    cout<<":It's not a leap year!"<<k<<endl;
}
else if(a[i] % 4==0){
    cout<<" It's a leap year!"<<k;
}
else{
    cout<<"not a leap year!"<<a[i];
}
}
}