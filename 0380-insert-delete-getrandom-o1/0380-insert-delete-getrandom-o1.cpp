class RandomizedSet {
    
public:   
    vector<int>arr;
    unordered_map<int, int>mp;
    
    RandomizedSet() {}
    
    bool insert(int val){
        if(mp.find(val)!=mp.end())
            return false;
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        
        int sz=arr.size()-1;
        int curr_ele_idx=mp[val];
        int last_ele=arr[sz];
        
        swap(arr[curr_ele_idx], arr[sz]);
        mp[last_ele]=curr_ele_idx;
        mp.erase(val);
        arr.pop_back();
   
        return true;
    }
    
    int getRandom() {
      // a[rand()%a.size()] will give random value of array in the range of a[0] to a[a.size()-1].
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */