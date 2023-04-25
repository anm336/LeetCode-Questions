class SmallestInfiniteSet {
public:
    set<int> s1;
    SmallestInfiniteSet() {
        s1.clear();
        for(int i=1;i<=1000;i++) s1.insert(i);
    }
    
    int popSmallest() {
        int y = *s1.begin();
        s1.erase(s1.begin());
        return y;
    }
    
    void addBack(int num) {
        s1.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */