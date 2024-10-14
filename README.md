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


Understanding the code snippet below:

1. First of all, we wouldn't start from scratch creating the struct Node and the createNode function and everything. So just copy the whole thing we did in our previous programming lecture and paste them here. This would save us a lot of time.

2. Create all the five nodes, using the createNode function, and link them using the arrow operator, and altering their left and right pointer elements. This creates our tree. The next thing would be to create the preOrder function.

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
Copy
Code Snippet 1: Creating the Binary tree

 

Creating the preOrder function:

3. Create a void function preOrder and pass the pointer to the root node of the tree you want to traverse as the only parameter. Inside the function, check if the pointer is not NULL, otherwise we wouldn't do anything. So, if it is not NULL, print the data element of the root struct node by using the arrow operator.

4. After you finish visiting the root node, simply call the same function recursively on the left and the right subtrees and you're done. Applying recursion does your job in its own subtle ways. It considers the left subtree as an individual tree and applies preorder on it, and the same goes for the right subtree.

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

Code Snippet 3: Implementing the preOrder function

Now simply call the preOrder function passing the pointer to the root node as its parameter and see if it actually visits each node.

    preOrder(p);
Copy
Code Snippet 4: Using the preOrder function

And the output we received was:

4 1 5 2 6 

# PostOrder Traversal in a Binary Tree (With C Code)

Understanding the code snippet below:

1. Following what we did before, we wouldn't start from scratch creating the struct Node and the createNode function and everything. We would just copy the whole thing we did in the PreOrder Traversal programming part and paste them here. This would save us a lot of time and help us compare both Pre and Post Order traversals.

2. Create all the five nodes, using the createNode function, and link them using the arrow operator and altering their left and right pointer element. This creates our tree. The next thing would be to create the postOrder function.

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
Copy
Code Snippet 1: Creating the Binary tree

 

Creating the postOrder function:

3. Create a void function postOrder and pass the pointer to the root node of the tree you want to traverse as the only parameter. Inside the function, check if the pointer is not NULL, otherwise we wouldn't do anything. If it is not NULL, we would not directly print the data of the root since this time it's the last one to get visited.

4. So first, you simply call the same function recursively on the left subtree and then the right subtree using the left and the right elements of the root struct. Once called, recursively, the function now considers the left subtree as an individual tree and applies postorder on it, and the same goes for the right subtree.

5. After visiting them both, you just print the data element of the root node marking it visited. And you are done.

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
Copy
Code Snippet 2: Creating the postOrder function

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
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    printf("\n");
    postOrder(p);
    return 0;
}
Copy
Code Snippet 3: Implementing the postOrder function

Now simply call both preOrder and the postOrder function passing the pointer to the root node as their parameter and see how their results vary.

    preOrder(p);
    printf("\n");
    postOrder(p);
Copy
Code Snippet 4: Using the preOrder and the postOrder function

And the output we received was:

4 1 5 2 6 
5 2 1 6 4

# InOrder Traversal in a Binary Tree (With C Code)

Understanding the code snippet below:

You know what to do first, right? We avoid doing repetitions, so we wouldn't start from scratch creating the whole struct Node and the createNode thing again rather we would just copy the whole thing we did in the PostOrder Traversal programming part and paste them here. This would get us even the codes for PreOrder and PostOrder.
You should now be able to create Binary Tree yourselves by now. So, just create the same binary tree we observed above using the createNode function. And if you are still not sure about creating a binary tree, follow the previous lectures. Let’s now move to create the InOrder function.
Creating the inOrder function:

Create a void function inOrder and pass the pointer to the root node of the tree you want to traverse as the only parameter. Inside the function, check if the pointer is not NULL, as we are doing every time, since this is the base case for the recursion to stop. If it is NULL, we wouldn’t do anything but if it isn’t we would call the same function recursively on the left subtree using the left element of the root struct.
After we finish visiting the left subtree, we print the data element of the root node indicating it as visited.
Having visited both the left subtree and the root, we now move to the right subtree and call it recursively. This completes our flow. And we are done visiting all the nodes.
void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
Copy
Code Snippet 1: Creating the InOrder function

 

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
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p);
    // printf("\n");
    inOrder(p);
    return 0;
}
Copy
Code Snippet 2: Implementing the inOrder function

