#include <bits/stdc++.h>

using namespace std;

// Shahd Elnassag
// Problem 4 in Part 1 Dynamic Programming

int memo [1010][31];
bool picked [1010][31];
int treasure[31];
int depth[31];
int cost[31];
int w;
int n;

void init(){
    memset(memo,-1,sizeof(memo));
    memset(treasure,0,sizeof(treasure));
    memset(depth,0,sizeof(depth));
    memset(cost,0,sizeof(cost));
    memset(picked, false, sizeof(picked));
}

int dp(int t,int state){
    //if runs out of time, terminate
    if(t<0){
        return 0;
    }
    //if reach last state
    if(state==n){
        return 0;
    }
    //if have been computed
    if(memo[t][state]!=-1){
        return memo[t][state];
    }
    //standard DP 0-1 knapsack
    int a=0;
    int b=0;
    if (t-cost[state]>=0){
        a = dp(t-cost[state],state+1)+treasure[state];
    }
    b = dp(t,state+1);
    if(a>b){
        picked[t][state] = true;
    }
    int ans = max(a,b);
    return memo[t][state]=ans;
}

int main(){
    int t;
    bool first =true;

    while(cin >> t >> w){
        if (first){
            first=false;
        }
        else{
            cout << endl;
        }
        init();
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> depth[i] >> treasure[i];
            cost[i]=depth[i]*3*w;
        }

        cout << dp(t,0) << endl;

        vector<int> indexTaken;
        int startTime=t;
        for(int i=0;i<n;i++){
            if(picked[startTime][i] == true){
                indexTaken.push_back(i);
                startTime = startTime - cost[i];
            }
        }
        cout << indexTaken.size() << endl;
        for(int i=0;i<(int)indexTaken.size();i++){
            cout << depth[indexTaken[i]] << " " << treasure[indexTaken[i]] << endl;
        }
    }

    return 0;
}