// A Nearly sorted array is given. Search an item in that array if it is found then return its index else return -1.
// A Nearly sorted array means element of (i)th position can be on (i-1)th or (i)th or (i+1)th position in array.

// Logic : FInd the mid element But also Check [Mid-1] & [Mid+1]. 
// if Number found then return its index ; Also we have to check Lower boundary (No negative index) & Upper boundary (No Overflow) of array 
// If A[Mid] > Item Then Search in 1st half ( High = mid -2 ) { We write "Mid-2" because we have alraedy checked "Mid-1" }
// If A[Mid] < Item Then Search in 2nd Half ( Low = Mid + 2 ) { We write "Mid+2" because we have alraedy checked "Mid+1" }

int Nearly_Sorted_Array(int a[], int low, int high, int item)
{
    while(low<=high)
    {
        int mid=low +(high-low)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid+1]==item && mid+1<=high)
            return mid+1;
        else if(a[mid-1]==item && mid-1>=low)
            return mid-1;
        else if(a[mid] > item)
            high = mid-2;
        else if(a[mid] < item)
            low = mid+2;
    }
    return -1;
}
