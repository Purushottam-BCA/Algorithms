// Time Complexity :: Best case --> O(N)    Worst case --> O(N^2)

void Insertion_Sort( int a[], int size)
{
  int key,j;
  for(int i=1; i<size; i++)
  {
    key = a[i];
    j = i-1;
    while(j>=0 && a[j]>key)
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
}
