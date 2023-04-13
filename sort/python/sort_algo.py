########################################################
# Bubble Sort
# This is an implementation of the bubble sort algorithm. The function takes an array as input and returns the sorted array. 
# The algorithm works by iterating through the array multiple times and swapping adjacent elements if they are in the wrong order. 
# The time complexity of bubble sort is O(n^2).

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
########################################################
#Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr
# This is an implementation of the selection sort algorithm. The function takes an array as input and returns the sorted array. 
# The algorithm works by dividing the input array into a sorted part and an unsorted part, and selecting the smallest element 
# from the unsorted part and swapping it with the leftmost unsorted element. 
# The time complexity of selection sort is O(n^2).
########################################################
# Insertion sort
def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr

# This is an implementation of the insertion sort algorithm. The function takes an array as input and returns the sorted array. 
# The algorithm works by taking one element at a time from the input array and inserting it into its correct position in the sorted part of the array. 
# The time complexity of insertion sort is O(n^2).
#######################################################
# Merge sort
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]
        merge_sort(left_half)
        merge_sort(right_half)
        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1
    return arr

# This is an implementation of the merge sort algorithm. The function takes an array as input and returns the sorted array. 
# The algorithm works by dividing the input array into two halves, recursively sorting each half, and then merging the sorted halves into a single sorted array.
# The time complexity of merge sort is O(n log n).

#######################################################
#Quick sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        left_half = [x for x in arr[1:] if x <= pivot]
        right_half = [x for x in arr[1:] if x > pivot]
        return quick_sort(left_half) + [pivot] + quick_sort(right_half)
# This implementation of the quick sort algorithm takes an array as input and returns the sorted array. 
#The algorithm works by selecting a pivot element from the input array and partitioning the array into two sub-arrays - one with elements smaller than the pivot and another with elements greater than the pivot. 
#The sub-arrays are recursively sorted using the same quick sort algorithm, and then concatenated with the pivot element in the middle to form the final sorted array.

# The time complexity of quick sort is O(n log n) on average, but can degrade to O(n^2) in the worst case if the pivot element is selected poorly.
