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

int diri[] = {-1, 0, 1,  0},	//N, E, S, W ;
    dirj[] = { 0, 1, 0, -1};	//0, 1, 2, 3 ;

int D(int dir){
	return ((dir<3)?dir+1:0);
}

int E(int dir){
	return ((dir>0)?dir-1:3);
}

int main() {
	// your code goes here
	int n, m, q;
	while(scanf("%d %d %d",&n, &m, &q), n>0){
		string a[n];
		int pi=0, pj=0, dir=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=0;j<m;j++){
				if(a[i][j]=='N'){
					pi=i;pj=j;
					dir=0;
				}else if(a[i][j]=='L'){
					pi=i;pj=j;
					dir=1;
				}else if(a[i][j]=='S'){
					pi=i;pj=j;
					dir=2;
				}else if(a[i][j]=='O'){
					pi=i;pj=j;
					dir=3;
				}
			}
		}
		string s;
		cin>>s;
		int count=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='D')
				dir=D(dir);
			else if(s[i]=='E')
				dir=E(dir);
			else{
				//cout<<pi<<' '<<pj<<' '<<dir<<endl;
				pi += diri[dir];
				pj += dirj[dir];
				if( (pi<0 || pi>=n || pj<0 || pj>=m) ||
				    (a[pi][pj]=='#')){
					pi -= diri[dir];
					pj -= dirj[dir];
				}else if(a[pi][pj]=='*'){
					a[pi][pj]='.';
					count++;
				}
				//cout<<count<<endl;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
