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
	    vector<long> a(4);
	    for(int i=0;i<4;i++)
	    {
	        cin>>a[i];
	    }
	    
	    long store = a[0];
	    
	    sort(a.begin(),a.end());
	    int index = lower_bound(a.begin(),a.end(),store) - a.begin();
	    
	    cout<<(4-index-1)<<"\n";
	    
	}
	
	return 0;
}
