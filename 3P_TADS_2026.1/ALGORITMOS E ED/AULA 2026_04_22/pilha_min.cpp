#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
    
public:
	int tam_max;
	stack<pair<int,int>> itens;

    explicit MinStack(int cap) {
	    tam_max=0;
    	this->tam_max=cap;
    }
    
    void push(int val) {
	    if (itens.size()==tam_max) {
	    	throw runtime_error("Stack Overflow");
	    }
    	if (itens.empty() || val < itens.top().second) {
    		itens.push(make_pair(val,val));
    	} else {
    		itens.push(make_pair(val,itens.top().second));
    	}
    }
    
    void pop() {
    	if (itens.empty()) {
    		throw runtime_error("Stack Underflow");
    	}
    	itens.pop();
    }

    int top() const {
	return itens.top().first;
    }

    int getMin() const {
	return itens.top().second;
    }
};

int main() {

    MinStack minStack(10);
	minStack.push(8);
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.getMin() << endl; // -2
    minStack.push(-10);
    minStack.push(-10);
    cout << minStack.getMin() << endl; // -10
    minStack.pop();
    cout << minStack.getMin() << endl; // -10
    minStack.pop();
    cout << minStack.getMin() << endl; // -2

    return 0;
}