Now simply call all the traversal functions, preOrder, postOrder, and inOrder passing the pointer to the root node as their parameter and see how they work.

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
Copy
Code Snippet 3: Using the preOrder, the postOrder, and the inOrder functions

And the output we received was:

4 1 5 2 6 
5 2 1 6 4 
5 1 2 4 6

# Checking if a binary tree is a binary search tree or not

n the last lecture, we got to know about one more variety of binary tree, called binary search trees. We discussed all the properties of a binary search tree. We drew a fine line between binary trees and binary search trees. Today, we’ll delve into their differences and distinguish a binary search tree from a normal binary tree. And check if a binary tree is a binary search tree or not.

But before that let’s briefly revise the properties of a binary search tree once.

Properties of a binary search tree:

1. All nodes of the left subtree are lesser than the node itself.
2. All nodes of the right subtree are greater than the node itself.
3. Left and Right subtrees are also binary trees.
4. There are no duplicate nodes.
5. The InOrder traversal of a binary search tree gives an ascending sorted array.
And the last one is of utmost importance to us. And that is what we use the most to check if a binary tree is a binary search tree or not. So, basically, we’ll check if a binary tree is a binary search tree or not by making an InOrder Traversal in the tree and analyzing its order. I have attached the source code below. Follow it as we proceed.

Understanding the code snippet below:

Since we’ll create a binary search tree at first which is nothing but a binary tree only and we’ll use the InOrder traversal function as well, we’ll simply copy everything we did in our last programming tutorial where we learned to create the function inOrder. And we did this because we avoided doing repetitions in the course and starting from scratch, creating the whole struct Node and the createNode thing again and all the functions would have made the lecture redundant. And this has also saved us a lot of time.
I just hope that you've followed all the way from the start of the Binary Search lecture and not just jumped right here. Make sure you check them all before proceeding.

Let’s now just create a function to check if the InOrder traversal of the binary tree is in ascending order or not.
Creating the function isBST:

Create an integer function isBST and pass the pointer to the root node of the tree you want to check as the only parameter. Inside the function, check if the pointer is not NULL, as we have been checking the whole time, and this is also considered as the base case for the recursion to stop. If it is NULL, we would simply return 1 since an empty tree is always a binary search tree. Else, this is a complex yet understandable part. You should follow what I am saying.
Create a static struct Node pointer prev initialised with NULL. This maintains the pointer to the parent node. And since the root node doesn't have any parent, we have initialized it with NULL and made it static.
Now, see if the left subtree is a Binary Search Tree or not, by calling it recursively. If it is not a BST, return 0 here itself. Else, see if the prev is not NULL otherwise this is the root node of the whole tree and we won't check this condition. If the prev node is not NULL and the current node, which is the root node of the current subtree, is smaller than or equal to the prev node, then we would return 0. Since this violates the increasing orderliness.
If it still passes all the if conditions we have structured above, we will store the current node in the prev and move it recursively to the right subtree. And this is nothing but a modified version of the InOrder Traversal.
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
Copy
Code Snippet 1: Creating the isBST function

I suggest ignoring the recursion and do not trace how the function isBST works if the function isBST is at all confusing. Just note that we have done nothing but the InOrder traversal of the tree, and we have checked if the previous value is smaller than the current value, that's it.

Note: Static variables are used when we don’t want our value for that variable to change every time that function is called.

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
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p); 
    // printf("\n");
    inOrder(p);
    printf("\n");
    // printf("%d", isBST(p)); 
    if(isBST(p)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }
    return 0;
}
Copy
Code Snippet 2: Implementing the isBST function

 

Let’s now check if our function actually works, and it reverts whether our binary tree is a BST or not. We would also like to print the InOrder traversal of the tree.

     inOrder(p);
    printf("\n");
    if(isBST(p)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }
