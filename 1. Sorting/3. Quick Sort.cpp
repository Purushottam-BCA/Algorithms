/*
We follow the partitioning approach here. In every pass, we fix n element at its correct position.

Time - O(n Log n)

-------------- Pseudocode -----------

Quick_Sort(A,0,Last)

    First we store the last element of array as Pivot. then a loop start from j= first index to last_index-1. 
    we take one more pointer 'i' that will keep track of how many elements are less tan Pivot. initially I=j-1

    Loop start 
      if(A[j]<=Pivot or last element then 
          Increase value of I (I++)
          swap(A[i],A[j]) 
          J = j + 1
      Else 
          j = J + 1
    Loop End. 
    Now we ave to set the correct position of pivot. So ,
    Swap(A[Last_Element], A[I+1]);
    return P=I+1

Next Time Quick_Sort(A,0,P-1)
Next Time Quick_Sort(A,P+1,Last)

-------- Algorithm ---------

Partition(A[], start, end)
  Step 1. Pivot = A[last];
  Step 2. set j = start_index , i=j-1;
  Step 3. Loop while( j < Last )
          i. if ( A[j] <= Pivot )
               i++;
               Swap(A[i],A[j])
          ii. J++
  Step 4. Swap (A[last],A[i+1])
  Step 5. Return (New_Index = I+1)
  
  
------ Actual Quick Sort -----------

Quick_Sort( Array [], Start, End)
{
  if(Start < End)
  {
    Index = Partion(Array , Start, End )
    Quick_Sort ( Array , Start , Index -1 )
    Quick_Sort ( Array , Index+1 , End )
  }
}

*/
