#include<bits/stdc++.h>
using namespace std;
string findmin(string s,string t){
    int minlen = INT_MAX;
    int n = s.size();
    int m = t.size();
    int sind = -1;
    for(int i = 0;i<n;i++){
        vector<int> hash(256,0);
        int cnt =0;
        for(int j=0;j<m;j++) hash[t[j]]++;
        for(int j =i;j<n;j++){
            if(hash[s[j]]>0)cnt++;
            hash[s[j]]--;
            if(cnt==m){
                if(j-i+1 <minlen){
                    minlen = j-i+1;
                    sind = i;
                    break;
                }
            }
        }
    }
    return (sind == -1) ? "" : s.substr(sind,minlen);
}
int main(){
  string s = "ddaaabbca";
  string t = "abc";
  string ans = findmin(s,t);
  cout<<"the minimum window substring is "<<ans<<endl;        
 return 0;
}