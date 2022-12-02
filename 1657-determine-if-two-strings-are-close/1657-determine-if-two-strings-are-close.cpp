class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int ans=1;
        if(word1.size()!=word2.size())
            return 0;
        
        unordered_map<char, int>mp, mp1;
        unordered_map<int, int>cnt, cnt1;
        
        for(int i=0;i<word1.size();i++)
            mp[word1[i]]++;
        
        for(int i=0;i<word2.size();i++)
            mp1[word2[i]]++;
        
        for(auto e:mp){
            if(mp1.find(e.first)==mp1.end())
                return 0;
        }
        
        for(auto e:mp){
            cnt[e.second]++;
        }
        
        for(auto e:mp1){
            cnt1[e.second]++;
        }
        
        for(auto e:cnt){
            if(e.second!=cnt1[e.first])
                return 0;
        }
        
        return cnt.size()==cnt1.size() && ans;
    }
};