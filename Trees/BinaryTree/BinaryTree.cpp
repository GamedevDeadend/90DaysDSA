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
        return -21371;

    return max<int>( node->data, ( max<int>( maximum(node->LChild), maximum(node->RChild) ) ) );
}

void PrintLvlOrder(TreeNode* RootNode)
{
    if(RootNode == NULL)  //Base Case
        return;

    queue<TreeNode*> q;

    q.push(RootNode);
    // q.push(nullptr); // Line end chr
    
    while(!q.empty())
    {
        TreeNode* c = q.front();
        cout << c->data <<" "<< endl;
        q.pop();

        // if(c == nullptr)
        // {
        //     if(q.empty())
        //         return;

        //     q.push(nullptr);
        //     cout<<endl;
        // }


    if(Node->LChild != nullptr)
        q.push(Node->LChild);

    if(Node->RChild != nullptr)
        q.push(Node->RChild);

    }
}

int main()
{
    TreeNode* node = create();
    // cout<<"PreOrder"<<endl;
    // PreorderTraversal(node);

    // cout<<"\nPostOrder"<<endl;
    // PostorderTraversal(node);

    // cout<<"\nInOrder"<<endl;
    // InorderTraversal(node);

    cout<<"\nLvl Order"<<endl;
    PrintLvlOrder(node);
   
}