class SmallestInfiniteSet {
public:
    // priority_queue<int> q;
    unordered_set<int> popList;
    priority_queue<int, vector<int>, greater<int> >q;
    SmallestInfiniteSet() {
        for(int i = 1; i < 1001; i++){
            q.push(i);
        }
    }
    
    int popSmallest() {
        int x = q.top();
        popList.insert(x);
        q.pop();
        return x;
    }
    
    void addBack(int num) {
        auto it = popList.find(num);
        if(it != popList.end()) {
            q.push(num);
            popList.erase(it);
        }
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */