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

