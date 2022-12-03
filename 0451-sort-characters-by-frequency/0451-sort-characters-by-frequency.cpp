class Solution {
public:
    
    bool static cmp(pair<long int, char>a, pair<long int, char>b){
        return a.first > b.first;
    }
    
    string frequencySort(string s){
        
        string str="";
        map<char, long int>mp;
        vector<pair<long int, char>>v;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(auto e:mp){
            v.push_back(make_pair(e.second, e.first));
        }   
        
        sort(v.begin(), v.end(), cmp);
                        
        for(auto e:v){
            long int cnt=e.first;
            while(cnt--)
                str+=e.second;
        }
        
        return str;
    }
};