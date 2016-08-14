#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<limits>
#include<vector>
#include<string>
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

int di[] = {-1, -1, -1,  0, 0, 0,  1, 1, 1},
    dj[] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};

vector<string> a;
int n, m;

int flood_fill(int i, int j, char q, char r){
	if(i<0 || i>=n || j<0 || j>=m)
		return 0;
	if(a[i][j]!=q)
		return 0;
	int ans=1;
	a[i][j]=r;
	for(int k=0;k<9;k++)
		ans += flood_fill(i+di[k], j+dj[k], q, r);
	return ans;
}

int stoi(string s){
	int r=0;
	for(int i=0;i<s.size();i++)
		r=r*10+(s[i]-'0');
	return r;
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		string s;
		int state=0;	//0 = fetching grid, 1 = otherwise
		int i, j;
		while(!state){
			cin>>s;
			if(s[0]=='L' || s[0]=='W')
				a.push_back(s);
			else{
				state=1;
				istringstream iss(s);
				iss>>i;
				si(j);
				n=a.size();
				m=a[0].size();
				break;
			}
		}
		while(state){
			printf("%d\n", flood_fill(i-1, j-1, 'W', '.'));
			cin>>s;
			if(s[0]=='L' || s[0]=='W'){
				a.clear();
				a.push_back(s);
				break;
			}else{
				if(s.size()==0) break;
				istringstream iss(s);
				iss>>i;
				si(j);
				//j/=10;
				s="";
			}
		}
	}
	return 0;
}
