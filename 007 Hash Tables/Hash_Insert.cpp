/*
                    PSEUDOCODE


Hash_Insert(T, k)

int i = 0;

repeat
    j = hash(k, i)
    if(T[j] == NULL)
        T[j] = k
        return j
    
    i = i+1;
until i == m

    // If you get here, you ran out of space
    error("overflow of table T")

*/
