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

int solve(vector<int> stones){
	int tmp=0;
	for(int j=2;j<stones.size();j++)
		tmp = MAX(tmp, stones[j]-stones[j-2]);
	if(stones.size()==2)
		tmp=MAX(tmp,stones[1]-stones[0]);
	return tmp;
}

int main() {
	// your code goes here
	int t,c=1;
	si(t);
	while(t--){
		int n,d;
		char ch;
		int x,m=0;
		si(n);si(d);
		vector<int> stones;
		stones.push_back(0);
		for(int i=0;i<n;i++){
			scanf(" %c-%d",&ch,&x);
			if(ch=='S')
				stones.push_back(x);
			else{
				stones.push_back(x);
				//for(int j=0;j<stones.size();j++)
				//	cout<<stones[j]<<' ';
				//cout<<endl;
				//cout<<solve(stones)<<endl;
				m=MAX(m,solve(stones));
				int temp=stones.back();
				stones.clear();
				stones.push_back(temp);
			}
		}
		stones.push_back(d);
		m=MAX(m,solve(stones));
		printf("Case %d: %d\n",c++,m);
	}
	return 0;
}
