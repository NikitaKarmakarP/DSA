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

MergeSort Source Code in C (Helpful Explanation)
In the last tutorial, we deeply covered the concepts behind the merge sort algorithm. We saw its implementation as well via some pseudocodes. We implemented the merge sort algorithm to sort a few arrays. I hope you did learn everything till here. If you couldn't, I recommend first going through the last lecture before proceeding to the programming part. Today, we’ll solely look at the programming part of the merge sort algorithm in C.

Before we move on to the programming part, let's revise a few things

Whenever you are asked to sort an array using the merge sort algorithm, first divide the array until the size of each subarray becomes 1.
Now, since an array or subarray of size 1 is considered already sorted, we call our merge function, which merges these subarrays into bigger sorted subarrays.
And finally, you end up with your array fully sorted. Voila!

Understanding the code snippet below:

1. Before we proceed with the functions merge and mergeSort, let’s copy the printArray part in our current programs. Copying would save us some time. Having a print function helps a lot seeing the contents of the array before and after the sorting. Anyways, I have attached the snippet for printArray as well.

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

Code Snippet 1: Creating the printArray function

2. The next step is to define an array of elements. I'd rather copy that from our previous lecture. Then define an integer variable for storing the size/length of the array.

Creating the merge function:

3. This is just the merge function, whose only job is to merge two sorted arrays into a bigger sorted array. I’d recommend keeping the pseudo code with you for better understanding. Create a void function merge that takes the array and the integer indices low, mid, and high as its parameters. Create integer variables i,j, and k for iterating through the array A and an auxiliary array B. Create this integer array B of size, but for now, we would choose some larger size, say 100. Initialize i with low, j with mid+1, and k with low Here, i marks the current element of the first subarray of array A, and j marks the first element of the second subarray. And, k is the iterator for array B to insert the smaller of elements at indices i and j.

Run a while loop until either i or j or both reaches the threshold of their corresponding subarray. Inside the loop, see if the element at index i is smaller than the one at index j. If it is, insert element at index i in index k of array B i.e., B[k] = A[i] and increment both i and k by 1, else, insert element at index j in index k of array B i.e. B[k] = A[j] and increment both j and k by 1.

The above ends when either i or j or both reach its corresponding subarray’s end. Now, run two separate while loops for inserting the remaining elements, if left, in both the subarrays. And this would finish filling all the elements in sorted order in array B. The only thing left is just to copy the sorted array back again to array A. And we are done.

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

Code Snippet 2: Creating the merge function

 

Creating the mergeSort function:

4. Create a void function mergeSort and pass the address of the array and the index variables low and high as its parameters. Here, the lower index would be 0 for the first time, and the higher index would be length -1 for the first time.

We would recursively call this function only if low is less than high; that is, there are at least two elements in the subarray. Otherwise, we break off from the loop.

Create an integer variable mid for holding the index of the mid element, which would be. Now recursively call the mergeSort function twice but with parameters changed to (low, mid-1) for the left subarray and (mid+1, high) for the right subarray. Applying mergeSort sorts the left half and the right half separately. This is where we would merge them back in the array. Call the merge function and pass the array, its index variables low, mid, and high. And this would return a sorted array.

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

Code Snippet 3: Creating the mergeSort function

 

Here is the whole source code:

#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}

Code Snippet 4: Program to implement the Merge Sort Algorithm

 

Let us now check if our functions work well. Consider an array A of length 7.

    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);

Code Snippet 5: Using the mergeSort function

 

And the output we received was:

9 1 4 14 4 15 6
1 4 4 6 9 14 15 
PS D:\MyData\Business\code playground\Ds & Algo with Notes\Code>

# Linked Representation Of Binary Tree in C

Understanding the code snippet below:

1. The first thing would be to create the struct Node we discussed yesterday. So, create a struct Node. Inside the structure, we have three embedded elements, first is an integer variable data to store the data of the node, second is a struct Node pointer called left to store the address of the left child node, and third is again a struct Node pointer called right to store the address of the right child node.

struct node{
    int data;
    struct node* left;
    struct node* right;
};

Code Snippet 1:  Creating the struct Node

 

2. Our next job would be to create the root node. In main, create struct Node pointer p, and assign to it the memory in heap using malloc. Don’t forget to include the header file <malloc.h> or <stdlib.h> And then using the pointer operator →, assign some data to its data element and NULL to both the left and the right element of the struct Node p.

3. And now we can proceed to creating the further nodes. We have different ways to do that. First one is to copy the whole thing we did for the root node twice for both the children and name them p1 and p2. This will create three separate nodes p, p1 and p2. Then just link them together by changing the left element of p from NULL to the left node’s pointer p1 and the right element of p from NULL to the right node’s pointer p2.

4. But this is somewhere redundant and not considered a good practice as we are copying the whole thing again and again. So, we would create a dedicated function for creating a node.

Creating the createNode function:

5. Create a struct Node* function createNode, and pass the data for the node as the only parameter. Create a struct Node pointer n. Reserve a memory in heap for n using malloc. Basically, do the same thing we did above. Point the left and the right element of the struct n to NULL, and fill the data in the data element. And return the node pointer n you created. This would simply create a node, and you can now very easily link them as per your wish via main to the other nodes.

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}
Code Snippet 2:  Creating the function createNode

 

Here is the whole source code:

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL

Code Snippet 3:  Implementing binary trees in C

 

Now we can see if our program doesn’t revert any error while we try linking 3 nodes p, p1 and p2.

    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    p->left = p1;
    p->right = p2;

    Code Snippet 4:  Using createNode to create nodes.

No, it didn’t show any error, and this is how we created three nodes and linked two of them to the root node.  You can imagine how it would have looked.



