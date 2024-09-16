
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int low = 0, high = n - 1;
    long mid;
    while (low <= high) {
      // math trick to avoid integer overflow while calculating mid
      mid = low + (high - low) / 2;
      if (guess(mid + 1) == 0)
        return mid + 1;
      else if (guess(mid + 1) == -1) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return 0;
  }
};
