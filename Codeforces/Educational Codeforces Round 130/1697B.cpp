#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	long long n,q;
	cin>>n>>q;
	
	vector<ll> a(n);
	
	for(ll i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	sort(a.begin(),a.end(),greater<ll> ());
	
	for(long i=1;i<n;i++)
	{
	    a[i] += a[i-1];
	}
	
	ll x,y;
	
	for(ll i=0;i<q;i++)
	{
	    cin>>x>>y;
	    
	    ll ans = a[x-1];
	    
	    if(x != y)
	    {
	        ans -= a[x-y-1];
	    }
	    
	    cout<<ans<<"\n";
	}
	
	
	
	return 0;
}
