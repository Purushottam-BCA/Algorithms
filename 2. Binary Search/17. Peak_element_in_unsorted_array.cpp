/* Binary Search on ANSWER

Till now we have applied binary search only on sorted array but we can apply it to the unsorted array as well in some condition.

APPROACH :- In that case we have to define some criteria for both cases :-
  CASE-1 :  If A[mid] element satisfies the criteria then return index or element whatever required.
  CASE-2 :  If A[mid] doesn't satisfy the criteria then we have to define some other criteria to move in left or right direction.

----------------------------------------------------------------------------------------------------------------------------------
PROBLEM :- FIND PEAK ELEMENT OF ARRAY 

A peak element is an element that is strictly greater than its neighbors.  

If A[i-1] < A[i] > A[i+1]
Else if 1st element in array is greater than second element then 1st element can also be Peak.
Else if Last element in array is greater than second Last element then Last element can also be Peak.

Given an integer array A[], find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that A[-1] = A[n] = -∞. You must write an algorithm that runs in O(log n) time.

## Example 1:

Input: A = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

## Example 2:

Input: A = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

## Example 3:

Input: A = [1,2,14,23,31,42,96]
Output: 6

*/

// ---------- Approach 1 ---------------

int Peak_element_in_unsorted_array(int a[],int size)
{
    int low=0,high=size-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid>0 && mid<size-1)
        {
            if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
                return mid;
            else if(a[mid]<a[mid-1])
                high = mid-1;
            else if(a[mid]<a[mid+1])
                low = mid+1;
        }
        else if((mid==0 && (a[mid]>a[mid+1]))||(mid==size-1 &&(a[mid]>a[mid-1])))
            return mid;
    }
    return -1;
}

// --------------- Approach-2 ---------------------

int Peak_element_in_unsorted_array(int a[],int size)
{
    int low=0,high=size-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid>0 && mid<size-1)
          {
            if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
                return mid;
            else if(a[mid]<a[mid-1])
                high = mid-1;
            else if(a[mid]<a[mid+1])
                low = mid+1;
          }
        else if(mid==0)
          {
            if(a[0]>a[1])
                return 0;
            else
                return 1;
          }
        else if(mid==size-1)
        {
            if(a[mid]>a[mid-1])
                return mid;
            else
                return mid-1;
        }
    } // End of while loop 
} // End of Function


int main()
{
    int d[]{2,5,3,9,21,29,5,33,69};
    int size=sizeof(d)/sizeof(d[0];
                              
    cout<<Peak_element_in_unsorted_array(d,size);
    return 0;
}
                              
