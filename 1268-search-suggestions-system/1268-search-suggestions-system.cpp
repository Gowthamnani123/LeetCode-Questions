class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
     vector<vector<string>>ans;
      sort(products.begin(),products.end());
     for(int i=0;i<searchWord.length();++i)
     {
         vector<string>temp;
         auto start = lower_bound(products.begin(),products.end(),searchWord.substr(0,i+1));
         int j = 0;
         while(start!=products.end() && (*start).find(searchWord.substr(0,i+1))!= string::npos && j<3)
         {
             temp.push_back(*start);
             start++;
             j++;
         }
        ans.push_back(temp);
     }
    return ans;  
  }
};