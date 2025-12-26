// // #include<bits/stdc++.h>
// // using namespace std;
// // void printsubarr(vector<int> &arr){
// //     int n = arr.size();
// //     for(int i = 0;i<n;i++){
// //         for(int j = i;j<n;j++){
// //             for(int k = i;k<=j;k++){
// //                 cout<<arr[k]<<" ";
// //             }
// //             cout<<endl;
// //         }
// //     }
// // }
// // int findtotal(vector<int> arr ,int k ){
// //     int n = arr.size();
// //     long long sum = 0;
// //      for(int i = 0;i<arr.size();i++){
// //             int largest = arr[i]; 
// //             int smallest =arr[i];
// //             for(int j= i+1;j<arr.size();j++){
// //                 // largest = max(largest,arr[j]);
// //                 // smallest = min(smallest,arr[j]);
// //                 // sum = sum + (largest-smallest );
                
// //             }
// //         }
// //         return sum;
// // }
// // int main(){
// //   vector<int> arr = {18,36,6};
// //   int k = 3;
// //   printsubarr(arr);
// //  // cout<<findtotal(arr,k)<<endl;

// //  return 0;
// // }

// // #include<bits/stdc++.h>
// // using namespace std;
// // int main(){
// //     for(int i = 1;i<10;i++)
// //       cout<<ceil(16.0/i)<<endl;       
 
// //       return 0;
// // }
// #include<bits/stdc++.h>
// using namespace std;
//  int maximumEnergy(vector<int>& energy, int k) {
//         int maxi = INT_MIN;
//         vector<int> suffix(energy.size());

//         suffix[0] = energy[0];

//         for(int i = 1;i<energy.size();i++){
//           suffix[i] = max(suffix[i-1],energy[i]);

//         }
        
//         for(int i = 0;i<suffix.size();i++){
//           cout<<suffix[i]<<" ";
//         }
         
//         return maxi;
//     }
// int main(){
//   vector<int> arr = { 5,2,-10,-5,1};
//   int k = 3;
//   string s = "3";
//   string v = "4";


//   cout<<    maximumEnergy(arr,k);
//  return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int timer = 1;
void dfs(int node ,int parent,vector<int> adj[],vector<int> &vis,int tin[],int low[],vector<vector<int>> & bridges){
    vis[node] = 1;
    low[node] = tin[node] =  timer;
    timer++;
    for(auto it: adj[node]){
        if(it == parent) continue;
        if(vis[it]== 0){
            dfs(it,node,adj,vis,tin,low,bridges);
            low[node] = min(low[node],low[it]);
            if(low[it]> tin[node]){
                bridges.push_back({it,node});
            }

        }else{
            low[node] = min(low[node],low[it]);
        }
    }
    

}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
         dfs(0,-1,adj,vis,tin,low,bridges);
        return bridges;
    }

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> result = criticalConnections(n, connections);
    cout << "Critical Connections (Bridges) in the network:" << endl;
    for (const auto& bridge : result) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "]" << endl;
    }
    return 0;
}
