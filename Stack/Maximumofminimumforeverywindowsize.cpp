#include <bits/stdc++.h>
using namespace std;

// 1. First evaluvate the index of Previous smaller elements and Next smaller elements.
// 2. Find the range in which it is smallest then fill the vector at that range index
// 3. Iterate from end to start index and replace with large number b/w consequtive

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print(int v[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> maxOfMin(int arr[], int n)
{
    stack<int> st;
    vector<int> next(n);
    next[n - 1] = n;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            next[i] = st.top();
        }
        else
        {
            next[i] = n;
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    vector<int> prev(n);
    prev[0] = -1;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            prev[i] = st.top();
        }
        else
        {
            prev[i] = -1;
        }
        st.push(i);
    }
    print(arr);
    print(prev);
    print(next);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
    {
        cout << next[i] - prev[i] - 1 << " ";
        ans[next[i] - prev[i] - 1] = max(arr[i], ans[next[i] - prev[i] - 1]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    ans.erase(ans.begin(), ans.begin() + 1);
    cout << endl;
    print(ans);
    return ans;
}

int main()
{
    int arr[] = {35, 22, 74, 33, 88};
    maxOfMin(arr, 5);
}