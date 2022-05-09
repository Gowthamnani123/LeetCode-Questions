class Solution {
public:
   vector<string> letterCombinations(string digits) {
        if(digits.empty()) 
            return {};
        vector<string> map = {"","","abc","def","ghi", "jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res(1,"");
        
        for(auto digit: digits)
        {
            string letters = map[digit-'0'];
            vector<string> next;
            for(auto ch : letters)
                for(auto elem : res)
                    next.push_back(elem+ch);
            swap(res,next);
        }
        
        return res;
    }
};