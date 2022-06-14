#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    
	    vector<int> a(n);
	    long sum = 0;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum += a[i];
	    }
	    
	    if(m >= sum)
	    {
	        cout<<0;
	    }
	    else
	    {
	        cout<<(sum - m);
	    }
	    cout<<"\n";
	}
	
	return 0;
}
