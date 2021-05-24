/*
Given a sorted array in which all elements appear twice (one after one) and one element appears only once. Find that element in O(log n) complexity.

Example: 

Input:   arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
Output:  4

Input:   arr[] = {1, 1, 3, 3, 4, 4, 5, 5, 7, 7, 8}
Output:  8 
*/

// ~~~~~~~~~~~~~~~~~~ Approach-1 ~~~~~~~~~~~~~~~~~~~~~

int single_element_in_sorted_array(const vector <int>&a)
{
    int low=0, high=a.size()-1;
    if(a.size()==0) return -1;
    while(low<high)
    {
        int mid=low+ (high-low)/2;
        if(mid & 1) // Odd
        {
            if(a[mid]==a[mid-1])
                low=mid+1;
            else
                high=mid;
        }
        else    // Even
        {
            if(a[mid]==a[mid+1]) // Before that all elements are already in pair so no need to go back
                low = mid+2;
            else
                high=mid;
        }
   }
   return a[low];
}


// ~~~~~~~~~~~~~~~~~~ Approach-2 ~~~~~~~~~~~~~~~~~~~~~

int single_element_in_sorted_array(const vector <int>&a)
{
    int low=0, high=a.size()-1;
    if(a.size()==0) return -1;
    if(a.size()==1) return a[0];

    while(low<high)
    {
        int mid=low+ (high-low)/2;
        int res = ((mid&1)?mid-1:mid+1);
        int temp2 = ((mid&1)?mid+1:mid+2);
        if(a[mid]==a[res])
             low= temp2;
        else
             high=mid;
    }
   return a[low];
}

// ~~~~~~~~~~~~~~~~~~ Approach-3 ~~~~~~~~~~~~~~~~~~~~~

int single_element_in_sorted_array3(const vector <int>&a)
{
    int low = 0, high = a.size()- 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mid % 2 == 1) mid--;  // if it odd then Before it must be one extra element apart from pair, so mid = mid-1
            if (a[mid] != a[mid + 1])
                high = mid;  // Saerch in left part only as right is already sorted
        // Next:     1 1 3 3 5 6 6 :: here  3=3 and before  3 already a pair so no chance there then moveto low=mid+2
            else low = mid + 2;
    }
    // 'low' should always be at the beginning of a pair.
    // When 'low > high', low must be the single element.
    return a[low];
    }

// ### MAIN PROGRAM ###

    int main()
    {
      vector <int> a={2,2,3,3,4,4,5,5,6,6,9,9,10,11,11};
      cout<<single_element_in_sorted_array(a);
      return 0;
    }
