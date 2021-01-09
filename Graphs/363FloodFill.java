class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }

        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    public void dfs(int[][] image, int i, int j, int newColor, int color) {
        if (i < 0 || i >= image.length || j < 0 || j >= image[i].length || image[i][j] != color) {
            return;
        }

        image[i][j] = newColor;

        dfs(image, i + 1, j, newColor, color);
        dfs(image, i - 1, j, newColor, color);
        dfs(image, i, j + 1, newColor, color);
        dfs(image, i, j - 1, newColor, color);
    }
}