#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    int total = count(root);

    cout << "The total amount of nodes in this BST: " << total << endl;

    int sumTotal = sum(root);
    
    cout << "The sum of the BST: " << sumTotal << endl;
	
    int heightTotal = height(root);

    cout << "The height of the tree is: " << heightTotal << endl;

    display(root);
    destroy(root);
    return 0;
}
