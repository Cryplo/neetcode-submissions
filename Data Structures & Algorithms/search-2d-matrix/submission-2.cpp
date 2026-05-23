class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lp = 0;
        int rp = m * n - 1;
        while(rp >= lp){
            int mid = (lp + rp) / 2;
            if(matrix[mid / n][mid % n] > target) rp = mid - 1;
            else if(matrix[mid / n][mid % n] < target) lp = mid + 1;
            else return true;
        }
        return false;
    }
};
