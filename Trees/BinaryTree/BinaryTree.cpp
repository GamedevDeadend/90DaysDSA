#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* LChild;
    TreeNode* RChild;
};

TreeNode* create()
{
    int data;
    TreeNode* RootNode = nullptr;

    cout<<"Enter the data\n";
    cin>>data;

    if(data == -1)
        return RootNode;
    
    RootNode = new TreeNode;
    RootNode->data = data;

    cout<<"Enter Left Child Data For "<<data<<endl;
    RootNode->LChild = create();

    cout<<"Enter Right Child Data For "<<data<<endl;
    RootNode->RChild = create();

    return RootNode;
}

void InorderTraversal( TreeNode* RootNode)
{
    // cout<<endl;
    if(RootNode == nullptr)
        return;

    InorderTraversal(RootNode->LChild);
    cout<<RootNode->data<<"\t";
    InorderTraversal(RootNode->RChild);
}
void PreorderTraversal( TreeNode* RootNode)
{
    // cout<<endl;
    if(RootNode == nullptr)
        return;

    cout<<RootNode->data<<"\t";
    InorderTraversal(RootNode->LChild);
    InorderTraversal(RootNode->RChild);
}

void PostorderTraversal( TreeNode* RootNode)
{
    // cout<<endl;
    if(RootNode == nullptr)
        return;

    InorderTraversal(RootNode->LChild);
    InorderTraversal(RootNode->RChild);
    cout<<RootNode->data<<"\t";
}

int height(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    return max<int>(height(node->LChild), height(node->RChild))+1;
}

//total elements in binary tree
int size(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    return size(node->LChild)+size(node->RChild)+1;
}

int maximum(TreeNode* node)
{
    if(node == nullptr)
        return INT_MIN;

    return max<int>( node->data, ( max<int>( maximum(node->LChild), maximum(node->RChild) ) ) );
}

void PrintLvlOrder(TreeNode* Node)
{
    queue<int> q;
    q.push(Node->data);
    
    while(!q.empty())
    {
        int c = q.front();
        cout << c << endl;

    if(Node->LChild != nullptr)
        q.push(Node->LChild->data);

    if(Node->RChild != nullptr)
        q.push(Node->RChild->data);
    }


}

int main()
{
    TreeNode* node = create();
    cout<<"PreOrder"<<endl;
    PreorderTraversal(node);
    cout<<"PostOrder"<<endl;
    PostorderTraversal(node);
    cout<<"InOrder"<<endl;
    InorderTraversal(node);
   
}