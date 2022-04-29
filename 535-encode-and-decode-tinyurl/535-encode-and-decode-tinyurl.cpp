class Solution {
public:

    unordered_map<string,int> freq;
    unordered_map<string,string> s_to_l;
    string encode(string longUrl) {
        string t="";
        for(int i=0;i<10;i++)
            t+=(rand()%256);
        
        freq[t]++;
        t+=to_string(freq[t]);
        
        s_to_l[t]=longUrl;
        
        return t;
    }
    string decode(string shortUrl) {
        return s_to_l[shortUrl];
    }
};


// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));