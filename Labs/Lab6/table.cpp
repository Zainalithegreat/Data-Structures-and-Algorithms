#include "table.h"

int count(node *root) {
    if (!root) {
        return 0;
    }
    
 
    int leftCount = count(root->left);
    
 
    int rightCount = count(root->right);
    
    return 1 + leftCount + rightCount;
}
int sum(node * root){
	int count = 0;
	sum(root, count);
	return count;
}

void sum(node * root, int &count){
	if(!root){
		return;
	}
	sum(root->left, count);
	count += root->data;
	sum(root->right, count);
}
int height(node * root){
        if(!root){
                return 0;
        }else{
                int left = height(root->left);
                int right = height(root->right);

                return max(left, right) + 1;
        }
}

