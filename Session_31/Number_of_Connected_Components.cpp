class Solution {
public:
    void dfs(int i, unordered_map<int,int>& hash, vector<vector<int>>& adj){
        hash[i]++ ;
        for(auto it : adj[i]){
            if(hash.find(it) == hash.end()){
                dfs(it,hash,adj);

            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        unordered_map<int,int> hash;

        int c = 0;

        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
    }

        for(int i =0; i < n; i++){
            if(hash.find(i) == hash.end()){   //not there then continue call dfs
            dfs(i,hash,adj);
            c++;
            }
            
    }
        return c;

    }
    
};
