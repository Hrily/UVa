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

int n, c;
vector<int> visited;
vector<char> v, a[256];

int consistent(string r){
	char ch=r[r.size()-1];
	for(int i=0;i<r.size()-1;i++)
		for(int j=0;j<a[ch].size();j++)
			if(r[i]==a[ch][j])
				return 0;
	return 1;
}

void backtrack(int i, string s){
	if(i==n){
		c++;
		cout<<s<<endl;
		return;
	}
	//cout<<i<<' '<<s<<endl;
	for(int ind=0;ind<n;ind++){
		if(!visited[ind]){
			visited[ind]=1;
			string r = s + " " +  v[ind];
			//cout<<"Checking "<<r<<endl;
			if(consistent(r)){
				//cout<<"Consistent\n";
				backtrack(i+1,r);
			}
			visited[ind]=0;
		}
	}
}

int main() {
	// your code goes here
	int t;
	si(t);
	while(t--){
		v.clear();
		string l1="", l2="";
		while(l1.size()<2)getline(cin, l1);
		while(l2.size()<2)getline(cin, l2);
		//cout<<l1<<endl<<l2<<endl;
		for(int i=0;i<l1.size();i++)
			if(l1[i]!=' ')
				v.push_back(l1[i]);
		for(int i=0;i<l2.size();i++)
			if(l2[i+1]=='<')
				a[l2[i]].push_back(l2[i+2]);
		string s="";
		n=v.size();
		c=0;
		visited.assign(n+1,0);
		for(int i=0;i<n;i++){
			s = v[i];
			visited[i]=1;
			backtrack(1,s);
			visited[i]=0;
		}
		if(c==0)
			cout<<"NO\n";
		if(t)cout<<endl;
	}
	return 0;
}
