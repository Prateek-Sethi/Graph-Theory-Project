#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
    int v=0;
    int w=0;
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
    Edge(){
    }
};

vector<int> dijkstra(vector<vector<Edge*>>& g, int src){

    int V=g.size();
    vector<int> dist(V,1e6);
    set<pair<int,int>> setds;
    setds.insert({0,src});

    dist[src]=0;
    
    while(!setds.empty()){
        pair<int,int> tmp=*(setds.begin());
        setds.erase(setds.begin()); 
  
        int u = tmp.second; 
  
        for (int i=0;i<g[u].size();i++){  
            int v = g[u][i]->v;
            int weight = g[u][i]->w;
  
            if (dist[v] > dist[u] + weight){ 
                if (dist[v] != 1e6) setds.erase(setds.find(make_pair(dist[v], v))); 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            }
        } 
    }
    return dist;
}

int main(){

    clock_t clkStart=clock();
    int n,Max=1e6;
    cin>>n;

    vector<vector<int>> graph(n,vector<int>(n,Max));
    vector<vector<Edge*>> g(n,vector<Edge*>());

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
            if(i!=j){
                if(graph[i][j]==0) graph[i][j]=Max;
                else g[i].push_back(new Edge(j,graph[i][j]));
            }
        }
    }
    vector<vector<int>> minDis(n,vector<int>(n,Max));
    for(int i=0;i<n;i++){
        minDis[i]=dijkstra(g,i);
    }
    cout<<"Number of vertices are "<<n<<"\n";
    // cout<<endl;
    // cout<<"The shortest path from source to other vertices are: \n";
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<minDis[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    clock_t clkFinish=clock();
    // cout<<endl;
    cout<<"Execution time is "<< clkFinish-clkStart<<" ms"<<"\n";
}