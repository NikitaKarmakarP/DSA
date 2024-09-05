#include<stdio.h>
int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
    
}

int binarySearch(int arr[], int size, int element){
    int low, mid,high;
    low = 0;
    high = size-1;
    //keep searching until low <=> high convert
    while (low<=high){
    mid=(low+high)/2;
    if (arr[mid]==element)
    {
        return mid;
    }
    if(arr[mid]>element)
    {
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
}
    //Searching ends

    return -1;
}

int main(){
    // Unsorted array for Linear Search
    // int arr[] = {1, 5, 3, 123, 64, 444, 56, 225, 73};
    // int size = sizeof(arr)/sizeof(int);

    // Sorted array for Binary Search
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr)/sizeof(int);
    int element = 444;
    int searchIndex = linearSearch(arr, size, element);
    printf("The element %d was found at index %d\n", element, searchIndex);
    return 0;
}