/*
Exercises are relevant and kinda specific for the exam 

Risolvere con la tecnica della memoization il seguente problema: calcola numeri 
descritto dall'equazioe "g(n) = g(n-1) + g(n-2) + g(n-3)", con g(0) = 1, g(1) = 1, g(2) = 1


gMem[1...MAX_VALUE] // vettore globale

InitGMem(i)
for i = 0 to MAX_VALUE
    gMem[i] = -1

GMem(i)

if(gMem[i] != -1)
    return gMem[i]

if(i == 0 || i == 1 || i == 2)
    return gMem[i] = 1


return gMem[i] = (GMem(i-1) + GMem(i-2) + GMem(i-3))

*/