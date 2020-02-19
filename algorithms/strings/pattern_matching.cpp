#include <iostream>
#include <vector>

using namespace std;

/*
# ========== Pattern Matching Algorithm ========== #

## ========== Brute Force ========== ##

Algorithm BruteForceMatch(T, P):
    Input: Strings T (text) with n characters and P (pattern) with m characters
    Output: Starting index of the first substring of T matching P, or an
        indication that P is not a substring of T
    for i <- 0 to n - m do
        j -> 0
        while (j < m and T[i+j] = P[j]) do
            j <- j + 1
        if j = m then
            return i
    return "There is no substring of T matching P"
*/

/*
## ========== Boyer-Moore Algorithm ========== ##

The main idea of the BM algorithm is to improve the running time of the brute-
force algorithm by adding two potentially time-saving heuristics. Roughly
stated, these heuristics are as follows:

Looking-Glass Heuristic: When testing a possible placement of P against T,
    begin the comparison from the end of P and move backward to the front.
Character-Jump Heuristic: During the testing of a possible placement of P
    against T, a mismatch of text character T[i] = c with the corresponding 
    pattern character P[j] is handled as follows. If c is not contained
    anywhere in P, then shift P completely past T[i] (for it cannot match
    any character in P). Otherwise, shift P until an occurrence of character
    c in P get aligned with T[i].

if c is in P, last(c) is the index of the last (rightmost) occurrence of c in P.

Algorithm BMMatch(T, P):
    compute function last
    i <- m - 1
    j <- m - 1
    repeat
        if P[j] = T[i] then 
            if j = 0 then
                return i
            else
                i <- i - 1
                j <- j - 1
        else
            i <- i + m - min(j, 1 + last(T[i]))
            j <- m - 1
    until i > n - 1
    return "There is no substring of T matching P"

*Jumping Step Illustration*

Case 1:
x x x x x x x x x x x x x x A x x x x x x x x x x x x x x x x x
Get mismatch c: x A x x x x B x x x
Jump by m-(l+1):          x A x x x x B x x x
Case 2:
x x x x x x x x x x x x x x A x x x x x x x x x x x x x x x x x
Get mismatch c: x x x x x x B x A x
Jump by m-j:      x x x x x x B x A x
*/

int BMMatch(const string& text, const string& pattern) {
    vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1;
    if (i > n - 1) return -1;
    int j = m - 1;
    do {
        if (pattern[j] == text[i]) {
            if (j == 0) return i;
            else {
                i--;
                j--;
            }
        }
        else {
            i = i + m - min(j, 1 + last[text[i]]);
            j = m - 1;
        }
    } while (i <= n - 1);
    return -1;
}

vector<int> buildLastFunction(const string& pattern) {
    const int N_ASCII = 128;
    int i;
    vector<int> last(N_ASCII);
    for (i = 0; i < pattern.size(); i++) {
        last[pattern[i]] = i; // implicit cast to ASCII code
    }
    return last;
}

/*
## ========== Knuth-Morris-Pratt Algorithm ========== ##

The main idea of the KMP algorithm is to preprocess the pattern string P so as
to compute a failure function, f, that indicates the proper shift of P, so
that, to the largest extent possible, we can reuse previously performed comparisons.
Specifically, the failure function f(j) is defined as the length of the longest
prefix of P that is a suffix of P[1..j] (note that we do not put P[0..j] here).
We also use the convention that f(0) = 0. Later, we discuss how to compute the
failure function is that it "encodes" repeated substrings inside the patter itself.

Example:
    j | 0 1 2 3 4 5
  P[j]| a b a c a b
  f(j)| 0 0 1 0 1 2

Algorithm KMPMatch(T, P):
    f <- KMPFailureFunction(P)
    i <- 0
    j <- 0
    while i < n do
        if P[j] = T[i] then
            if j = m - 1 then
                return i - m + 1
            i <- i + 1
            j <- j + 1
        else if j > 0 {no match, but we have advanced in P} then
            j <- f(j - 1) {j indexes just after prefix of P that just match}
        else
            i <- i + 1
    return "There is no substring of T matching P"

Algorithm KMPFailureFunction(P):
    Input: String P (pattern) with m characters
    Output: The failure function f for P, which maps j to the length of the
        longest prefix of P that is a suffix of P[1..j]
    i <- 1
    j <- 0
    f(0) <- 0
    while i < m do
        if P[j] = P[i] then
            f(i) <- j + 1
            i <- i + 1
            j <- j + 1
        else if j > 0 then
            {j indexes just after a prefix of P that must match}
            j <- f(j - 1)
        else
            f(i) <- 0
            i <- i + 1

*Illustration*

a b a c a a b a c c a b a c a b a a b b
1 2 3 4 5 6
a b a c a b
          7
    --> a b a c a b
    |     8 9 101112
    |     a b a c a b
    |             13
    |             a b a c a b
no comparison       141516171819
needed here         a b a c a b
*/

int KMPmatch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> fail = computeFailureFunction(pattern);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            if (j == m - 1) return i - m + 1;
            i++; j++;
        }
        else if (j > 0) j = fail[j - 1];
        else i++;
    }
    return -1;
}

vector<int> computeFailureFunction(const string& pattern) {
    vector<int> fail(pattern.size());
    fail[0] = 0;
    int m = pattern.size();
    int j = 0;
    int i = 1;
    while (i < m) {
        if (pattern[j] == pattern[i]) {
            fail[i] = j + 1;
            i++; j++;
        }
        else if (j > 0) j = fail[j - 1];
        else {
            fail[i] = 0;
            i++;
        }
    }
    return fail;
}
