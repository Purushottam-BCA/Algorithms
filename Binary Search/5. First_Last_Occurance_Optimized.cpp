// In a non decreasing sorted array find the First & last index of an element
// If Array = {5,8,10,10,10,10,10,18,24,65,90,100} and Element = 10 then First_Index=2 & last_Index = 5
// ( Return Element index if found else return -1,-1 )

// ################## Approach-1 ###################

  vector<int> First_Last_Occurance(int a[], int array_size, int item) 
  {
    int low = 0, high = array_size;
    vector<int> v(2,-1);     // Declaring a vector of size=2
  
    // -------------- Finding First Index ---------------
    while (low < high)
    {
        mid = low + (high-low) / 2;
        if (a[mid] >= item)   
            high = mid;
        else
            low = mid + 1;
    }
    if(a[low]!=item)
        return v;
    else
        v[0]=low;

    // --------------- Finding last Index ---------------

    high = array_size;  // No need to set low as it is actually at its correct position
    while (low < high)
    {
        mid = low + (high-low) / 2;   
        if (a[mid] > item)
            high = mid;
        else
            low = mid + 1;
    }
    v[1] = low-1;
    return v;
}

// ################## Approach-2 ###################

vector<int> First_Last_Occurance2(int A[], int array_size, int item) 
{
    int low = 0, high = array_size - 1;
    vector<int> v(2, -1);
  
    // -------------- Finding First Index ---------------
  
    while (low < high)  // Finding First Index
    {
        int mid = (low + high) /2;
        if (A[mid] < item)
            low = mid + 1;
        else
            high = mid;
    }

    if (A[low]!=item) // If Element not found
        return v;
    else
        v[0] = low;   // Else Store Index

    // --------------- Finding last Index ---------------
  
    high = array_size-1;  // Now Search for Right ; We don't have to set low to 0 the second time.
    while (low < high)
    {
        int mid = (low + high) /2 + 1;	// Make mid biased to the right
        if (A[mid] > item)
            high = mid - 1;
        else
            low = mid;				// So that this won't make the search range stuck.
    }
    v[1] = high;
    return v;
}
