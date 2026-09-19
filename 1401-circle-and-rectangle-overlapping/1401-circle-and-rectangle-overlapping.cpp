class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        
        int closestX = max(x1, min(x, x2));
        int closestY = max(y1, min(y, y2));

        int dx = x - closestX;
        int dy = y - closestY;

        return dx * dx + dy * dy <= r * r;
    }
};