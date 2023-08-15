//BOJ 1991 it's about tree orders
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> node;
int N;

int find_idx(char root)
{
    for(int i=0;i<N;i++)
    {
        if(root == node[i][0])
            return i;
    }

    return -1;
}

void preorder(int root) //root - left - right
{
    if(root == -1)
        return;
    cout << node[root][0];
    preorder(find_idx(node[root][1]));
    preorder(find_idx(node[root][2]));
}

void inorder(int root) //left - root - right
{
    if(root == -1)
        return;
    inorder(find_idx(node[root][1]));
    cout <<  node[root][0];
    inorder(find_idx(node[root][2]));
}

void postorder(int root) //left - right - root
{
    if(root == -1)
        return;
    postorder(find_idx(node[root][1]));
    postorder(find_idx(node[root][2]));
    cout << node[root][0];
}

int main()
{
    char tmp[3];
    int root;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        vector<char> v;
        v.push_back(tmp[0]);
        v.push_back(tmp[1]);
        v.push_back(tmp[2]);
        node.push_back(v);
        if(tmp[0] == 'A'){
            root = i;
        }
    }

    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);

    return 0;
}
