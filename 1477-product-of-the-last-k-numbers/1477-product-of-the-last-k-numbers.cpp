class ProductOfNumbers {
public:
    vector<int> v;
    int idx = -1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            v.clear();
            idx = -1;
        } else if(idx == -1){
            v.push_back(num);
            idx++;
        } else {
            v.push_back(v[idx] * num);
            idx++;
        }
    }
    
    int getProduct(int k) {
        if(k > v.size()) return 0;
        else if(k == v.size()) return v[idx];
        else return v[idx] / v[idx-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */