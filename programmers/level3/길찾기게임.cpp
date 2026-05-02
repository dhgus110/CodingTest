#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node
{
    node(){}
    node(int _index, int _x, int _y)
    : index {_index}, x {_x} , y {_y},left{}, right{} {}

    int index;
    int x,y;
    node* left;
    node* right;
};

class BST
{
private:
    node *root {};
    int cnt {0};
    vector<int> tree;

    void _insert(node* n, int index ,int x, int y)
    {
        node* parent;   
        while(n)
        {
            parent = n;
            if (parent->x > x)
                n = n->left;
            else
                n = n->right;
        }

        if( parent->x > x)
            parent->left = new node(index,x,y);
        else 
            parent->right = new node(index,x,y);

        ++cnt;
    }

    void _preorderTraversal(node* n)
    {
        tree.emplace_back(n->index);
        if (n->left)_preorderTraversal(n->left);
        if (n->right)_preorderTraversal(n->right);
    }

    void _postorderTraversal(node* n)
    {
        if (n->left)_postorderTraversal(n->left);
        if (n->right)_postorderTraversal(n->right);
        tree.emplace_back(n->index);

    }
public:
    void insert(int index ,int x, int y)
    {
        if (!root){
            root = new node(index,x,y);
            ++cnt;
        }
        else
            this->_insert(root, index, x, y);
    }

    vector<int> preorderTraversal()
    {
        if (!root) return {};
        if(tree.capacity()  < cnt) tree.reserve(cnt);
        tree.clear();
        
        _preorderTraversal(root);

        return tree;
    }

    vector<int> postorderTraversal()
    {
        if (!root) return {};
        if(tree.capacity()  < cnt) tree.reserve(cnt);
        tree.clear();
        
        _postorderTraversal(root);

        return tree;
    }
};



vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for(int i = 0 ; i < nodeinfo.size() ; ++i)
        nodeinfo[i].emplace_back(i+1);

    sort(nodeinfo.begin(),nodeinfo.end(),[](const vector<int>& a, const vector<int>& b){
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] > b[1];});

    BST * bst = new BST();

    for(int i = 0 ; i < nodeinfo.size() ; ++i)
        bst->insert(nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1]);

    answer.push_back(bst->preorderTraversal());
    answer.push_back(bst->postorderTraversal());

    return answer;
}