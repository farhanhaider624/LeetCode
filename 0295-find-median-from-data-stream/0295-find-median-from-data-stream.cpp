#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() || num<leftMaxHeap.top()) leftMaxHeap.push(num);
        else rightMinHeap.push(num);
        
        if(abs((int)leftMaxHeap.size()-(int)rightMinHeap.size())>1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if(leftMaxHeap.size()<rightMinHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        double res;
        if(leftMaxHeap.size()==rightMinHeap.size()){
            return (leftMaxHeap.top()+rightMinHeap.top())/2.0;
        }
        return leftMaxHeap.top()/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */