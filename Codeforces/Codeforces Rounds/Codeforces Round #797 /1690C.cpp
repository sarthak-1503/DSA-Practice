#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> problemC(vector<ll> s,vector<ll> f,long n)
{
    vector<ll> ans(n);
    
    for(long i=1;i<n;i++)
    {
        s[i] = max(s[i],f[i-1]);
    }
    
    for(long i=0;i<n;i++)
    {
        ans[i] = f[i] - s[i];
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
	    long n;
	    cin>>n;
	    vector<ll> s(n), f(n);
	    
	    for(long i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    
	    for(long i=0;i<n;i++)
	    {
	        cin>>f[i];
	    }
	    
	    vector<ll> ans = problemC(s,f,n);
	    
	    for(long i=0;i<n;i++)
	    {
	        cout<<ans[i]<<" ";
	    }
	    cout<<"\n";
	}
	
	return 0;
}
