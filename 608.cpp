#include <iostream>
using namespace std;
#define ABS(x) ((x<0)?-x:x)


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	    for(int i=0;i<3;i++){
	        string x,y,c;
	        cin>>x>>y>>c;
	        if(c=="even"){
	            for(int j=0;j<x.size();j++)a[x[j]-'A']=10;
	            for(int j=0;j<y.size();j++)a[y[j]-'A']=10;
	        }else if(c=="down"){
                for(int j=0;j<x.size();j++){
                    if(a[x[j]-'A']<=0)a[x[j]-'A']+=-1;
                    if(a[x[j]-'A']==1)a[x[j]-'A']=10;
                }
	            for(int j=0;j<x.size();j++){
                    if(a[y[j]-'A']>=0 && a[y[j]-'A']!=10)a[y[j]-'A']+=1;
                    if(a[y[j]-'A']==-1)a[y[j]-'A']=10;
                }
	        }else{
	            for(int j=0;j<x.size();j++){
                    if(a[x[j]-'A']>=0 && a[x[j]-'A']!=10)a[x[j]-'A']+=1;
                    if(a[x[j]-'A']==-1)a[x[j]-'A']=10;
                }
	            for(int j=0;j<x.size();j++){
                    if(a[y[j]-'A']<=0)a[y[j]-'A']+=-1;
                    if(a[y[j]-'A']==1)a[y[j]-'A']=10;
                }
	        }
	    }
        int max=0,mi=0;
        string flag="";
        for(int i=0;i<12;i++){
            if(max<ABS(a[i]) && a[i]!=10){
                max=ABS(a[i]);
                mi=i;
                flag=(a[i]>0)?"heavy":"light";
            }
        }
        cout<<(char)('A'+mi)<<" is the counterfeit coin and it is "<<flag<<".";
	    cout<<endl;
	}
	return 0;
}
