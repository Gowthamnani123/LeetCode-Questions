class Solution {
public:
        int maxProduct(vector<string> &words)
    {
        int n = words.size(), i = 0, j, ans = 0;
        vector<int> bitmask(n, 0);
        for (string s : words)
        {
            for (j = 0; j < s.size(); j++)
            {
                int val = s[j] - 'a';
                bitmask[i] |= 1 << val;
            }
            i++;
        }

        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (bitmask[i] & bitmask[j])
                    continue;
                int val = words[i].size() * words[j].size();
                ans = max(ans,val);
            }
        }

        return ans;
    }
};