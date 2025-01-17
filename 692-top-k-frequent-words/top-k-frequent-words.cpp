class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      map<string,int>freqMap;
    for(auto& word : words){
        freqMap[word]++;
    }
    auto comp = [&](string&a,string& b){
        return freqMap[a] > freqMap[b] || (freqMap[a] == freqMap[b] and a < b);
    };
    priority_queue<string,vector<string>,decltype(comp)>minHeap(comp);
    for(auto&x : freqMap){
        minHeap.push(x.first); 
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    vector<string>result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();}
    reverse(result.begin(),result.end());

    return result;
    }
};