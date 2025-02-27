/*
Exercises are relevant and kinda specific for the exam 

Si scriva un algoritmo che calcoli la distanza di editing tra il proprio nome e il proprio cognome

LevenstheinDistance

c[i][j] = { i se j = 0
            j se i = 0

                { c[i][j-1]   + 1
            min { c[i-1][j]   + 1
                { c[i-1][j-1] + delta

                delta = 0 se X[i] == Y[j] altrimenti 1


LevDistance(X, x, Y, y)

c = [x][y]

// array start at 1 in pseudo
for i = 1 to x
    c[i][0] = i
    
for j = 1 to y
    c[0][j] = j

for i = 1 to x
    for j = 1 to y
        if X[i] == Y[j]
            delta = 0
        else
            delta = 1

        c[i][j] = min(c[i][j-1]+1, c[i-1][j]+1, c[i-1][j-1]+delta)

return c[x][y]


Main()

nome = "MATTIA"
cognome = "SILVESTRO"

LevDistance(nome, nome.size, cognome, cognome.size)

*/