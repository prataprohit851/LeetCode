class MyCalendar {
public:
    
    set<pair<int, int>> st;
    
    MyCalendar() {
        return;
    }
    
    bool book(int start, int end) {
        for(auto it = st.begin(); it != st.end(); it++){
            if(max(it->first, start) < min(it->second, end)) return false;
        }
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */