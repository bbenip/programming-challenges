class MyHashMap {
  private:
    const int size = 100;
    vector<vector<pair<int, int>>> values;

  public:
    MyHashMap() : values(size) {}

    void put(int key, int value) {
      const int hashKey = key % size;
      auto& valuesForHashKey = values[hashKey];

      for (auto& [existingKey, existingValue] : valuesForHashKey) {
        if (key == existingKey) {
          existingValue = value;
          return;
        }
      }

      valuesForHashKey.push_back({ key, value });
    }

    int get(int key) {
      const int hashKey = key % size;
      const auto& valuesForHashKey = values[hashKey];

      for (const auto& [existingKey, existingValue] : valuesForHashKey) {
        if (key == existingKey) {
          return existingValue;
        }
      }

      return -1;
    }

    void remove(int key) {
      const int hashKey = key % size;
      auto& valuesForHashKey = values[hashKey];

      for (int i = 0; i < valuesForHashKey.size(); ++i) {
        const int existingKey = valuesForHashKey[i].first;

        if (key == existingKey) {
          valuesForHashKey.erase(valuesForHashKey.begin() + i);
          return;
        }
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
