class CustomStack {
public:
    int n;
    vector<int> st;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(st.size()<n) st.push_back(x);
    }
    
    int pop() {
        int ele;
        if(st.size()!=0){
            ele=st.back();
            st.pop_back();
            return ele;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int temp = min(k, (int)st.size());
        for(int i=0; i<temp; i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */