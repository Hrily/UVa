#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--){
        int c=0;
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            if(s[i]=='M')c++;
            if(s[i]=='F')c--;
        }
        cout<<((c==0 && s.size()>2)?"LOOP\n":"NO LOOP\n");
    }
    return 0;
}
