/*
----------------------------------------------------------------------------------
                                    PSEUDOCODE

As per the Cormen book "Introduction to Algorithms", pseudocode arrays start at 1

HuffmanTree(C)

n = |C|
Q = C       // Q is a min priority queue

for i = 1 to n-1
    z = allocate_node()
    x = z.leftPtr = EXTRACT_MIN(Q)
    y = z.rightPtr = EXTRACT_MIN(Q)
    z.freq = x.freq + y.freq
    INSERT(Q, z)

return EXTRACT_MIN(Q) // this is the root of the huffman tree

----------------------
    TIME COMPLEXITY
----------------------
T(n):     O(n logn)
*/

