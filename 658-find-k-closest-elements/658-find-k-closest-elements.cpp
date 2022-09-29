class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), L = 0, R = n - k;
        while (L < R) {
            int mid = (L + R) / 2;            
            if(arr[mid] == arr[mid + k])          
                if (arr[mid] < x) L = mid + 1;
                else R = mid;
				
            else if (abs(x - arr[mid]) <= abs(x - arr[mid + k])) R = mid;  
            else L = mid + 1;                                               
        }
        return vector<int>(begin(arr) + L, begin(arr) + L + k);
    }
};