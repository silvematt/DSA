/*
Exercises are relevant and kinda specific for the exam 

Gennaro è ghiotto di babà. Per il compleanno di Gennaro, sua madre si reca in pasticceria per acquistarne. 
Sfortunatamente la pasticceria non vende babà singoli, ma soltanto N torte di babà. Ogni torta t ha un costo C[t] ed un numero di babà 
B[t]. Infine, la madre ha deciso di spendere in pasticceria al massimo E euro.

Scrivere un algoritmo, in pseudocodice, che, ricevendo come input le N torte a disposizione e E la somma massima a disposizione, 
restituisca il numero massimo dei babà che possono essere acquistati. 
Si assuma che sia possibile acquistare parti di torta. (7 punti)

t = torta
C[t] = costo di una torta
B[t] = numero baba
E = capacità

Knapsack(n, E)

curCapacity = E
curNumBaba = 0

x[1...n.size]

for t = 1 to n.size
    x[t] = 0

Sort(n) // sort by B[t]/C[t], we want to maximise the number of cake

int t = 1
while(curCapacity > 0.0 && t <= n.size)
    if(curCapacity >= C[t])
        curNumBaba += B[t]
        x[t] = B[t]
        curCapacity -= C[t]
    else
        fraction = curCapacity / C[t]
        x[t] = fraction * B[t]
        curNumBaba += x[t]
        curCapacity = 0.0

    t++

return (curNumBaba);
*/