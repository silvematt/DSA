/*
                PSEUDOCODE

Hash_Search(T, k)

i = 0

notfound = false
repeat
    j = hash(k, i)
    if(T[j] == NULL)
        notfound = true
    else
        if(T[j] == k)
            return j
        else
            i = i+1

until notfound == true || i == m

error("value not found for key k")
*/
