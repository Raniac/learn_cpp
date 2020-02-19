/*
# Longest Common Subsequence #

Proposition 12.3: Given a string X of n characters and a string Y of m characters,
    we can find the longest common subsequence of X and Y in O(nm) time.

Algorithm LCS(X, Y):
    Input: Strings X and Y with n and m elements, respectively
    Output: For i = 0, ... , n-1, j = 0, ... , m-1, the length L[i, j] of a
        longest string that is a subsequence of both the string X[0..i] = x0x1...xi
        and the string Y[0..j] = y0y1...yj
    for i <- -1 to n - 1 do
        L[i, -1] <- 0
    for j <- -1 to m - 1 do
        L[-1, j] m<- 0
    for i <- 0 to n - 1 do
        for j <- 0 to m - 1 do
            if xi = yj then
                L[i, j] <- L[i-1, j-1] + 1
            else
                L[i, j] <- max{L[i-1, j], L[i, j-1]}
    return array L
*/