class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;
    int curr;
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        int ele;
        if(!pq.empty()){
            ele=pq.top();
            pq.pop();
            s.erase(ele);
        }
        else{
            ele=curr;
            curr++;
        }
        return ele;
    }
    
    void addBack(int num) {
        if(num>=curr || s.find(num)!=s.end()) return;
        
        s.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */