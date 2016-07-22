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

int n,a[100010];

int sim(int k){
	int c=0;
	for(int i=0;i<n;i++){
		if(a[i]-c>k)
			return 0;
		if(a[i]-c==k)
			k--;
		c=a[i];
	}
	return 1;
}

int main() {
	// your code goes here
	int t;
	si(t);
	for(int cas=1;cas<=t;cas++){
		si(n);
		for(int i=0;i<n;i++)
			si(a[i]);
		int l=0,h=a[n-1],m;
		while(h>l){
			m=(l+h)/2;
			if(sim(m))
				h=m;
			else
				l=m+1;
		}
		cout<<"Case "<<cas<<": ";
		if(sim(l))
			cout<<l<<endl;
		else if(sim(m))
			cout<<m<<endl;
		else if(sim(h))
			cout<<h<<endl;
	}
	return 0;
}
