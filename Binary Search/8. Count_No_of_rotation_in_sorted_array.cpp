// A Sorted rotated array is given. Find the minimum number of rotation that this array has been rotated.
// EX:- Input :: [ 14, 19, 21, 23, 35, 45, 2, 7, 9 ]  Then OUTPUT :: 3
// Because This array was initially following :- 
// [2,7,9,14,19,21,23,35,45] --> [7,9,14,19,21,23,35,45,2] --> [9,14,19,21,23,35,45,2,7] --> [14,19,21,23,35,45,2,7,9]

// Logic - Find the index of minimum element then return (Total_Element - index)
// If A[Mid-1] > A[Mid] < A[Mid+1]  then A[mid] is the lowest Element 

// Note :- Must Check the Array boundry because when Mid= 1st index then [Mid-1] is not possible 
// similarly when Mid=Last element then [Mid+1] is not possible 
// therefore MOD (%) is required to ensure we didn't cross array boundry

int Count_Array_Rotated(int c[],int size)  
{
    int low=0, high=size-1;
    // Finding the index of lowest element
    while(low<=high)       
    {
        int mid = low + (high-low)/2;   // Finding the middle element
        int next= (mid+1)%size;         // Finding the Next element after Mid 
        int prev = (mid-1+size)%size;   // finding the previous eement before Mid
        
        if(c[mid]<c[next] && c[mid]<c[prev])
            return size-mid;            // Mid is the index the smallest element
        else if(c[mid]>c[0])            // Check Which part is Unsorted because element will not be found in Sorted portion
            low = mid + 1;
        else if(c[mid]<c[size-1])
            high = mid-1;
    }
    return 0; // In case Array is already sorted then 0 rotations.
}
