import java.util.LinkedHashMap;
import java.util.Map;

class Solution {
  public int solution(int cacheSize, String[] cities) {
    if (cacheSize == 0) {
      return 5 * cities.length;
    }

    Map<String, Boolean> cache = new LinkedHashMap<>(cacheSize, 0.75f, true);

    int totalTime = 0;

    for (String city : cities) {
      city = city.toLowerCase();

      if (cache.containsKey(city)) {
        totalTime += 1;

        cache.get(city);
      } else {
        totalTime += 5;

        if (cache.size() == cacheSize) {
          String leastRecentlyUsed = cache.keySet().iterator().next();

          cache.remove(leastRecentlyUsed);
        }

        cache.put(city, true);
      }
    }

    return totalTime;
  }
}