Copy
Code Snippet 3: Using the isBST function

And the output we received was:

1 3 4 5 6    
This is a bst

# C Code For Searching in a BST

Understanding the code snippet below:

1. First of all, we’ll anyway have to create a binary search tree to be able to use it to search some keys. And since we created everything the last time, we’ll just copy everything we have done till the last programming lecture. It covered everything from creating a node to building a tree. It also features all the traversal methods and the isBST function. We copied everything so as to keep everything in one place, and to avoid repeating things in the course, and this has also saved us a lot of time.
2. Let’s create a binary search tree I’ve illustrated below using the createNode function. Creating a binary search tree should be an issue anymore. And if you are still not sure about creating a binary search tree, follow the previous lectures.
3. We’ll do each of the other operations we usually do. But today our focus is on the search operation. Let’s now just create a function to search a key in the binary search tree we created.

Creating the function search:

4. Create a struct Node pointer function search and pass into it the pointer to the root and the key you want to search as two of its parameters.
5. First of all, check if the root is NULL. If the root is NULL, we haven’t found our key, and we‘ll simply return NULL.
6. Now, check if the node we are currently at has the data element equal to the key we were searching for. If it is the case, we have found the key, and we’ll simply return the pointer to the current root.
7. But if we still haven't found the key, it is probably in the left subtree of the root, or in the right subtree of the root. To judge which side to proceed with, we’ll check if the current root is less than or greater than the data element of the root. If it is less than the root, the key probability lies on the left subtree, and hence we would reduce our search space and recursively start searching in the left subtree. Otherwise, we would start searching in the right subtree. Anyways, we are reducing our search space after each comparison.

   struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

Code Snippet 1: Creating the search function

Recursion in the above function is pretty simple this time, unlike the isBST function we did early. Here, we simply decide every time which subtree to pursue next. And recursively go with that. 

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
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct node* n = search(p, 10);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    return 0;
}

Code Snippet 2: Implementing the search function

Now, make sure you store the value returned by the search function in a struct node pointer, say n. We’ll see if our function actually works, and it reverts the pointer to the node it found, or a NULL if it didn't find the key. Let’s search 10, in the above function.

    struct node* n = search(p, 10);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }

    Code Snippet 3: Using the search function

And the output we received was:

Element not found
PS D:\MyData\Business\code playground\Ds & Algo with Notes\Code>
Copy
Figure 1: Output of the above code

And since 10 was not there in the binary search tree we created, the function search returned a NULL. Let’s make it work for something which is there. Let’s use the function to find 3 in the above BST.

    struct node* n = search(p, 3);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
Copy
Code Snippet 4: Using the search function again

And the output we received was:

Found: 3

# Iterative Search in a Binary Search Tree

Understanding the code snippet below:

1. There is nothing much to explain in the code. Although for the people coming right here, we have just copied everything we had done till the last programming lecture which dealt with the search function. It had covered everything from creating a node, to building a tree. It also featured all the traversal methods, and all the other functions. We did this to save ourselves some time.
2. Let’s create a binary search tree I’ve illustrated below using the createNode function. And without doing any further ado, we would move to creating the searchIter

---->Creating the function searchIter:

3. Create a struct Node pointer function searchIter and pass into it the pointer to the root and the key you want to search as two of its parameters.
4. First of all, check if the root’s data itself is the key we were looking for. If the root data is equal to the key, we have found the key, and we’ll return the pointer to the root.
5. If we couldn’t find the key on the root, we’ll further see if our key is greater than or smaller than the root data. If it is smaller than the root data, we will make the root node pointer now point to the left child of the root, using the arrow operator. And if the key is greater than the root data, we’ll make the root node pointer point to the right child of the root
6. And we’ll use a while loop to run steps 4 and 5 iteratively until our root becomes NULL, or we find the key and return from the function.
7. And in the end, if we couldn’t find the key after iterating through the tree, or the root we received in the starting itself was a NULL, we would return NULL.

   struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

Code Snippet 1: Creating the searchIter function

Iteration is more intuitive because you are able to see what's exactly happening and how things end. Even so, recursion is considered a powerful tool.

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
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct node* n = searchIter(p, 6);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    return 0;
}

Code Snippet 2: Implementing the searchIter function

Now, make sure you store the value returned by the searchIter function in a struct node pointer, say n. We’ll see if our function actually works, and it reverts the pointer to the node it found, or a NULL if it didn't find the key. Let’s search 10, in the above function. We did all this time as well.

    struct node* n = searchIter(p, 10);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }

Code Snippet 3: Using the searchIter function

And the output we received was:

Element not found

Figure 1: Output of the above code

And since 10 was not there in the binary search tree we created, the function searchIter returned a NULL. Let’s see if it works for something else. Let’s use the function to find 6 in the above BST.

    struct node* n = searchIter(p, 6);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
Copy
Code Snippet 4: Using the searchIter function again

And the output we received was:

Found: 6

# Insertion in a Binary Search Tree

We know a few facts about binary search trees. And I’ll only mention the ones we will focus on, while we learn the insertion operation.

1. There are no duplicates in a binary search tree. So, if you could search the element you are being asked to insert, you would return that the number already exists.
2. Now, you would follow what we did in the search operation. Here is an example binary search tree, and the element we want to insert is 9.

Now, you would simply start from the root node, and see if the element you want to insert is greater than or less than. And since 9 is greater than 8, we move to the right of the root. And then the root is the element 10, and since this time 9 is less than 10, we move to the left of it. And since there are no elements to its left, we simply insert element 9 there.

This was one simple case, but things become more complex when you have to insert your element at some internal position and not at the leaf.

Now, before you insert a node, the first thing you would do is to create that node and allocate memory to it in heap using malloc. Then you would initialize the node with the data given, and both the right and the left member of the node should be marked NULL.

And another important thing to see here is the pointer you would follow the correct position with. In the above example, to be able to insert at that position, the pointer must be at node 10.

And then you check whether going to the left side is good, or the right. Here you came to the left, but had it been right, we would have updated our pointer ptr further and maintained a second pointer to the previous root. We’ll see all this via our program. That would actually make things simpler to understand.  I have attached the source code below. Follow it as we proceed.

Understanding the source code below:

1. Now, since our main focus would be to create the insert function, we could just copy everything we did in the last programming lecture where we learned the iterative search operation. And this would save us a lot of time. And we would have the createNode and other functions we did before at one place for our exigency.
2. Create a binary search tree of your choice, we would rather go with the one we already had in the program. Now, let’s see the insert

Creating the insert function:

3. So, the first thing we would like to know is whether inserting this new node is even possible or not. For that, create a void function insert and pass the pointer to the root node, and the data of the node you want to insert as its parameters. We will call it
4. Now, we would use two struct pointers to traverse through the array. One of them would be our root which we would traverse through the nodes, and the other one would be prev which stores the pointer to the previous root. SO, just create a struct Node pointer prev to maintain the node you were previously at, at some point in time.
5. Run a while loop that is for until we reach some leaf, and couldn't traverse further. So, run that loop until the root becomes NULL. And inside that loop, make the prev equal to the current root since we would definitely move further because this root is not a NULL. We would either move to the left of this root or to the right of this root. But before that check, if this root itself is not equal to the node we are trying to insert. That is, write an if condition to see if there are any duplicates here. If there is, return from the function here itself.
6. Further in the loop, check if the element you want to insert is less than the current root. If it is, update the root to the left element of the struct root. And if it isn't, update the root to the right element of the struct root. And since we have already stored this root in the prev node, there isn’t any issue updating.
7. And finally, you will have a prev node as the outcome at the end after this loop finishes. Now, the only procedure left now is to link these nodes together, that is the prev node, the new node, and the node next to the prev
8. Now, before you insert, make sure you create that new struct node using malloc, or simply the createNode Fill in the key data into this new node. Now, simply check if the prev->data is less than the key or greater than the key. If it is less, insert our new node to the left of prev, else to right of prev. And that would be it. We are done inserting our new node.


