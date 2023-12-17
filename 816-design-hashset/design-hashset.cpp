class MyHashSet {
public:

    // method-1
    // vector<int> hash;
    // int size;
    // MyHashSet() {
    //     size = 1e6+10;
    //     hash.resize(size);
    // }
    // void add(int key) {
    //     hash[key] = 1;
    // }
    // void remove(int key) {
    //     hash[key] = 0;
    // }
    // bool contains(int key) {
    //     return hash[key];
    // }


    // method-2

    vector<list<int>> hash;
    int size;
    MyHashSet() {
        size = 1e6+10;
        hash.resize(size);
    }
    int hashFunction(int key) {
        return key%size;
    }
    list<int> :: iterator search(int key) {
        int i = hashFunction(key);
        return find(hash[i].begin(), hash[i].end(), key);
    }
    void add(int key) {
        if(contains(key)) return;
        int i = hashFunction(key);
        hash[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = hashFunction(key);
        hash[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hashFunction(key);
        if(search(key) != hash[i].end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */