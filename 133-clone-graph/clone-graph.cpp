/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> mp;
    void dfs(Node* node, Node* temp){
        if(node==NULL){
            return;
        }
        mp[node->val]=temp;
        // cout<<node->val<<" "<<temp->val<<" "<<temp->neighbors.empty()<<"\n";
        for(auto i :node->neighbors){
            if(mp.find(i->val)!=mp.end()){
                temp->neighbors.push_back(mp[i->val]);
            }
            else{
                Node* newn=new Node(i->val);
                temp->neighbors.push_back(newn);
                dfs(i,newn);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node* head=new Node(node->val);
        dfs(node,head);
        return head;
    }
};