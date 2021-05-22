// A Sorted rotated array is given. find an element in this array. 
// if element exist then return its index else return -1

// ################ Small [ Other Functions is required ] #################

int Find_in_Sorted_Rotated ( int a[], int size, int item )
{
    int low=0, high;
    int min_pos = Count_Array_Rotated(a,size);  // Finding the index of minimum element in sorted rotated array 
    if(a[min_pos]==item)                        // If this is the element then return the index
        return min_pos;
    int temp = bin_search(a,0,min_pos+1,item);    // Search in first half
    if(temp==-1)                                  // If Element is not found in first half then search in 2nd half
        temp = bin_search(a,min_pos+1,size,item); // search in 2nd Half
          if(temp==-1)                            // If Element is not found then return -1
                return -1;
    return temp;  // Else return the index
}

// ################# Long Solution ###################

int Find_in_Sorted_Rotated ( int a[], int size, int item )
{
    int low=0, high;
    int min_pos = Count_Array_Rotated(a,size);  // Finding the index of minimum element in sorted rotated array 
    
    if(a[min_pos]==item)  // If this is the element then return the index
        return min_pos;
    
    // Search in 1st half 
    high=min_pos;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]>item)
            high = mid-1;
        else
            low=mid+1;
    }
    
    // Search in 2nd half
    low =  min_pos;
    high = size-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]>item)
            high = mid-1;
        else
            low=mid+1;
    }
    return -1;
}
