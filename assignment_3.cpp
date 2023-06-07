// Insertion and inorder, preorder traversal without recursion
// and deletion 
// is done in this file

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    bool l_thread;
    bool r_thread;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        l_thread = true;
        r_thread = true;
    }
};

class TBST
{
public:
    Node *root;
    Node *head = new Node(999); // dummy node

    TBST()
    {

        root = NULL;
        cout << "Creation of Threaded Binary Search Tree" << endl;
        cout << "Enter number of nodes : " << endl;
        int n;
        cin >> n;
        cout << "Enter values of each node : " << endl;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            insert(a[i]);
        }
    }

    void insert(int key)
    {
        Node *newNode = new Node(key);
        if (root == NULL)
        {
            root = newNode;
            cout << key << " Added as root" << endl;
            head->left = root;
            head->right = head;
            head->l_thread = false;
            head->r_thread = false;

            // these two lines were not written so
            // code was getting terminated ig
            root->left = head;
            root->right = head;

            return;
        }

        Node *temp = root;
        Node *parent = head;
        while (temp != NULL)
        {
            if (key == temp->data)
            {
                return;
            }
            parent = temp;
            if (key < temp->data)
            {
                if (temp->l_thread == false)
                    temp = temp->left;
                else
                    break;
            }
            else
            {
                if (temp->r_thread == false)
                    temp = temp->right;
                else
                    break;
            }
        }
        if (key < temp->data)
        {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->l_thread = false;
            parent->left = newNode;
        }
        else
        {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->r_thread = false;
            parent->right = newNode;
        }
    }

    void inOrder(Node *head)
    {
        Node *temp = head->left; // temp is root now since head->left is root
        do
        {
            while (temp->l_thread != true)
            {
                temp = temp->left;
            }

            cout << temp->data << " ";

            while (temp->r_thread == true)
            {
                temp = temp->right;
                if (temp == head)
                {
                    return;
                }
                cout << temp->data << " ";
            }

            temp = temp->right;

        } while (temp != head);
    }

    void preOrder(Node *head)
    {
        Node *temp = head->left;

        do
        {
            while (temp->l_thread != true)
            {
                cout << temp->data << " ";
                temp = temp->left;
            }
            cout << temp->data << " ";

            while (temp->r_thread == true)
            {
                temp = temp->right;
                if (temp == head)
                {
                    return;
                }
            }
            temp = temp->right;
        } while (temp != head);
    }

    Node *leftMost(Node *temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        while (temp->left != NULL && temp->l_thread == false)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *inOrderPred(Node *temp)
    {
        return temp->left;
    }

    Node *inOrderSucc(Node *temp)
    {
        if (temp->r_thread == true)
        {
            return temp->right;
        }
        else
        {
            temp = temp->right;
            return leftMost(temp);
        }
    }

    void deletion(int key)
    {
        Node *temp = root;
        Node *parent = head;

        while (temp != head)
        {
            if (key == temp->data)
            {
                break;
            }

            parent = temp;

            if (key < temp->data)
            {
                if (temp->l_thread == false)
                {
                    temp = temp->left;
                }
                else
                {
                    break;
                }
            }

            else
            {
                if (temp->r_thread == false)
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }

            if (key != temp->data)
            {
                cout << key << " not found" << endl;
                return;
            }

            else if (temp->l_thread == true && temp->r_thread == true)
            {
                if (parent == head)
                {
                    root = NULL;
                }

                else if (temp == parent->left)
                {
                    parent->l_thread = true;
                    parent->left = temp->left;
                }

                else
                {
                    parent->r_thread = true;
                    parent->right = temp->right;
                }

                delete temp;
                cout << key << " successfully deleted" << endl;
                return;
            }

            else if ((temp->l_thread == true && temp->r_thread == false) || (temp->l_thread == false && temp->r_thread == true))
            {
                Node *child;

                if (temp->l_thread == false)
                {
                    child = temp->left;
                }
                else
                {
                    child = temp->right;
                }

                if (parent == head)
                {
                    root = child;
                }

                if (temp == parent->left)
                {
                    parent->left = child;
                }

                else
                {
                    parent->right = child;
                }

                Node *s = inOrderSucc(temp);
                Node *p = inOrderPred(temp);

                if (temp->l_thread == false)
                {
                    p->right = s;
                }
                else
                {
                    s->left = p;
                }

                delete temp;
                cout << key << " successfully deleted" << endl;
                return;
            }

            else
            {
                Node *s = inOrderSucc(temp);
                int t = s->data;
                deletion(s->data);
                temp->data = t;
            }
        }
    }
};

int main()
{
    TBST b;
    cout << b.head->data << endl;
    cout << b.head->left << endl;
    cout << b.head->right << endl;
    cout << b.head->l_thread << endl;
    cout << b.head->r_thread << endl;
    while (true)
    {
        cout << "Implementation of Threaded BST" << endl << endl;
        cout << "1. Traversal of Threaded BST" << endl;
        cout << "2. Delete a node from Threaded BST" << endl;
        cout << "3. Exit" << endl;
        int res;
        cout << "Enter your choice : ";
        cin >> res;
        if (res == 1)
        {
            cout << "Inorder :";
            b.inOrder(b.head);
            cout<<endl;
            cout << "Preorder :";
            b.preOrder(b.head);
            cout << endl;
        }
        else if (res == 2)
        {
            cout << "Before Deletion : " << endl;
            cout << "Inorder :";
            b.inOrder(b.head);
            cout<<endl;
            cout << "Preorder :";
            b.preOrder(b.head);
            cout << endl;
            int n;
            cout << "Enter a no. to delete from threaded BST : ";
            cin >> n;
            b.deletion(n);
            cout << "After Deletion : " << endl;
            cout << "Inorder :";
            b.inOrder(b.head);
            cout<<endl;
            cout << "Preorder :";
            b.preOrder(b.head);
            cout << endl;
        }
        else if (res == 3)
        {
            cout << "Terminating program" << endl;
            break;
        }
        else
            continue;
    }
    return 0;
}
