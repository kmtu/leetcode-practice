import unittest
import random
import sys
from lc215 import *

class P215Test(unittest.TestCase):
    def setUp(self):
        def gen_list(num):
            low = -100
            high = 100
            return [random.randint(low, high) for i in range(num)]
        self.num_test = 100
        self.test_lists = []
        for i in range(self.num_test):
            len_A = random.randint(1, 100)
            self.test_lists.append(gen_list(len_A))

    def test_partition(self):
        for A in self.test_lists:
            len_A = len(A)
            s = random.randint(0, len_A - 1)
            e = random.randint(s, len_A - 1)
            q = partition(A, s, e)
            self.assertTrue(all(a > A[q] for a in A[s:q]))

    def test_get_kth_largest(self):
        for A in self.test_lists:
            B = A.copy()
            len_A = len(A)
            k = random.randint(1, len_A)
            res = get_kth_largest(A, k - 1, 0, len_A-1) 
            B.sort()
            self.assertEqual(res, B[-k])

