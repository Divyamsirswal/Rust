#include <bits/stdc++.h>

using namespace std;

// Structure to represent a node in the tree
struct TreeNode
{
    string value;
    vector<pair<TreeNode *, int>> children; // (Child Node, Edge Weight)

    TreeNode(string val) : value(val) {}
};

// Function to build the tree from the given string
TreeNode *buildTree(const string &s)
{
    unordered_map<string, TreeNode *> nodes;

    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = i + 1; j <= s.length(); ++j)
        {
            if (j - i != 1)
            {
                string substring = s.substr(i, j - i);
                TreeNode *node = new TreeNode(substring);
                nodes[substring] = node;
            }
        }
    }

    for (auto &entry : nodes)
    {
        TreeNode *parent = entry.second;
        for (int i = 1; i < parent->value.length(); ++i)
        {
            string leftChild = parent->value.substr(0, i);
            string rightChild = parent->value.substr(i);
            parent->children.push_back({nodes[leftChild], 1});
            parent->children.push_back({nodes[rightChild], 2});
        }
    }

    return nodes[s];
}

// Function to find the shortest path between two nodes in the tree
int shortestPath(TreeNode* root, const string& u, const string& v) {
    unordered_map<TreeNode*, int> distance;
    queue<TreeNode*> bfsQueue;

    distance[root] = 0;
    bfsQueue.push(root);

    while (!bfsQueue.empty()) {
        TreeNode* current = bfsQueue.front();
        bfsQueue.pop();

        if (current->value == v) {
            return distance[current];
        }

        for (const auto& child : current->children) {
            if (distance.find(child.first) == distance.end()) {
                distance[child.first] = distance[current] + child.second;
                bfsQueue.push(child.first);
            }
        }
    }

    return -1;  // Return -1 if v is not found in the tree
}

// Function to process each test case
void processTestCase()
{
    int n, q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;

    TreeNode *root = buildTree(s);

    for (int i = 0; i < q; ++i)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        string u = s.substr(l1 - 1, r1 - l1 + 1);
        string v = s.substr(l2 - 1, r2 - l2 + 1);
        int x = shortestPath(root, u, v);
        cout << x << endl;
    }
}

// Main function
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        processTestCase();
    }

    return 0;
}
