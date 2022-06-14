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
	    int n;
	    cin>>n;
	    
	    int num;
	    map<int,int> m;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>num;
	        m[num]++;
	    }
	    
	    int odd = 0;
	    int even = 0;
	    
	    for(auto ptr : m)
	    {
	        if(ptr.second % 2)
	        {
	            odd++;
	        }
	        else
	        {
	            even++;
	        }
	    }
	    
	    if(even % 2 == 0)
	    {
	        cout<<(odd + even)<<"\n";
	    }
	    else
	    {
	        cout<<(odd + even - 1)<<"\n";
	    }
	}
	
	return 0;
}
