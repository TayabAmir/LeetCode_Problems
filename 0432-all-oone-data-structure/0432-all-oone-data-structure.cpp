class AllOne {
public:
    unordered_map<string,int> mp;
    set<pair<int,string>> mp2;
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
        if(mp[key] > 1)
            mp2.erase({mp[key]-1,key});
        mp2.insert({mp[key],key});
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key] == 0){
            mp2.erase(mp2.find({mp[key]+1,key}));
            mp.erase(mp.find(key));
        } else{
            mp2.erase({mp[key]+1,key});
            mp2.insert({mp[key],key});
        }
    }
    
    string getMaxKey() {
        return (!mp2.empty()) ? mp2.rbegin()->second : "";
    }
    
    string getMinKey() {
        return (!mp2.empty()) ? mp2.begin()->second : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */