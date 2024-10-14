# DSA

# Marge Sort

The programming part of the merge procedure is not that tough. You just follow these steps:

1. Take both the arrays and their sizes to be merged as the parameters of the merge function. By summing the sizes of the two arrays, we can create one larger array.
2. Create three index variables i,j & k. And initialize all of them with 0.
And then run a while loop with the condition that both the index variables i and j don't exceed their respective array limits.
3. Now, at each run, see if A[i] is smaller than B[j], if yes, make C[k] = A[i] and increase both i and k by 1, else C[k] = B[j] and both j and k are incremented by 1.
And when the loop finishes, either array A or B or both get finished. And now you run two while loops for each array A and B, and insert all the remaining elements as they are in the array C. And you are done merging.
4. The pseudocode for the above procedure has been attached below.

void Merge(int A[], int B[], int C[], int n, int m)
{
    int i = 0, j = 0, k = 0;
    while (i <= n && j <= m) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    
    while (i <= n) {  // Copying all remaining elements from A to C
        C[k] = A[i];
        i++;
        k++;
    }
    
    while (j <= m) {  // Copying all remaining elements from B to C
        C[k] = B[j];
        j++;
        k++;
    }
}

Now, this would quite not be our situation when sorting an array using the merge sort. We wouldn’t have two different arrays A and B, rather a single array having two sorted subarrays. Now, I’d show you how to merge two sorted subarrays of a single array in the array itself.

Suppose there is an array A of 5 elements and contains two sorted subarrays of length 2 and 3 in itself.

Here is the representation of the unsorted array A as shown in the image:

  0   1   2   3   4
+---+---+---+---+---+
| 7 | 15|  2|  8| 10|
+---+---+---+---+---+
  Unsorted Array A

This array has five elements, with the values 7, 15, 2, 8, 10, and their respective indices 0, 1, 2, 3, 4.

To merge both the sorted subarrays and produce a sorted array of length 5, we will create an auxiliary array B of size 5. Now the process would be more or less the same, and the only change we would need to make is to consider the first index of the first subarray as low and the last index of the second subarray as high. And mark the index prior to the first index of the second subarray as mid.

Here is the representation of the arrays:
   low   mid    high
    ↓     ↓       ↓
  +----+----+----+----+----+
  | 7  | 15 |  2 |  8 | 10 |
  +----+----+----+----+----+
     0    1    2    3    4
    Unsorted Array A

In this scenario, low = 0, mid = 2, and high = 4, which divides Array A for sorting (possibly using merge sort or another sorting algorithm).

    k
    ↓
  +----+----+----+----+----+
  |    |    |    |    |    |
  +----+----+----+----+----+
     0    1    2    3    4
    Sorted Array B

Array B is empty for now, and k = 0, representing the starting index for filling the sorted values from Array A into Array B during the sorting process.


