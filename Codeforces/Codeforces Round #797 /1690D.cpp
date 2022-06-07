#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long problemD(long n,long k,string s)
{
    map<char,long> m = {{'B',0},{'W',0}};
    long ans = INT_MAX;
    
    for(long i=0;i<k;i++)
    {
        m[s[i]]++;
    }
    
    ans = min(ans,m['W']);
    
    for(long i=k;i<n;i++)
    {
        m[s[i-k]]--;
        m[s[i]]++;
        ans = min(ans,m['W']);
    }
    
    return ans;
}

int main() {
	// your code goes here
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	long t;
	cin>>t;
	
	while(t--)
	{
	    long n,k;
	    string s;
	    cin>>n>>k>>s;
	    
	    cout<<problemD(n,k,s)<<"\n";
	}
	
	return 0;
}
