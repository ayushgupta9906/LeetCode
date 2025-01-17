class LFUCache {
private:
    unordered_map<int, int> key_val;
    unordered_map<int, int> key_use;
    unordered_map<int, deque<int>> uses;
    int min_uses;
    int capacity;

    void refreshCache() {
        while (!uses[min_uses].empty()) {
            int tmp_key = uses[min_uses].front();
            if (key_use[tmp_key] == min_uses) break;

            uses[min_uses].pop_front();

            if (uses[min_uses].empty()) {
                uses.erase(min_uses);
                while (!uses.count(min_uses)) ++min_uses;
            }
        }
    }

public:
    LFUCache(int capacity): min_uses(INT_MAX), capacity(capacity) {}
    
    int get(int key) {
        if (!key_val.count(key)) return -1;

        ++key_use[key];
        uses[key_use[key]].push_back(key);

        return key_val[key];
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if (key_val.size() == capacity && !key_val.count(key)) {
            refreshCache();

            int to_remove = uses[min_uses].front();
            uses[min_uses].pop_front();
            key_val.erase(to_remove);
            key_use.erase(to_remove);
        }

        ++key_use[key];
        uses[key_use[key]].push_back(key);

        min_uses = min(min_uses, key_use[key]);

        key_val[key] = value;
    }
};