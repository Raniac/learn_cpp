#include <iostream>
#include <vector>

using namespace std;

class SingleMinStack {
public:
    SingleMinStack() {
        minStack = {};
        n = 0;
    }
    
    void push(int x) {
        if (n == 0) {
            minStack.push_back(x);
            minStack.push_back(x);
        }
        else {
            int tmp = minStack[minStack.size() - 1];
            minStack.push_back(x);
            if (tmp > x) {
                minStack.push_back(x);
            } else {
                minStack.push_back(tmp);
            }
        }
        n += 2;
        return;
    }
    
    void pop() {
        minStack.pop_back();
        minStack.pop_back();
        n -= 2;
        return;
    }
    
    int top() {
        return minStack[n - 2];
    }
    
    int getMin() {
        return minStack[n - 1];
    }
private:
    vector<int> minStack;
    int n;
};

class ExtraMinStack {
public:
    ExtraMinStack() {
        minStack = {};
        myStack = {};
        n = 0;
    }
    
    void push(int x) {
        if (n == 0) {
            minStack.push_back(x);
            myStack.push_back(x);
        }
        else {
            int tmp = minStack[n - 1];
            myStack.push_back(x);
            if (tmp > x) {
                minStack.push_back(x);
            } else {
                minStack.push_back(tmp);
            }
        }
        n++;
        return;
    }
    
    void pop() {
        myStack.pop_back();
        minStack.pop_back();
        n--;
        return;
    }
    
    int top() {
        return myStack[n - 1];
    }
    
    int getMin() {
        return minStack[n - 1];
    }
private:
    vector<int> minStack;
    vector<int> myStack;
    int n;
};

int main() {
    ExtraMinStack* obj = new ExtraMinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int res1 = obj->getMin();
    cout << res1 << endl;
    obj->pop();
    int res2 = obj->top();
    cout << res2 << endl;
    int res3 = obj->getMin();
    cout << res3 << endl;
    return 0;
}