class FindSumPairs {
public:
    vector<int> nums2;
    unordered_map<int,int> mp1, mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums2 = nums2;
        for(int ele : nums1) mp1[ele]++;
        for(int ele : nums2) mp2[ele]++;
    }
    // 1, 2    1,1
    // 2, 3    2,1
    // 3, 1    4,2
    //         5,2
    void add(int i, int val) {
        mp2[nums2[i]]--, mp2[nums2[i]+val]++, nums2[i] += val;
    }
    
    int count(int total) {
        int o = 0;
        for(auto &ent : mp1)
            if(mp2.find(total-ent.first) != mp2.end())
                o += (ent.second*mp2[total-ent.first]);
        return o;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */