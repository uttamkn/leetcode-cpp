class LRUCache {
public:
  unordered_map<int, pair<int, list<int>::iterator>> mp;
  list<int> lst;
  int capacity;

  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (mp.find(key) == mp.end())
      return -1;

    lst.erase(mp[key].second);
    lst.push_front(key);
    mp[key].second = lst.begin();
    return mp[key].first;
  }

  void put(int key, int value) {
    if (mp.find(key) != mp.end()) {
      mp[key].first = value;
      lst.erase(mp[key].second);
      lst.push_front(key);
      mp[key].second = lst.begin();
      return;
    }

    if (lst.size() < capacity) {
      mp[key].first = value;
      lst.push_front(key);
      mp[key].second = lst.begin();
    } else {
      mp.erase(lst.back());
      lst.pop_back();
      mp[key].first = value;
      lst.push_front(key);
      mp[key].second = lst.begin();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
