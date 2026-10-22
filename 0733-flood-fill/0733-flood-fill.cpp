
class Solution {
    void dfs(vector<vector<int>>& image, int i, int j,
             int originalColor, int color) {

        if (i < 0 || i >= image.size() ||
            j < 0 || j >= image[0].size())
            return;

        if (image[i][j] != originalColor)
            return;

        image[i][j] = color;

        dfs(image, i - 1, j, originalColor, color);
        dfs(image, i + 1, j, originalColor, color);
        dfs(image, i, j - 1, originalColor, color);
        dfs(image, i, j + 1, originalColor, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        if (originalColor == color)
            return image;

        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};

