// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    unordered_map<int,int> mp;
    int fun(int n, int x, int y, int z){
        if (n == 0){
            return 0;
        }
        if (mp.find(n)!=mp.end()) {return mp[n];}
        int xc = INT_MIN,yc = INT_MIN,zc = INT_MIN;
        if (n >= x) xc = fun(n-x,x,y,z);
        if (n >= y) yc = fun(n-y,x,y,z);
        if (n >= z) zc = fun(n-z,x,y,z);
        mp[n] = 1 + max(xc,max(yc,zc));
        return mp[n];
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans = fun(n,x,y,z);
        return (ans > 0) ? ans : 0;
        // return fun(n,x,y,z);
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends