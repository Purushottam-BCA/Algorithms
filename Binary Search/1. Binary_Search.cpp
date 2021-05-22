// Simple Binary Search on Ascending Order Arranged Elements
// [ 4, 6, 9, 10, 15, 27, 39, 40 ]

int bin_search(int a[],int size,int item)  
{
    int low = 0;
    int high = size-1;
    while(low<=high)
    {
        int mid=low +(high-low)/2;
        if(a[mid]==item)
            return mid;   // If element found return its index
        else if(a[mid]>item)
            high = mid-1;
        else
            low =  mid+1;
    }
    return -1;  // if element not found return -1
}

// Simple Binary Search on Descending Order Arranged Elements
// [ 84, 66, 59, 50, 45, 27, 19, 10 ]

int bin_search_desc(int a[],int size,int item) 
{
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=low +(high-low)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]>item)
            low = mid+1;
        else
            high =  mid-1;
    }
    return -1;
}

// TIME COMPLEXITY - O(log n)
