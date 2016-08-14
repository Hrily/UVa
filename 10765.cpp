#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
using namespace std;
#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")//print new line
#define REP(i,n) for(int i=0;i<(n);i++)//repeat n times
#define FOR(i,a,b) for(int i=(a);i<(b);i++)//end not included
#define FORR(i,n) for(int i=(n);i>=0;i--)//reverse for
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";//debugging
#define CL(a,b) memset(a,b,sizeof(a))
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
//}

vector< vector<int> > a;
vector<int> visited, parent, low, disc, child, isap;
vector< pair<int, int> > ap;
int tim;

int comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second)
		return a.first>b.first;
	return a.second<b.second;
}

void find_ap(int u){
	visited[u]=1;
	int children = 0;
	disc[u] = low[u] = tim++;
	for(int i=0;i<a[u].size();i++){
		int v = a[u][i];
		if(!visited[v]){
			children++;
			parent[v]=u;
			find_ap(v);
			low[u]=MIN(low[u], low[v]);
			if(parent[u]==-1 && children>1){
				child[u] = MAX(child[u], children-1);
				isap[u]=1;
			}
			if(parent[u]!=-1 && low[v]>=disc[u]){
				child[u]++;
				isap[u]=1;
			}
		}else if(parent[u]!=v)
			low[u]=MIN(low[u], disc[v]);
	}
}

int main() {
	// your code goes here
	int n,m;
	while(scanf("%d%d", &n, &m),n>0){
		a.assign(n+1, vector<int>());
		visited.assign(n+1, 0);
		parent.assign(n+1, -1);
		low.assign(n+1, 0);
		disc.assign(n+1, 0);
		isap.assign(n+1, 0);
		child.assign(n+1, 0);
		ap.clear();
		tim=0;
		int u, v;
		while(scanf("%d%d", &u, &v),u!=-1){
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int add=0;
		for(int i=0;i<n;i++){
			if(!visited[i]){
				add++;
				find_ap(i);
			}
		}
		for(int i=0;i<n;i++)
			ap.push_back(make_pair(i, child[i]+add));
		sort(ap.begin(), ap.end(), comp);
		reverse(ap.begin(), ap.end());
		for(int i=0;i<m;i++)
			cout<<ap[i].first<<' '<<ap[i].second<<endl;
		pnl;
	}
	return 0;
}
