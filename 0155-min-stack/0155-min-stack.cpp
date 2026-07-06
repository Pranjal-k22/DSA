class MinStack {
public:
    stack<long long> st;
    long long min;
    long long x;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            min=value;
            st.push(value);
        }
        else{
            if(value>=min){
                st.push(value);
            }
            else{
                st.push((2LL*value) - min);
                min=value;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            
        }
        else{
            x=st.top();
            st.pop();
        }
        if(x<min){
            min=2*min-x;
        }
    }
    
    int top() {
        if(st.empty()){
            return 0;
        }
        x=st.top();
        if(min<x) return x;
        return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */