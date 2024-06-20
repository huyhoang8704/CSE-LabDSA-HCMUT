#include<queue>
int minWaitingTime(int n, int arrvalTime[], int completeTime[]) {
    // YOUR CODE HERE
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<pair<int, int>> arr(n);
    for (int i=0; i<n;i++){
        arr[i].first=arrvalTime[i];
        arr[i].second=completeTime[i];
    }
    sort(arr.begin(), arr.end());
    int i=0;
    int curr=0;
    while(i<n){
        if(!q.empty()){
            curr+=(q.top().first);
            ans=ans+(curr-q.top().second);
            q.pop();
        }
        else{
            curr=arr[i].first+arr[i].second;
            ans+=arr[i].second;
            i++;
        }
        while(i<n&&arr[i].first<=curr){
            q.push({arr[i].second,arr[i].first});
            i++;
        }
    }
    while(!q.empty()){
        curr+=(q.top().first);
        ans=ans+(curr-q.top().second);
        q.pop();
    }
    return ans;
}