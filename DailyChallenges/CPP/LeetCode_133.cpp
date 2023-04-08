class Solution {
public:
    unordered_map<int, Node *> m;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        if (m[node->val] != nullptr) return m[node->val];
        Node * nn = new Node(node->val);
        m[nn->val] = nn;
        for (auto child: node->neighbors)
            nn->neighbors.push_back(cloneGraph(child));
        return nn; 
    }
};
