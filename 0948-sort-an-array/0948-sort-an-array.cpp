class Solution {
public:
    void heapify(vector<int> &arr, int n, int idx){
        int largest = idx, left = 2*idx+1, right = 2*idx+2;
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        if(idx != largest){
            swap(arr[idx], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    void buildHeap(vector<int> &nums, int n){
        for(int i = n/2-1; i >= 0; --i)
            heapify(nums, n, i);
    }
    void heapSort(vector<int> &nums){
        int n = nums.size();
        buildHeap(nums, n);
        int size = n - 1;
        while(size >= 0){
            swap(nums[0], nums[size]);
            heapify(nums, size, 0);
            size--;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};