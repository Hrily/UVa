#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
#include<sstream>
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
vector<int> visited, num, low, parent, isap;
int tim=0;

void find_ap(int u){
	visited[u]=1;
	int children=0;
	//update discovery time
	num[u]=low[u]=tim++;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(!visited[v]){
			//update no of children
			children++;
			//update parent of v
			parent[v]=u;
			find_ap(v);
			//update low time of u
			low[u]=MIN(low[u], low[v]);
			//1. if u is root with children>1
			if(parent[u]==0  && children>1)
				isap[u]=1;
			//2. if u aint root and has a child v
			//which backtracks to parent of u
			if(parent[u]!=0 && low[v]>=num[u])
				isap[u]=1;
		}else if(parent[u]!=v){
			//upadate low value for parent computation
			low[u]=MIN(low[u], num[v]);
		}
	}
}


int main() {
	// your code goes here
	int n;
	while(si(n), n>0){
		a.assign(n+1, vector<int>());
		visited.assign(n+1, 0);
		num.assign(n+1, 0);
		low.assign(n+1, 0);
		isap.assign(n+1, 0);
		parent.assign(n+1, 0);
		tim=0;
		string s;
		int u, v, ans=0;
		getline(cin, s);
		while(getline(cin, s), s[0]!='0'){
			istringstream iss(s);
			iss>>u;
			while(iss>>v){
				a[u].push_back(v);
				a[v].push_back(u);
			}
		}
		for(int i=1;i<=n;i++)
			if(!visited[i])
				find_ap(i);
		for(int i=1;i<=n;i++)
			ans += isap[i];
		cout<<ans<<endl;
	}
	return 0;
}
