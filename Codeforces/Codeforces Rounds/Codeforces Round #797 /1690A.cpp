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
	    long n;
	    cin>>n;
	    
	    long ans = n/3;
	    long first;
	    long second;
	    long third;
	    
	    if(n % 3 == 2)
	    {
	        second = ans+1;
	        first = ans+2;
	        third = ans-1;
	    }
	    else if(n % 3 == 1)
	    {
	        second = ans+1;
	        first = ans+2;
	        third = ans-2;
	        
	        if(third == 0)
	        {
	            second = ans;
	            third = ans-1;
	        }
	    }
	    else
	    {
	        second = ans;
	        first = ans+1;
	        third = ans-1;
	    }
	    
	    cout<<second<<" "<<first<<" "<<third<<"\n";
	}
	
	return 0;
}
