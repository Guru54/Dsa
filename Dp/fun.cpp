#include<bits/stdc++.h>
using namespace std;
void f(string str,int ind){
    if(ind == 0) {
        cout<<str[ind];
        return;
    }
    cout<<str[ind];
    f(str,ind-1);
}
int floot(int n,int m){
    if(n==m) return 2;
    if(n<m) return 1;
    int vp = floot(n-m,m);
    int hp = floot(n-1,m);
    return vp+hp;
}
int tgc(int n){
    if(n<=1) return 1;

    int w1 = tgc(n-1);
    int w2 = tgc(n-2)*(n-1);
    return w1+w2;
}
int tp(int i,int j , int n ,int m){
    if(i==n||j==m) return 0;

    if(i==n-1&&j==m-1) return 1;
    
    int dp = tp(i,j+1,n,m);
    int rp = tp(i+1,j,n,m);
    return dp+rp;
}
int magic(int a,int b){
    if(a==7) return 1;
    int c = a+b;
    for(int i = 0;i<5;i++){
        cout<<c<<endl;
        magic(a+1,b+1);

    }
    return c;


}

int pn(int n){
    if(n==0){
        return 1;
    }
    int b= 0;
    int sum = n+b;
    pn(n-1);
    return sum;
}
void pdn(int n){
    if(n==0) return;
    cout<<n<<endl;
    pdn(n-1);
    cout<<n<<endl;
}
void magic2(string str, string crc){
    if(str.size()==0){
        cout<<crc<<endl;
        return;
    }
    for(int i = 0;i<str.size();i++){
        char curc = str[i];
        string nstr = str.substr(0,i) + str.substr(i+1);
        magic2(nstr,curc+crc);
    }

}
void printsub(vector<int> &subset){
    for(int i = 0;i<subset.size();i++){
        cout<<subset[i]<<" ";
    }
    cout<<endl;
}
void fs(int n,vector<int> &subset){
    if(n==0){
        printsub(subset);
        return;
    }
    subset.push_back(n);
    
    fs(n-1,subset);

    subset.pop_back();
    fs(n-1,subset);
}
int main(){
  string str = "saduruG";
  //f(str,str.size()-1); 
 int n = 6;
 int m= 2;
// cout<<floot(n,m);
int r = 7;
//cout<<tgc(r);
//cout<<tp(0,0,3,6)<<endl;
//cout<<magic(0,1);
//cout<<pn(7);
//pdn(5);
magic2("hello why and hey","");

vector<int> subset;
//fs(5,subset);
 return 0;
}