class Solution {
public:
    int merge(vector<int>& nums,int low,int mid,int high){
        int cnt = 0;
        int j = mid + 1;
        for(int i = low; i <= mid; i++){
            while(j <= high && (long long)nums[i] > 2LL * nums[j]) j++;
            cnt += (j - (mid + 1));
        }

        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> left(n1), right(n2);

        for(int i=0; i<n1; i++) left[i] = nums[low + i];
        for(int i=0; i<n2; i++) right[i] = nums[mid + 1 + i];

        int i=0, k=low, l=0;
        while(i<n1 && l<n2){
            if(left[i] <= right[l]) nums[k++] = left[i++];
            else nums[k++] = right[l++];
        }
        while(i<n1) nums[k++] = left[i++];
        while(l<n2) nums[k++] = right[l++];

        return cnt;
    }

    int ms(vector<int>& nums,int low,int high){
        if(low >= high) return 0;
        int mid = (low + high) / 2;
        int cnt = ms(nums,low,mid);
        cnt += ms(nums,mid+1,high);
        cnt += merge(nums,low,mid,high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return ms(nums,0,nums.size()-1);
    }
};
