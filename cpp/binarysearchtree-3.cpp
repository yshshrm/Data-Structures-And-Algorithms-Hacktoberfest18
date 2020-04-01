#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

TreeNode* createTree() {
    int x; cin >> x;
    if (x == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(x);
    // cout << "Enter left child of " << x << " ";
    root->left = createTree();
    // cout << "Enter right child of " << x << " ";
    root->right = createTree();
    return root;
}

void inorder(const TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelPrint(TreeNode* root) {
    if (root == NULL) return;
    TreeNode* const MARKER = NULL;

    queue<TreeNode*> q;
    q.push(root);
    q.push(MARKER);

    while (q.empty() == false) {
        TreeNode* cur = q.front(); q.pop();
        if (cur == MARKER) {
            // cur level is processed....all children of this level are processed
            // this signfies next level has ended
            cout << endl;
            if (q.empty() == false) q.push(MARKER);
            continue;
        }

        cout << cur->data << "(" << (cur->next ? cur->next->data : 0) << ") ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

void connectLevels(TreeNode* root) {
    TreeNode* leftMostNode = NULL;
    TreeNode* child = NULL;
    TreeNode* cur = root;

    while (cur) {
        leftMostNode = NULL;    // assumption
        child = NULL;
        while (cur) {
            if (cur->left) {
                if (leftMostNode == NULL) leftMostNode = cur->left;
                if (child == NULL) {
                    child = cur->left;
                }
                else {
                    child ->next = cur->left;
                    child = child->next;
                }
            }

            if (cur->right) {
                if (leftMostNode ==  NULL) leftMostNode = cur->right;
                if (child == NULL) {
                    child = cur->right;
                }
                else {
                    child->next = cur->right;
                    child = child->next;
                }
            }
            cur = cur->next;
        }
        cur = leftMostNode;
    }
}

void topView(TreeNode* root, set<int>& visited, int horizontalDistance) {
    if (root == NULL) {
        return;
    }
    bool shallIPrintRoot = false;
    if (visited.find(horizontalDistance) == visited.end()) {
        shallIPrintRoot = true;
        visited.insert(horizontalDistance);
    }
    topView(root->left, visited, horizontalDistance - 1);
    if (shallIPrintRoot) cout << root->data << " ";
    topView(root->right, visited, horizontalDistance + 1);
}

void topView(TreeNode* root) {
    set<int> visited;
    topView(root, visited, 0);
}

void bottomView(TreeNode* root, map<int, TreeNode*> &m, int hd) {
    if (root == NULL) return ;
    m[hd] = root;
    bottomView(root->left, m, hd - 1);
    bottomView(root->right, m, hd + 1);
}
void bottomView(TreeNode* root) {
    map<int, TreeNode*> m;
    bottomView(root, m, 0);
    // my map contains the bottom view in the sorted order
    // now I need to print the map

    // auto i = 0;

    for (map<int, TreeNode*>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->second->data << " ";
    }
}

void leftView(TreeNode* root, int curLevel, int& levelToPrint) {
    if (root == NULL) return;

    if (curLevel == levelToPrint) {
        cout << root->data;
        ++levelToPrint;
    }
    leftView(root->left, curLevel + 1, levelToPrint);
    leftView(root->right, curLevel + 1, levelToPrint);
}

void inorderIterative(TreeNode* root) {
    TreeNode* cur = root;
    stack<TreeNode*> s;
    s.push(cur);
    cur = cur->left;

    while (cur or s.empty() == false) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top(); s.pop();
        cout << cur->data << "";
        // cur = cur->right
        if (cur->right) {
            cur = cur->right;
        }
        else {
            cur = NULL;
        }
    }
}

TreeNode* arrToTree(int arr[], int be, int en) {
    if (be > en) { return NULL; /* no elements in the array*/ }

    int* idx = max_element(arr + be, arr + en + 1);
    int i = idx - arr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = arrToTree(arr, be, i - 1);
    root->right = arrToTree(arr, i + 1, en);
    return root;
}

TreeNode* findLcaBst(TreeNode* root, int a, int b){
    // TODO update it for both nodes to be present in the tree
    if (root == NULL) return NULL;
    if (a > root->data and b > root->data) return findLcaBst(root->right, a, b);
    if (a < root->data and b < root->data) return findLcaBst(root->left, a, b);
    return root;
}



void inputArr(int arr[100], int n){
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

int main() {
    TreeNode* root = createTree();
    // connectLevels(root);
    // levelPrint(root);
    // topView(root);
    // bottomView(root);

    // int levelToPrint = 0;
    // leftView(root, 0, levelToPrint);
   
    // inorder tree traversal using stack
    // inorderIterative(root); 

    // cartesian tree
    // int arr[100]; int n; cin >> n; inputArr(arr, n);
    // TreeNode* root = arrToTree(arr, 0, n - 1);
    // levelPrint(root);

    int a, b; cin >> a >> b;
    TreeNode* lca = findLcaBst(root, a, b);
    cout << lca << " " << (lca ? lca->data : 0) << endl;
}
