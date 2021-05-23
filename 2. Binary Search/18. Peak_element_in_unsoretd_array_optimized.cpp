// Find the Pick element in unsorted array.

// Optimized Solution - 1

int findPeakElement(const vector<int> &num) 
{
     int low = 0, high = num.size() - 1;
     while (low < high - 1) 
     {
      int mid = (low + high) / 2;
      if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1])
          return mid;
      else if (num[mid] > num[mid + 1])  // It means :: if (num[mid] < num[mid-1] ) then go to left side
          high = mid - 1;
      else                               // It means :: if (num[mid] < num[mid+1] ) then go to right side
          low = mid + 1;
     }
    return num[low] > num[high] ? low : high;   // At last low & high will point to two neighbours return the biggest among them
}

// Optimized Solutios-2

 int findPeakElement(const vector<int> &nums) 
    {
        int start=0, end=nums.size();
        while (start < end) 
        {
            int mid=start+(end-start)/2;
            if (mid < nums.size()-1 && nums[mid] < nums[mid+1])  
                start=mid+1;
            else 
                end=mid;
        }
        return start;
    }
