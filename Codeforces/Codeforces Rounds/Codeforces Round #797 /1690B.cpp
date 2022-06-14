#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string problemB(vector<ll> a,vector<ll> b,long n)
{
    map<pair<ll,ll>,long> m;
    for(long i=0;i<n;i++)
    {
        if(a[i] < b[i])
        {
            return "NO";
        }
        
        m[{a[i]-b[i],b[i]}] = 1;
    }
    
    if(m.size() == 1)
    {
        return "YES";
    }
    
    auto ptr = m.begin();
    
    while(ptr != m.end() && ptr->first.second == 0)
    {
        ptr++;
    }
    
    long curr = -1;
    
    for(auto itr=ptr;itr!=m.end();++itr)
    {
        if(itr == ptr)
        {
            curr = itr->first.first;
        }
        else
        {
            if(itr->first.first != curr)
            {
                return "NO";
            }
        }
    }
    
    return "YES";
}

int main() {
	// your code goes here
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    long n;
	    cin>>n;
	    
	    vector<ll> a(n), b(n);
	    
	    for(long i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    for(long i=0;i<n;i++)
	    {
	        cin>>b[i];
	    }
	    
	    cout<<problemB(a,b,n)<<"\n";
	}
	
	return 0;
}
