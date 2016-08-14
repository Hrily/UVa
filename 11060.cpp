#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
#include<map>
#include<queue>
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

int n;
map<string,  vector<string> > a;
map<string, int> inDeg;
vector<string> topOrder, v;

void kahn(){
	//calculating in degrees	
	queue<string> q;
	map<string, vector<string> >::iterator it;
	for(it=a.begin();it!=a.end();it++)
		for(int j=0;j<it->second.size();j++)
			inDeg[it->second[j]]++;
	//Enqueue vertices w/ inDeg=0
	for(int i=0;i<n;i++)
		if(inDeg[v[i]]==0)
			q.push(v[i]);
	//BFS
	while(!q.empty()){
		string u = q.front();
		q.pop();
		topOrder.push_back(u);
		for(int i=0;i<a[u].size();i++)
			if(--inDeg[a[u][i]]==0)
				q.push(a[u][i]);
	}
}

int main() {
	// your code goes here
	int cas=1;
	while(si(n)!=EOF){
		int m;
		v.assign(n+1,"");
		topOrder.clear();
		inDeg.clear();
		a.clear();
		for(int i=0;i<n;i++)
			cin>>v[i];
		si(m);
		string u, v;
		for(int i=0;i<m;i++){
			cin>>u>>v;
			a[u].push_back(v);
		}
		kahn();
		cout<<"Case #"<<cas++<<": Dilbert should drink beverages in this order:";
		for(int i=0;i<topOrder.size();i++)
			cout<<" "<<topOrder[i];
		cout<<'.'<<endl<<endl;
	}
	return 0;
}
