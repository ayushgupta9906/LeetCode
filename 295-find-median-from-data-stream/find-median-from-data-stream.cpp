class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {

    }
    
 void addNum(int num) {
        if (arr.empty()) {
            arr.push_back(num);
        } 
        else {
            int index=-1;
            for(int i=0;i<arr.size();i++){
                if(num<=arr[i]){
                    index=i;
                    break;
                }
            }
            if(index==-1){
                arr.push_back(num);
            }
            else{
                arr.insert(arr.begin()+index,num);     //O(n)
            }
        }
    }
    double findMedian() {
        int n=arr.size();
        if(n%2==0){
            return (double(arr[n/2]+arr[n/2-1]))/2;
        }
        else{
            return double(arr[n/2]);
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */