#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include <queue>
#include<vector>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
#define P pair<int,int>
using namespace std;
const ll mod = 1000000007;


class comp1 {
    public:
    bool operator()(P t1, P t2) // Returns true if t1 is earlier than t2
    {
       return t1.second>t2.second;
    }
};

int main(){
    ll t,N,K,M,S,X,k,l;
    cin >> t ;
    while(t--){
        cin >> N >> K >> X >> M >> S;
        vector< P > v[N+1];
        bool vis[N+1];
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < M; ++i)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[a].push_back(make_pair(b,c));
            v[a].push_back(make_pair(a,c));
        }
        priority_queue< P , vector< P > , comp1 > pq;

        std::vector<ll> dist(N+1,0);
        bool clique_seen = 0;

        pq.push(make_pair(S,0));
        P top=pq.top();
        while(!pq.empty()){
            top=pq.top();pq.pop();
            k=top.first;
            if(vis[k]){
                continue;
            }
            vis[k]=1;
            dist[k]=l=top.second;
            for (vector<P >::iterator it = v[k].begin() ; it != v[k].end(); ++it){
                P node=*it;
                if (!vis[node.first])
                {
                    pq.push(make_pair(node.first,l+node.second));
                }
            }
            if (!clique_seen and k<=K)
            {
                clique_seen=1;
                for (int i = 1; i <=K; ++i)
                {
                    if (i!=k)
                    {
                        pq.push(make_pair(i,l+X));
                    }
                }
            }
        }
        for (int i = 1; i <=N; ++i)
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}