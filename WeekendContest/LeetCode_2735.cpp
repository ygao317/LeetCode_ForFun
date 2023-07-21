class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long result=0;
        int n=nums.size();
        for(auto y: nums) result+=y; // without shift
        for(int i=0;i<n;i++) // start to shift
        {
            long long sum=0;
            int temp=nums[0];
            for(int j=0;j<n;j++) // take using the min cost during the shift
            {
                if(j==n-1)
                {
                    if(nums[j] > temp)
                        nums[j]=temp;
                }
                else if(nums[j] > nums[j+1])
                {
                    nums[j]=nums[j+1];
                }
                sum+=nums[j];
            }
            sum+=(long long ) x * (i+1);
            result= min(result,sum);
        }
        return result;
    }
};
