class Solution {
public:

    void traverse(int i, vector<bool> &visited, bool& ans, vector<vector<int>> & mat){
        for(int j : mat[i]){
            if(visited[j]){
                ans = false;
                return;
            }
            visited[j] = true;
            traverse(j, visited, ans, mat);
            visited[j] = false;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mat(numCourses);
        for(vector<int> v : prerequisites){
            mat[v[0]].push_back(v[1]);
        }
        for(int i = 0; i < numCourses; i++){
            vector<bool> visited(numCourses, false);
            bool ans = true;
            visited[i] = true;
            traverse(i, visited, ans, mat);
            if(!ans) return false;
        }
        return true;
    }
};
