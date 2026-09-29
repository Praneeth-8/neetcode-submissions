class KthLargest {
public:
    vector<int> heap;
    int k_element;
    void upheap(vector<int>& nums,int index){
        while(index>0){
            int parent = (index-1)/2;

            if(parent<0){
                break;
            }
            if(nums[parent]>nums[index]){
                swap(nums[parent],nums[index]);
                index=parent;
            }
            else{
                break;
            }
        }
    }
    void downheap(vector<int> &nums,int index){
        int parent = index;

        while(1){
            int left = 2*parent +1;
            int right = 2*parent +2;
            if(left>=nums.size()){
                break;
            }
            int smaller = left;
            if(nums[parent]<=nums[left] && nums[parent]<=nums[right]){
                break;
            }
            if(right<nums.size() && nums[right]<nums[left]){
                smaller = right;
            }
            if(nums[parent]<=nums[smaller]){
                break;
            }
            swap(nums[parent], nums[smaller]);
            parent=smaller;
        }
    }

    void heappush(vector<int>&nums,int val){
        nums.push_back(val);
        int n = nums.size();
        upheap(nums,n-1);
    }
    int heappop(vector<int>&nums){
        int val = nums[0];
        int n=nums.size();
        swap(nums[0],nums[n-1]);
        nums.pop_back();
        downheap(nums,0);
        return val;
    }

    KthLargest(int k, vector<int>& nums) {
        for(int num : nums){
            heappush(heap,-num);
        }
        k_element=k;

        
    }
    
    int add(int val) {
        heappush(heap,-val);
        vector<int> temp;

        for(int i=0;i<k_element-1;i++){
            int val = heappop(heap);
            temp.push_back(val);
        }
        int kth = -1*heap[0];

        for(int num:temp){
            heappush(heap,num);
        }
        return kth;
        
        
    }
    
};
