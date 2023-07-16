#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

class Solution{
    public:
        vector<int>bottomView(TreeNode* root){
            vector<int>ans;
            if(root==NULL)return ans;
            map<int,int>map;
            queue<pair<TreeNode*,int>>q;
            q.push({root,0});
            while (!q.empty()){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                int line=it.second;
                //update the value of line each and every time 
                map[line]=node->val;
                if(node->left!=NULL){q.push({node->left,line-1});}
                if(node->right!=NULL){q.push({node->right,line+1});}
            }
            for(auto it:map){
                ans.push_back(it.second);
            }
            return ans;
            
        }
};