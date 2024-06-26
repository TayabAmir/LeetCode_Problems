class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i=0;i<n;i++){
            for(int j=0,k=n-1;j<k;j++,k--)
                swap(image[i][j],image[i][k]);
            for(int j=0;j<n;j++)
                (image[i][j]==1) ? image[i][j] = 0 : image[i][j] = 1;
        }
        return image;
    }
};