class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // have a hashmap from int to int, representing how often an int occurs
        unordered_map<int, int> occ;
        // have a hashmap from int to int, representing if an int is currently top
        // if not, then this is equal to -1, if it is, then this is equal to index
        // in topK
        unordered_map<int, int> isTop;
        // have a vector to store the top K nums (constantly update every loop)
        vector<int> topK;
        // have a vector to store the top K occurences
        vector<int> topOcc;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            occ[nums[i]]++;  //log the occurences of this num
            if(isTop.count(num) == 0){ // num not seen before
                isTop[num] = -1;
            } 
            if(isTop[num] == -1){ // not one of the top k
               if(topK.size() < k){ // not enough have been filled yet
                isTop[num] = topK.size();
                topK.push_back(num);
                topOcc.push_back(occ[num]);
               } 
               else{
                if(occ[num] > topOcc[0]){
                    isTop[num] = 0;
                    isTop[topK[0]] = -1;
                    topK[0] = num;
                    topOcc[0] = occ[num];
                }
               }
            }
            if(isTop[num] != -1){ //this number is alraedy in the top k
                int count = 1;
                while(count < topK.size() && topOcc[count - 1] > topOcc[count]){
                   int tempOcc = topOcc[count - 1];
                   int tempNum = topK[count - 1];
                   topOcc[count - 1] = topOcc[count]; 
                   topK[count - 1] = topK[count];
                   topOcc[count] = tempOcc;
                   topK[count] = tempNum;
                }
            }
        }
        return topK;
    }
};




