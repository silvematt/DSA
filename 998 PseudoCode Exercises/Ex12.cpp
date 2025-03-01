/*
Exercises are relevant and kinda specific for the exam 

Risolvere con la tecnica della tabulation il seguente problema: calcola numeri 
descritto dall'equazioe "g(n) = g(n-1) + g(n-2) + g(n-3)", con g(0) = 1, g(1) = 1, g(2) = 1

IN PSEUDOCODICE

GMem(i)

if(i == 0 || i == 1 || i == 2)
    return 1

gMem[0...i]

gMem[0] = 1
gMem[1] = 1
gMem[2] = 1

for j = 3 to i
    gMem[j] = gMem[j-1] + gMem[j-2] + gMem[j-3]

return gMem[i]

*/