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

vector<int> a(13,0);
int s,d;
int max_profit=0;

void backtrack(int i){
	if(i<4){
		a[i]=s;
		backtrack(i+1);
		a[i]=d;
		backtrack(i+1);
	}else if(i<12){
		//calculate prev 4 month report
		int rep=0;
		for(int j=i-4;j<i;j++)
			rep+=a[j];
		if(rep+s<=0){
			a[i]=s;
			backtrack(i+1);
		}else if(rep+d<=0){
			a[i]=d;
			backtrack(i+1);
		}//else backtrack
	}else{
		//calculate profit
		int profit=0;
		for(int j=0;j<12;j++)
			profit+=a[j];
		if(profit>max_profit)
			max_profit=profit;
	}
}

int main() {
	// your code goes here
	while(scanf("%d %d",&s,&d)!=EOF){
		d=-d;
		a.assign(13,0);
		max_profit=0;
		backtrack(0);
		if(max_profit>0)
			cout<<max_profit<<endl;
		else
			cout<<"Deficit\n";
	}
	return 0;
}
