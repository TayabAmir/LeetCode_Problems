class Solution {
public:
    int getCommon(vector<int> freq){
        int count = 0;
        for(int i = 1; i < freq.size(); i++)
            if(freq[i] == 2) count++;
        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C(A.size()), freq(A.size()+1,0);
        for(int i = 0; i < A.size(); i++){
            freq[A[i]]++,freq[B[i]]++;
            C[i] = getCommon(freq);
        }
        return C;
    }
};