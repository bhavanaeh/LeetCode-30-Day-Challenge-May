/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])//no anomaly
                    l=mid+2;
                else if(nums[mid]==nums[mid-1])//anomaly introduced
                    r=mid-2;
                else
                    return nums[mid];
                                        
            }
            else
            {
                if(nums[mid]==nums[mid-1])//no anomaly
                    l=mid+1;
                else
                    r=mid-1;
                //mid cannot be anomaly here strictly has to have even number of elements to the left but mid is odd here so there are odd number of elements to the left. Thus, mid cant be an anomaly
            }
        }
        return nums[l];
    }
};