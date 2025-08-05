#include<iostream>
using namespace std;
int small(int a){
    int ans=1;
    for(int i = 1;i<10;i++){
        for(int j = 1;j<10;j++){
            if((i*j)==a) return (i*10)+j;
           for(int k = 1;k<10;k++){
               
               if((i*j*k)==a&&i>1&&j>1){
              
           return (i*100)+(j*10)+k;
               }
           }
        }
    }
    return -1;
}
// int fact(int n){
//     if (n==0||n==1) return 1;

//     return n*fact(n-1);
// }
int main (){
    int a;
    cout<<"enter a :";
    cin>>a;
 // cout<<  fact(a)<<endl;
    int b = small(a);
    if(b== -1){
        cout<<"invalid";
    }else{
        cout<<"the smallest integer is :"<<b;
    }
}