/*
Exercises are relevant and kinda specific for the exam 

Si consideri un file F costituito da 100000 simboli:
( ! ) & = ?
 Le cui frequenze sono rispettivamente:
 11%, 6%, 23%, 17%, 14%, 29%

 Si scriva un programma, in pseudocodice, che costruisca l'albero di huffman
 e determinare per ogni simbolo la sua codifica di huffman.

 Calcolare l'evenutale risparmio di memoria che si otterrebbe codificando il file con la 
 codifica di huffman e invece di una codifica a lunghezza fissa


Huffman(a)

n = |a|
Q = a; // Q is a min priority queue, containing the elements of a where the key is the frequency

while(Q.size > 1)
    z = allocate_node()
    z.left = EXTRACT_MIN()
    z.right = EXTRACT_MIN()
    z.frequency = z.left.frequency + z.right.frequency
    Insert(Q, z)

return EXTRACT_MIN() // root of the huffman tree

*/