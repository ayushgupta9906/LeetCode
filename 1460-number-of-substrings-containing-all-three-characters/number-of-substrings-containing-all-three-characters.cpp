class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1;
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else if(s[i]=='c') c=i;
            int mid=min(a,min(b,c));
            count+=mid+1;
        }
        return count;
    }
};