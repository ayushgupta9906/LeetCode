class Solution {
public:
int compareVersion(string version1, string version2) {
    istringstream s1(version1), s2(version2);

while(1) {
    int n1,n2;
    string tmp1, tmp2;
    if (!getline(s1, tmp1, '.')) n1 = 0; 
    else n1 = stoi(tmp1);
    if (!getline(s2,tmp2,'.')) n2=0;
    else n2 = stoi(tmp2);
    if (not s1 and not s2) return 0;
    if (n1<n2) return -1;
    if (n1>n2) return 1;
}
}
};