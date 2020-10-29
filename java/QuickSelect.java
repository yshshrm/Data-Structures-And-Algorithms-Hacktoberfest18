class QuickSelect {
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i]; 
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public int partition(int[] nums,int i,int j) {
        int l = i - 1;
        Random r = new Random();
        int p = i + r.nextInt(j - i + 1);
        swap(nums,p,j);
        int pivot = nums[j];
        for(int k=i;k<j;k++) {
            if(nums[k]<pivot) {
                l++;
                swap(nums,k,l);
            }
        }
        swap(nums,l+1,j);
        return l+1;
    }
    public int findKthLargest(int[] nums, int k) {
        int r = nums.length - 1;
        k = r - k + 2;
        int l = 0;
        while(l<=r) {
            int p = partition(nums,l,r);
            if(p==k-1)
                return nums[p];
            else if(p<k-1) {
                l = p + 1;
            }
            else
                r = p - 1;
        }
        return -1;
    }
}
