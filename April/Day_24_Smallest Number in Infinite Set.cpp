class SmallestInfiniteSet {
    set<int> st;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)st.insert(i);
    }
    
    int popSmallest() {
        auto it = *st.begin();
        int a = it;
        st.erase(it);
        return a;
    }
    
    void addBack(int num) {
        if(st.find(num)==st.end())st.insert(num);
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
 
 
