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
#define MID(a,b) (a+b+1)/2
#define pb(x) push_back(x)

string split(int,int);
string split(string);

string data, ans;
int ind,max_char=50;

char v[210][210];

void create_v(int x, int y){
	int top=0;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			v[i][j]=data[top++];
}

string split(int x, int y){
	string s="",r="";
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			s+=v[i][j];
	for(int i=0;i<s.size();i++){
		if(i%max_char==0 && i>0)
			r+='\n';
		r+=s[i];
	}
	return  r;
}

string split(string s){
	string r="";
	for(int i=0;i<s.size();i++){
		if(i%max_char==0 && i>0)
			r+='\n';
		r+=s[i];
	}
	return r;
}

void D2B(int x1, int y1, int x2, int y2){
	if(x1<x2 && y1<y2 && ind<data.size()){
		if(data[ind]=='D'){
			int xm = MID(x1,x2);
			int ym = MID(y1,y2);
			ind++;
			//printf("Dividinig (%d,%d),(%d,%d) at (%d,%d)...\n",x1,y1,x2,y2,xm,ym);
			D2B(x1,y1,xm,ym);
			D2B(x1,ym,xm,y2);
			D2B(xm,y1,x2,ym);
			D2B(xm,ym,x2,y2);
		}else{
			//printf("Appending data[%d]=%d...\n",ind,data[ind]);
			for(int i=x1;i<x2;i++){
				for(int j=y1;j<y2;j++)
					v[i][j]=data[ind];
			}
			ind++;
		}
	}
}

void B2D(int x1, int y1, int x2, int y2){
	if(x1<x2 && y1<y2){
		//check all equal
		int sum=0,req=0;
		for(int i=x1;i<x2;i++){
			for(int j=y1;j<y2;j++){
				sum+=(v[i][j]-'0');
				req++;
			}
		}
		int isEqual = (sum==req) || (sum==0);
		if(isEqual){
			ans += v[x1][y1];
		}else{
			int xm = MID(x1,x2);
			int ym = MID(y1,y2);
			ans += 'D';
			B2D(x1,y1,xm,ym);
			B2D(x1,ym,xm,y2);
			B2D(xm,y1,x2,ym);
			B2D(xm,ym,x2,y2);
		}
	}
}

int main() {
	// your code goes here
	char ch;
	cin>>ch;
	while(ch=='B' || ch=='D'){
		int x,y;
		cin>>x>>y;
		data="";
		ans="";
		string inp;
		while(cin>>inp,inp.size()>1 || inp[0]=='0' || inp[0]=='1'){
			data+=inp;
			//if(inp.size()<50 && max_char==50)max_char=inp.size();
		}
		if(ch=='B'){
			create_v(x,y);
			B2D(0,0,x,y);
			printf("D%4d%4d\n",x,y);
			cout<<split(ans)<<endl;
		}else{
			ind=0;
			D2B(0,0,x,y);
			printf("B%4d%4d\n",x,y);
			cout<<split(x,y)<<endl;
		}
		ch=inp[0];
	}
	return 0;
}
