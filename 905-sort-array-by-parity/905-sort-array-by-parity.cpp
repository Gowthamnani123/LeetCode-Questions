class Solution {
public:
        vector<int> sortArrayByParity(vector<int>& a) {
            int i=0;
        for (int j = 0; j < a.size(); j++)
            if (a[j] % 2 == 0) 
            {
                swap(a[i++], a[j]);
            }
        return a;
    }
};