//Binary Search - O(log(min(n1,n2)))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) 
            return findMedianSortedArrays(nums2,nums1);
        int l=0,h=n1; 
        while(l<=h){
            int mid1=(l+h)/2; 
            int mid2=(n1+n2+1)/2 - mid1; 
            int l1= mid1==0 ? INT_MIN : nums1[mid1-1];
            int l2= mid2==0 ? INT_MIN : nums2[mid2-1];
            int r1= mid1==n1 ? INT_MAX : nums1[mid1]; 
            int r2= mid2==n2 ? INT_MAX : nums2[mid2];
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else 
                    return max(l1,l2);
            }else if(l1>r2)
                h=mid1-1;
            else 
                l=mid1+1;
        }
        return 0.0;
    }
};