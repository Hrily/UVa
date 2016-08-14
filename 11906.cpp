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
#define UNVISITED 0
#define VISITED 1
#define WATER	 -1

vector< vector<int> > a;
int r, c, m, n, even=0, odd=0;

int di[] = {-1, -1,  1, 1},
    dj[] = {-1,  1, -1, 1};

int get_val(int i, int j){
	if(i<0 || i>=r || j<0 || j>=c)
		return 0;
	if(a[i][j]==WATER)
		return 0;
	return 1;
}

void dfs(int i, int j){
	if(i<0 || i>=r || j<0 || j>=c)
		return;
	int ans=0;
	if(a[i][j]==UNVISITED){
		a[i][j]=VISITED;
		for(int k=0;k<4;k++){
			ans += get_val(i+di[k]*m, j+dj[k]*n);
			if(m!=n)ans += get_val(i+di[k]*n, j+dj[k]*m);
			dfs(i+di[k]*m, j+dj[k]*n);
			if(m!=n)dfs(i+di[k]*n, j+dj[k]*m);
		}
		if(n==0 || m==0)
			ans/=2;;
		//printf("At %d %d = %d\n", i, j, ans);
		if(ans%2)
			odd++;
		else
			even++;
	}
}

int main() {
	// your code goes here
	int t, cas=1;
	si(t);
	while(t--){
		even=odd=0;
		si(r);si(c);si(m);si(n);
		a.assign(r, vector<int>(c, 0));
		int w, wi, wj;
		si(w);
		while(w--){
			si(wi);si(wj);
			a[wi][wj]=WATER;
		}
		if(m>0 || n>0)dfs(0,0);
		printf("Case %d: %d %d\n", cas++, even, odd); 
	}
	return 0;
}
