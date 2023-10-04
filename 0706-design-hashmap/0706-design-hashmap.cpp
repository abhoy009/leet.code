class MyHashMap {
private:
    static const int SIZE = 10000;
    vector<list<pair<int, int>>> data; 
    
    list<pair<int, int>>::iterator findKey(int key, int index) {
        for (auto it = data[index].begin(); it != data[index].end(); ++it) {
            if (it->first == key) {
                return it; 
            }
        }
        return data[index].end(); 
    }

public:
    MyHashMap() : data(SIZE) {
    }

    void put(int key, int value) {
        int index = key % SIZE; 
        auto it = findKey(key, index);
        if (it == data[index].end()) {
            data[index].emplace_back(key, value);
        } else {
            it->second = value;
        }
    }

    int get(int key) {
        int index = key % SIZE; 
        auto it = findKey(key, index);
        return (it != data[index].end()) ? it->second : -1; 
    }

    void remove(int key) {
        int index = key % SIZE;
        auto it = findKey(key, index);
        if (it != data[index].end()) {
            data[index].erase(it);
        }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */