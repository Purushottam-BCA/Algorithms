/*
:::::::::::: Heart of Heap Sort => Heapify Process ::::::::::  

TIME - O(H) where H is the height of the node

   Max_heapify( A[] , index )
   {
      Left = index * 2;
      Right = index * 2 + 1;
      Largest = index;

      if(Left <= A.Heapsize && A[Left)>A[Largest])   // Left <= A.Heapsize ::- To check whether Left Child Exist or Not
          Largest = Left;
      if(Right <= A.Heapsize && A[Right)>A[Largest])  // Right <= A.Heapsize ::- To check whether Right Child Exist or Not
          Largest = Right;

       if(Largest != index)
          {
            swap(A[index],A[Largest]);
            Max_heapify( A, Largest );
          }
   }
 
::::::::::: Building Max-Heap From array :::::::::::::::

Logic :- Since all Leaf are already Max-heap , So no need to apply heapify on them. So we should start from last Non-leaf member [N/2].
TIME - O(n)
SPACE - O(log n)

    build_Max_heap( array [] )
    {
      A.Heap_Size = array.length();
      for ( i = N/2 ; i>=0; i--)  
         Max_heapify( array , i );
    }

:::::::::::::: Applying HEAP SORT :::::::::::::::
Logic => 
    1. Build a Max-Heap. So biggest element in the array will be present at TOP.
    2. Start a Loop i = last element to 2. (Going from Last Smallest Item To Top)
      3. Take the last element of array and Swap with the top . SWAP( A[i], A[1] );
      4. Now Top element appears on Last. Its OK. So we will reduce the Heap by 1. Because TOP is already at its correct position.
      5. A.Heap_Size = A.heap_Size-1;
      6. Again we have to Keep the top element at Root. So we will apply Max_Heapify( Array , 1)
      7. Again Largest ELement will be at TOP . Again repeat Step 3 to Step 6.
      
- - - - - - - -ALGORITHM -- - -- -- - --- --

TIME => n.log.n 

Heap_Sort ( Array[] )
{
  Build_Max_Heap( Array );   // Build A Max-Heap : O(n)
 
  for ( i = Array.length ; i>1; i-- )  // O(log n)
  {
    Swap( Array[i], Array[1] );
    A.Heap_Size = A.Heap_Size-1;
    Max_Hapify( Array , 1 );
  }
}

::::::::::::: Extract Max => deleting Biggest Element from Heap , But still we have to maintain heap property.  :::::::::::::::::
TIME => O(log n)

Logic :- Temp = A[1]
         A[1] = A [Last] // Last element at root position
         A.Heap_Size--;
         Max_heapify ( A, 1 );
         return Temp;

Algorithm :-

    int Extract_Max( Arr[] )
    {
      Temp = Arr[1];
      Arr[1] = Arr[n];
      Arr.Heap_Size = Arr.Heap_Size-1;
      Max_heapify( Arr, 1);
      return Temp;
    }
        
  
:::::::::::: Increase Value of a Node by Key ::::::::::::::::::

void Increase_key ( Arr [], Index, New_Val )
{
  if(Arr[Index] > New_val) return;
  
  Arr[Index] = New_Val;
  while(Index >1 && Arr[Indx] > Arr[Index/2])
  {
    Swap ( Arr[index], Arr[index/2]);
    Index/=2;
  }  
}
        
     
:::::::::::::::::::: Insert Element in max-Heap :::::::::::::::::::::::

LOGIC :- Insert it at last and then Match it with parent to maintain Heap.

Void Insert_In_Heap( Arr[], Element )
{
  Index = Arr[].length();
  Arr[Index+1] = Element;
  Index = Index+1;
  while(Index>1 && Arr[Index/2]<Arr[Index])
  {
    swap (Arr[Index], Arr[index/2]);
    Index/=2;
  }
}

*/
