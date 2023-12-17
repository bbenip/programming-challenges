class MyHashSet {
  private:
    const int size = 100;
    vector<vector<int>> values;

  public:
    MyHashSet() : values(size) {}

    void add(int key) {
      const int hashKey = key % size;
      auto& valuesForHashKey = values[hashKey];

      if (contains(key)) {
        return;
      }

      valuesForHashKey.push_back(key);
    }

    void remove(int key) {
      const int hashKey = key % size;
      auto& valuesForHashKey = values[hashKey];

      for (int i = 0; i < valuesForHashKey.size(); ++i) {
        if (valuesForHashKey[i] == key) {
          valuesForHashKey.erase(valuesForHashKey.begin() + i);
          return;
        }
      }
    }

    bool contains(int key) {
      const int hashKey = key % size;
      auto& valuesForHashKey = values[hashKey];

      for (auto& value : valuesForHashKey) {
        if (value == key) {
          return true;
        }
      }

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
