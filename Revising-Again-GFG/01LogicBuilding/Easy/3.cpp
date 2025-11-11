class Solution {
  public:
    int distance(int x1, int y1, int x2, int y2) {
        return round(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0));
    }
};