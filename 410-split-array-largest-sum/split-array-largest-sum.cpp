class Solution {
public:
    int canAllocate(vector<int>& arr, int pages){
        int noOfStd = 1;
        long long pagesStudent = 0; 
        for(int i = 0; i < arr.size(); i++){
            if(pagesStudent + arr[i] <= pages){
                pagesStudent += arr[i];
            }
            else{
                noOfStd += 1;
                pagesStudent = arr[i];
            }
        }
        return noOfStd;
    }

    int splitArray(vector<int>& arr, int k) {
        if(k > arr.size()) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            int students = canAllocate(arr, mid);
            if(students > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};