#include <iostream>
#include "/c/Users/Benny/Documents/Projects/learn_csapp/learn_cpp/datastructures/lists.cpp"

using namespace std;

void bubbleSort1(NodeSequence& S) {
    int n = S.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            NodeSequence::Iterator prec = S.atIndex(j - 1);
            NodeSequence::Iterator succ = S.atIndex(j);
            if (*prec > *succ) {
                int tmp = *prec;
                *prec = *succ;
                *succ = tmp;
            }
        }
    }
}

void bubbleSort2(NodeSequence& S) {
    int n = S.size();
    for (int i = 0; i < n; i++) {
        NodeSequence::Iterator prec = S.begin();
        for (int j = 1; j < n - i; j++) {
            NodeSequence::Iterator succ = prec;
            ++succ;
            if (*prec > *succ) {
                int tmp = *prec;
                *prec = *succ;
                *succ = tmp;
            }
            ++prec;
        }
    }
}