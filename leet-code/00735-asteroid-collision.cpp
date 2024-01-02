class Solution {
  public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> asteroidsAfterCollisions;

      for (const auto& asteroid: asteroids) {
        const bool isNonCollidingAsteroid = (
          asteroidsAfterCollisions.empty()
          || asteroidsAfterCollisions.top() < 0
          || asteroidsAfterCollisions.top() > 0 && asteroid > 0
        );

        if (isNonCollidingAsteroid) {
          asteroidsAfterCollisions.push(asteroid);
          continue;
        }

        int sizeOfPreviousAsteroid = asteroidsAfterCollisions.top();
        const int sizeOfCurrentAsteroid = abs(asteroid);

        while (sizeOfPreviousAsteroid <= sizeOfCurrentAsteroid) {
          if (sizeOfPreviousAsteroid == sizeOfCurrentAsteroid) {
            asteroidsAfterCollisions.pop();
            break;
          }

          asteroidsAfterCollisions.pop();

          if (
            asteroidsAfterCollisions.empty()
            || asteroidsAfterCollisions.top() < 0
          ) {
            asteroidsAfterCollisions.push(asteroid);
            break;
          }

          sizeOfPreviousAsteroid = asteroidsAfterCollisions.top();
        }
      }

      vector<int> remainingAsteroids;

      while (!asteroidsAfterCollisions.empty()) {
        const int asteroid = asteroidsAfterCollisions.top();
        remainingAsteroids.push_back(asteroid);

        asteroidsAfterCollisions.pop();
      }

      reverse(remainingAsteroids.begin(), remainingAsteroids.end());

      return remainingAsteroids;
    }
};
