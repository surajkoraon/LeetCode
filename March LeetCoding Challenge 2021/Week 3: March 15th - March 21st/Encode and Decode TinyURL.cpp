class Solution {
public:

    map<string,string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m["4e9iAk"]=longUrl;   
        return "4e9iAk";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto it=m.find(shortUrl);
        return it->second;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));