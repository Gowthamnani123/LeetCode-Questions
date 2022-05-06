class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() or st.top().first != s[i])
            {
                st.push({s[i],1});
            }
            else
            {
                auto prev = st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            if(st.top().second == k)
            {
                st.pop();
            }
        }
        string str = "";
        while(!st.empty())
        {
            auto curr = st.top();
            st.pop();
            while(curr.second--)
            {
                str += curr.first;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};