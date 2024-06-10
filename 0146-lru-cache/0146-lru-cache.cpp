class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };
    node *head=new node(-1, -1);
    node *tail=new node(-1, -1);
    int cap;
    unordered_map<int, node*> mp;
    
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node *newNode){
        node* temp=head->next;
        head->next=newNode;
        newNode->next=temp;
        newNode->prev=head;
        temp->prev=newNode;
    }
    void deleteNode(node *delNode){
        node* prevNode=delNode->prev;
        node* nextNode=delNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* resnode=mp[key];
            int res=resnode->val;
            mp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* existNode=mp[key];
            mp.erase(key);
            deleteNode(existNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */