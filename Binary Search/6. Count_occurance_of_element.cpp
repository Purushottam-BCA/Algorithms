// In a sorted array count the occurance of a particular element
// A = [ 2, 5, 8, 11 ,11 ,11 ,14,18 ] 
// Element = 11 then Answer = 3

// Use Simple Formula :: Count = Last_index - Start_Index + 1

int Count_Element(int a[], int array_size, int item)  
{
    return (last_occurance(a,array_size,item) - first_occurance (a,array_size,item) +1 );
}
