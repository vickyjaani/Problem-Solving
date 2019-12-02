#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
{
    if (postLength == 0)
        return NULL;
    int rootData = postorder[postLength - 1];
    int rootIndex = 0;
    while (inorder[rootIndex] != rootData)
    {
        rootIndex++;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = getTreeFromPostorderAndInorder(postorder, rootIndex, inorder, rootIndex);
    root->right = getTreeFromPostorderAndInorder(postorder + rootIndex, postLength - rootIndex - 1, inorder + rootIndex + 1, inLength - rootIndex - 1);
    return root;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> post[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}
/* testcases
12
15 4 3 5 2 10 8 12 9 7 6 1
4 15 3 2 5 1 6 10 8 7 9 12


7
5 4 7 6 3 2 1
1 2 5 4 3 6 7

7
2 4 6 7 5 3 1
2 1 4 3 6 5 7
*/