#include<bits/stdc++.h>

using namespace std;

void floyd(vector<vector<int>>& adj){
    int n=adj.size();
    vector<vector<int>> dist=adj;

    for(int k = 0;k<n;k++)  {  
        for(int i=0;i<n;i++){  
            for(int j=0;j<n;j++)  {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];  
                }
            }  
        }  
    }
    // cout<<"Following matrix shows the shortest distances between every pair of vertices"<<"\n";
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}

int main(){
    clock_t clkStart=clock();
    int n,Max=1e6;
    // cout<<"Enter the number of vertices: ";
    cin>>n;
    vector<vector<int>> adj(n,vector<int>(n,0));
    // cout<<"Enter the adjacency matrix: "<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
            if(i!=j && adj[i][j]==0) adj[i][j]=Max;
        }
    }
    cout<<"Number of vertices are "<<n<<"\n";
    // cout<<endl;
    floyd(adj);
    // cout<<endl;
    clock_t clkFinish=clock();
    cout<<"Execution time is "<< clkFinish-clkStart <<" ms"<<"\n";
}