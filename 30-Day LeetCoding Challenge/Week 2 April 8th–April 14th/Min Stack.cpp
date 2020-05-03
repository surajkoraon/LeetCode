class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v,u;
    int mins=INT_MAX;
    MinStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        mins=min(mins,x);
        u.push_back(mins);
    }
    
    void pop() {
        if(v.size()>0)
        {
            v.pop_back();
            u.pop_back();
        }
        if(v.size()>0)
            mins=u[u.size()-1];
        else
            mins=INT_MAX;
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return mins;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */