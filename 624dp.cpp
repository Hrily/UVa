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

string to_string(int a){
	ostringstream ss;
	ss<<a;
	return ss.str();
}

int main() {
	// your code goes here
	int w,n;
	while(scanf("%d %d",&w,&n)!=EOF){
		vector<int> a(n+1), mark(n+1,0);
		for(int i=1;i<=n;i++)
			si(a[i]);
		int dp[n+1][w+1];
		string s[n+1][w+1];
		for(int k=0;k<=w;k++){
			dp[0][k]=0;
			s[0][k]="";
		}
		for(int i=0;i<=n;i++){
			dp[i][0]=0;
			s[i][0]="";
		}
		for(int i=1;i<=n;i++){
			for(int k=0;k<=w;k++){
				dp[i][k]=dp[i-1][k];
				s[i][k]=s[i-1][k];
				if(a[i]<=k)
					dp[i][k]=MAX(dp[i][k],a[i]+dp[i-1][k-a[i]]);
			}
		}
		int i=n, k=w;
		while(i>0 && k>0){
			if(dp[i][k]!=dp[i-1][k]){
				mark[i]=1;
				k-=a[i];
				i--;
			}else
				i--;
		}
		for(int i=1;i<=n;i++)
			if(mark[i])
				cout<<a[i]<<' ';
		cout<<"sum:"<<dp[n][w]<<endl;
	}
	return 0;
}
