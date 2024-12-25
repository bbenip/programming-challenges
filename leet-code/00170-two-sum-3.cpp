class TwoSum {
  public:
    unordered_map<int, int> numberAndFrequency;

    TwoSum() {}

    void add(int number) {
      numberAndFrequency[number] += 1;
    }

    bool find(int value) {
      for (const auto& [number, frequency] : numberAndFrequency) {
        if (value < 0 && number > 0 && value < INT_MIN + number) {
          return false;
        }

        if (value >= 0 && number < 0 && value > INT_MAX + number) {
          return false;
        }

        const int complement = value - number;

        if (number == complement) {
          if (frequency > 1) {
            return true;
          }
        } else if (numberAndFrequency.contains(complement)) {
          return true;
        }
      }

      return false;
    }
};
