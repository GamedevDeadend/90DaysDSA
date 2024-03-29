//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) 
    {
        tree->left = insert(tree->left, val);
    } 
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;

    cout<<"Enter No. of Test Cases"<<endl;
    cin >> T;


    while (T--) {
        Node *root = NULL;

        int N;
        cout<<"Enter nodes of tree"<<endl;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cout<<"Enter Key Element"<<endl;
        cin >> s;

        cout << search(root, s);
        cout << endl;
    }
}

// } Driver Code Ends


// Function to search a node in BST.
bool search(Node* root, int x) 
{
    if(root == nullptr) return false;
    
    if(root->data == x) return true;
    
    if(x < root->data) return search(root->left,x);
    
    return search(root->right,x);
    // Your code here
}