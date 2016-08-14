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

int is_prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0};

int n, mask=0;
vector<int> a;

void backtrack(int i){
	if(i<n){
		for(int k=2;k<=n;k++){
			if(!(mask&(1<<k)) && is_prime[a[i-1]+k]){
				mask|=(1<<k);
				a[i]=k;
				backtrack(i+1);
				//clear a[i]
				a[i]=0;
				mask&=~(1<<k);
			}
		}
	}else if(i==n && is_prime[a[0]+a[n-1]]){
		for(int j=0;j<n-1;j++)
			cout<<a[j]<<' ';
		cout<<a[n-1]<<endl;
	}				
}
int main() {
	// your code goes here
	int c=1;
	while(si(n)!=EOF){
		a.assign(n,0);
		a[0]=1;
		mask=2;	//mark 1
		printf("Case %d:\n",c++);
		backtrack(1);
		pnl;
	}
	return 0;
}
