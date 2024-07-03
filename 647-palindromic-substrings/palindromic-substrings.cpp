class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size(), psCnt = 0;
        for(int right = 0; right < size; right++){
            psCnt += countPalin(s, right, right);
            if(right + 1 < size)
                psCnt += countPalin(s, right, right + 1);
        }
        return psCnt;
    }
private:
    int countPalin(string & s, int left, int right){
        int psCnt = 0, size = s.size();
        while(left > -1 &&  right < size && s[left] == s[right]){
            if(s[left--] == s[right++])psCnt++;
        }
        return psCnt;
    }    
};