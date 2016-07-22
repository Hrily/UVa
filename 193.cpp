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

vector< vector< int > > Adj(104);
vector<int> col(104),max_set;
int n;

int check(int node){
	for(int i=0;i<Adj[node].size();i++)
		if(col[Adj[node][i]]) return 0;
	return 1;
}

void mis(int node){
	if(node>n){
		vector<int> set;
		for(int i=1;i<=n;i++)
			if(col[i]) set.push_back(i);
		if(set.size()>max_set.size()){
			max_set.clear();
			for(int i=0;i<set.size();i++)
				max_set.push_back(set[i]);
		}
	}else{
		col[node]=0;
		mis(node+1);
		col[node]=1;
		if(check(node))
			mis(node+1);
		col[node]=0;
	}
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		int k,a,b;
		si(n);si(k);
		col.assign(n+1,0);
		Adj.assign(n+1,vector<int>());
		max_set.clear();
		for(int i=0;i<k;i++){
			si(a);si(b);
			Adj[a].push_back(b);
			Adj[b].push_back(a);
		}
		mis(1);
		cout<<max_set.size()<<endl;
		for(int i=0;i<max_set.size();i++){
			if(i) cout<<" "<<max_set[i];
			else  cout<<max_set[i];
		}
		pnl;
	}
	return 0;
}
