class Solution {
    int arr[10003];

public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int sum = 0, ans = 0, j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (arr[nums[i]])
            {
                while (j < arr[nums[i]])
                {
                    sum -= nums[j];
                    j++;
                }
            }

            sum += nums[i];
            ans = max(ans, sum);
            arr[nums[i]] = i + 1;
        }

        return ans;
    }
};