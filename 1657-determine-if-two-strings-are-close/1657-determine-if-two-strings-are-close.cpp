class Solution {
public:
    bool closeStrings(string word1, string word2) {       
        int ans=1;
        vector<int>mp(26, 0), mp1(26, 0), cnt(26, 0), cnt1(26, 0);
        
        for(int i=0;i<word1.size();i++){
            mp[word1[i]-'a']++;
            cnt[word1[i]-'a']=1;     // i.e it is present
        }
        
        for(int i=0;i<word2.size();i++){
            mp1[word2[i]-'a']++;
            cnt1[word2[i]-'a']=1;
        }
        sort(mp.begin(), mp.end());
        sort(mp1.begin(), mp1.end());
        
        return mp==mp1 && cnt==cnt1;
    }
};