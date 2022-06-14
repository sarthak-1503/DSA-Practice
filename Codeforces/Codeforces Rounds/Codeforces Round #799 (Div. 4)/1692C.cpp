#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> posBishop(vector<string> &a)
{
    for(int i=1;i<7;i++)
    {
        for(int j=1;j<7;j++)
        {
            if(a[i][j] == '#')
            {
                if(a[i-1][j-1] == '#' && a[i+1][j-1] == '#' && a[i+1][j+1] == '#' && a[i-1][j+1] == '#')
                {
                    return {i+1,j+1};
                }
            }
        }
    }
    
    return {0,0};
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
	    vector<string> a(8);
	    for(int i=0;i<8;i++)
	    {
	        cin>>a[i];
	    }
	    
	    vector<int> ans = posBishop(a);
	    cout<<ans[0]<<" "<<ans[1]<<"\n";
	}
	
	return 0;
}
