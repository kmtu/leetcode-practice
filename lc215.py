import random

def partition(A, s, e):
    '''
    Partition array A into two segments with a randomly picked pivot element
    such that those elements on the left of pivot are larger than the
    pivot and those on the right are no greater. Return the index of pivot
    after partitioning.

    Parameters
    ----------
    A : list of int
        Unordered list (array)
    s : int
        Start index
    e : int
        End index

    Returns
    -------
    int
        Pivot index after partitioning
    '''
    p = random.randint(s, e)

    # swap pivot to the end
    pv = A[p]
    A[p] = A[e]
    A[e] = pv

    # q points to the end of the partition that is larger than pivot
    q = s - 1
    for i in range(s, e):
        a = A[i]
        if a > pv:
            # swap i and q+1
            q += 1
            A[i] = A[q]
            A[q] = a

    # swap pivot back from end to q+1 
    q += 1
    a = A[e]
    A[e] = A[q]
    A[q] = a

    return q

def get_kth_largest(A, k, s, e):
    '''
    Get the Kth largest number in the list.

    Parameters
    ----------
    A : list of int
        Unordered list
    k : int
        k for kth largest element to be fetched
    s : int
        Start index
    e : int
        End index

    Return
    ------
    int
        Value of the kth largest element
    '''
    q = partition(A, s, e)
    if k == q:
        return A[q]
    elif k > q:
        return get_kth_largest(A, k, q+1, e)
    else:
        return get_kth_largest(A, k, s, q-1)


# Leetcode solution
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return get_kth_largest(nums, k - 1, 0, len(nums) - 1)

