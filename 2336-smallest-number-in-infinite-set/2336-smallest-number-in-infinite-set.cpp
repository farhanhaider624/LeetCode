class SmallestInfiniteSet {
public:
    set<int> st;
    int currEle;
    
    SmallestInfiniteSet() {
        currEle=1;
    }
    
    int popSmallest() {
        int result;
        if(!st.empty()){
            result=*st.begin();
            st.erase(result);
        }
        else{
            result=currEle;
            currEle++;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num>=currEle || st.find(num)!=st.end()) return;
        
        st.insert(num);
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */