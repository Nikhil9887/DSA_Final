#include <iostream>
# define SPACE 10
using namespace std;

class TreeNode
{
public:
    string keyword;
    string meaning;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        keyword = "";
        meaning = "";
        left = NULL;
        right = NULL;
    }

    TreeNode(string v)
    {
        keyword = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;

    BST()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL)
            return true;
        else
            return false;
    }

    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Keyword inserted as root node" << endl;
        }

        else
        {
            TreeNode *temp = root;

            while (temp != NULL)
            {
                if (new_node->keyword == temp->keyword)
                {
                    cout << "Keyword already exists. Please enter another keyword" << endl;
                    return;
                    // duplicate entries not allowed
                }

                else if ((new_node->keyword < temp->keyword) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Keyword inserted to the left" << endl;
                    break;
                }

                else if (new_node->keyword < temp->keyword)
                {
                    temp = temp->left;
                }

                else if ((new_node->keyword > temp->keyword) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Keyword inserted to the right" << endl;
                    break;
                }

                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void printPreOrder(TreeNode *r)
    {
        if (r == NULL)
            return;

        cout << r->keyword << " ";
        printPreOrder(r->left);
        printPreOrder(r->right);
    }

    void printInOrder(TreeNode *r)
    {
        if (r == NULL)
            return;

        printInOrder(r->left);
        cout << r->keyword << " ";
        printInOrder(r->right);
    }

    void printPostOrder(TreeNode *r)
    {
        if (r == NULL)
            return;
        printPostOrder(r->left);
        printPostOrder(r->right);
        cout << r->keyword << " ";
    }

    TreeNode *iterativeSearch(string val)
    {
        if (root == NULL)
            return root;
        else
        {
            TreeNode *temp = root;

            while (temp != NULL)
            {
                if (temp->keyword == val)
                {
                    return temp;
                }

                else if (val < temp->keyword)
                {
                    temp = temp->left;
                }

                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode *minkeywordNode(TreeNode *node)
    {
        TreeNode *current = node;

        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *r, string v)
    {
        if (r == NULL)
        {
            return NULL;
        }

        else if (v < r->keyword)
        {
            r->left = deleteNode(r->left, v);
        }

        else if (v > r->keyword)
        {
            r->right = deleteNode(r->right, v);
        }

        else
        {
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = minkeywordNode(r->right);
                r->keyword = temp->keyword;
                r->meaning = temp->meaning;
                r->right = deleteNode(r->right, temp->keyword);
            }
        }
        return r;
    }

    void print2D(TreeNode *root, int space){
        if (root==NULL){
            return;
        }
        space += SPACE;
        print2D(root->right, space);
        cout<<endl;
        for (int i = SPACE; i < space; i++)
        {
            cout<<" ";
        }
        cout<<root->keyword<<"\n";
        print2D(root->left, space);
    }
};

int main()
{
    BST obj;
    int option;
    string val, mean;

    do
    {
        cout << "What operation do you want to perform?" << endl;
        cout << "Select option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print BST keywords" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Insert" << endl;
            cout << "Enter keyword to insert in BST : " << endl;
            cin >> val;
            cout << "Enter meaning of the keyword : " << endl;
            cin >> mean;
            new_node->keyword = val;
            new_node->meaning = mean;

            obj.insertNode(new_node);
            break;

        case 2:
            cout << "Search" << endl;
            cout << "Enter keyword to be searched in the BST : " << endl;
            cin >> val;
            new_node = obj.iterativeSearch(val);

            if (new_node != NULL)
            {
                cout << "keyword found" << endl;
                cout << "Keyword : " << new_node->keyword << " "
                     << "Meaning : " << new_node->meaning << endl;
            }

            else
                cout << "keyword not found" << endl;

            break;

        case 3:
            cout << "Delete" << endl;
            cout << "Enter keyword of the node to be deleted in the BST : ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "keyword Deleted" << endl;
            }
            else
            {
                cout << "keyword NOT found" << endl;
            }
            break;

        case 4:
            cout << "Print and Traverse" << endl;

            cout << "Pre-order Traversal : ";
            obj.printPreOrder(obj.root);

            cout << endl;

            cout << "In-order Traversal : ";
            obj.printInOrder(obj.root);

            cout << endl;

            cout << "Post-order Traversal : ";
            obj.printPostOrder(obj.root);

            cout << endl;

            obj.print2D(obj.root, 5);

            break;

        case 5:
            cout << "Clear Screen" << endl;
            system("cls");
            break;

        default:
            cout << "Enter proper option number " << endl;
            break;
        }
    } while (option != 0);

    return 0;
}