#include <cstdio>
#include<cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define ABS(x) (((x)<0)?-(x):(x))

int a, b, lineCounter;
vector<int> row;

int place(int r, int c){
	for(int prev=0; prev<c; prev++)
		if(row[prev]==r || (ABS(row[prev]-r)==ABS(prev-c)))
			return 0;
	return 1;
}

void backtrack(int c){
	if(c==8){// && row[a]==b){
		printf("%2d	%d",++lineCounter,row[0]+1);
		for(int  i=1;i<8;i++) printf(" %d",row[i]+1);
		printf("\n");
	}
	for(int r=0;r<8;r++){
		if(place(r,c)){
			row[c]=r;backtrack(c+1);
			row[c]=0;
		}
	}
}

int main(){
	//int t;
	//scanf("%d",&t);
	//while(t--){
	//	scanf("%d %d",&a,&b);
	//	a--;b--;
		row.assign(8,0);
		lineCounter=0;
		printf("#	1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		printf("\n");
	//}
	return 0;
}
