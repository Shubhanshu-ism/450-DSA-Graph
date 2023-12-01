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
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* copy = new Node(node->val);
        vector<Node*> vis(101,NULL);   //it is for keeping location of copied node
        dfs(copy,node,vis);
        return copy;
    }
    void dfs(Node* copy,Node* node, vector<Node*> & vis){
        vis[copy->val] = copy;
        for(auto it: node->neighbors){
            if(vis[it->val]==NULL){
                Node* copynode = new Node(it->val);
                (copy->neighbors).push_back(copynode);
                dfs(copynode,it,vis);
            }
            else{
                (copy->neighbors).push_back(vis[it->val]); //to get copied node as it was in vis array
            }
        }
    }
};
