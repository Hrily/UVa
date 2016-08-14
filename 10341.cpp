#include<iostream>
#include <iomanip>
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
#define EPS 1e-7

int p,q,r,s,t,u;

float solve(float x){		//fn is decreasing...
	return (float)( p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u );
}

int main() {
	// your code goes here
	while(si(p)==1){
		scanf("%d %d %d %d %d",&q,&r,&s,&t,&u);
		float l=0.0,h=1.0,m=0.5;
		float lv=solve(l),hv=solve(h);
		//cout<<lv<<' '<<hv<<' ';
		if(lv*hv>0){
			printf("No solution\n");
			continue;
		}
		if(ABS(lv)<1e-5f){
			cout<<"0.0000\n";
			continue;
		}
		if(ABS(hv)<1e-5f){
			cout<<"1.0000\n";
			continue;
		}
		while(h-l>(float)EPS){
			m=(float)(l+h)/2.0;
			float tmp = solve(m);
			//printf("h=%lf l=%lf m=%lf : %lf\n",h,l,m,tmp);
			//printf("%lf %lf\n",h-l,EPS);
			//if(ABS(tmp)<(float)1e-5)
				//break;
			if(tmp>0.0f){
				if(lv<hv)
					h=m;
				else
					l=m;
			}else{
				if(lv<hv)
					l=m;
				else
					h=m;
			}
		}
		//printf("%lf ",solve(m));
		printf("%.4lf\n",m);
		p=-1;
	}
	return 0;
}
