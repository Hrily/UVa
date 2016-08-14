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
#define UNVISITED (-1)

vector< vector<int> > a;
vector<int> visited, low, disc, stack;
int tim=0, scc=0;

void tarjan(int u){
	visited[u]=1;
	stack.push_back(u);
	disc[u] = low[u] = tim++;
	for(int i=0;i<a[u].size();i++){
		int v = a[u][i];
		if(disc[v]==UNVISITED)
			tarjan(v);
		if(visited[v])
			low[u] = MIN(low[u], low[v]);
	}
	if(low[u]==disc[u]){
		scc++;
		while(1){
			int v=stack.back();
			stack.pop_back();
			visited[v]=0;
			if(u==v)
				break;
		}
	}
}

int main() {
	// your code goes here
	int n,m;
	while(scanf("%d%d",&n,&m), n>0){
		a.assign(n+1, vector<int>());
		visited.assign(n+1, 0);
		disc.assign(n+1, UNVISITED);
		low.assign(n+1, 0);
		tim=scc=0;
		int u, v, p;
		while(m--){
			si(u);si(v);si(p);
			a[u].push_back(v);
			if(p>1)
				a[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			if(disc[i]==UNVISITED)
				tarjan(i);
		cout<<((scc==1)?1:0)<<endl;
	}
	return 0;
}
