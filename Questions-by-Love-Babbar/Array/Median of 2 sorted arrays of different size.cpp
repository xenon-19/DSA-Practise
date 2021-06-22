// Question
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

//---------Code--------
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(); 
        double la, ra, lb, rb;
        if(m<n) return findMedianSortedArrays(b, a);
        //cout << "n = " << n << " m = " << m << endl;
        if(n==0){
            if(m%2==0) return ((float)b[m/2-1]+(float)b[m/2])/2;
            else return b[m/2];
        }
        
        int p1, p2;
        int start = 0, end = n;
        while(start<=end){
            p1 = (start+end)/2;
            p2 = (n+m+1)/2 - p1;
            if(p1==0) la = INT_MIN;
            else la = a[p1-1];
            if(p1==n) ra = INT_MAX;
            else ra = a[p1];
            if(p2==0) lb = INT_MIN;
            else lb = b[p2-1];
            if(p2==m) rb = INT_MAX;
            else rb = b[p2];
            
            if(la <= rb && lb <= ra){
                if((m+n)%2==0) return (max(la, lb) + min(ra, rb))/2;
                else return max(la, lb);
            }else if(la > rb) end = p1-1;
            else start = p1+1;
        }
        return -1;
    }
};
