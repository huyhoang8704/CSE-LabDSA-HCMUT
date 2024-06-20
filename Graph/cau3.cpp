



void dfs(int v, vector<vector<int>>& friends, vector<bool>& visted){
    if(visted[v] == false){
        visted[v] = true;
        for(int i : friends[v]){
            dfs(i,friends,visted);
        }
    }
}


int numberOfFriendGroups(vector<vector<int>>& friends) {
    vector<bool> visted(friends.size(), false);
    int n = friends.size();
    int count = 0;
    for(int i = 0 ; i < n; i++){
        if(visted[i] == false){
            dfs(i,friends,visted);
            count ++;
        }
    }
    return count;
}