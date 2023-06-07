#include <bits/stdc++.h>
#define size 26
using namespace std;

class Node
{

public:
    string key;
    string value;
    Node *next;

    Node()
    {
        key = "";
        value = "";
        next = NULL;
    }

    Node(string k, string v)
    {
        key = k;
        value = v;
    }
};

class Dictionary
{
    Node **arr;

public:
    Dictionary()
    {
        arr = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
    }

    int hashCode(string s)
    {
        int res = 0;
        res = (int(s[0]) - 97) % 26;
        return res;
    }

    void insertElement(string key, string value)
    {
        int hashIndex = hashCode(key);
        Node *newNode = new Node;
        newNode->key = key;
        newNode->value = value;

        if (arr[hashIndex] == NULL)
        {
            arr[hashIndex] = newNode;
            cout << "Insertion Performed" << endl;
        }

        else
        {
            Node *temp = arr[hashIndex];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printDictionary()
    {
        for (int i = 0; i < size; i++)
        {
            // cout<<i<<endl;
            // cout<<arr[i]->key<<" "<<arr[i]->value<<" "<<arr[i]->next<<endl;

            if (arr[i] == NULL)
            {
                cout << i << "  __\t__" << endl;
            }
            else
            {
                Node *temp = arr[i];
                while (temp)
                {
                    cout << i << " " << temp->key << " " << temp->value << endl;
                    temp = temp->next;
                }
            }
        }
    }

    void searchElement(string key)
    {
        int hashIndex = hashCode(key);

        if (arr[hashIndex] != NULL)
        {
            if (arr[hashIndex]->key == key)
            {
                cout << "Element found" << endl;
                cout << "Key : " << arr[hashIndex]->key << endl;
                cout << "Value : " << arr[hashIndex]->value << endl;
            }
            else
            {
                Node *temp;
                temp = arr[hashIndex];
                bool flag = false;
                while (temp)
                {
                    if (temp->key == key)
                    {
                        flag = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (flag)
                {
                    cout << "Element found" << endl;
                    cout << "Key : " << temp->key << endl;
                    cout << "Value : " << temp->value << endl;
                }
                else
                {
                    cout << "Element not found" << endl;
                }
            }
        }
        else{
            cout<<"Element not found hehe"<<endl;
        }
    }

    void deleteElement(string key)
    {
        int hashIndex = hashCode(key);
        if (arr[hashIndex] != NULL)
        {
            Node *curr = arr[hashIndex];
            bool flag = false;

            if (arr[hashIndex]->key == key)
            {
                flag = true;
                arr[hashIndex] = curr->next;
                // arr[hashIndex] = NULL;
            }

            else
            {
                Node *par = NULL;
                while (curr)
                {
                    if (curr->key == key)
                    {
                        flag = true;
                        break;
                    }
                    par = curr;
                    curr = curr->next;
                }
                if (flag)
                {
                    par->next = curr->next;
                    delete curr;
                }
                else
                {
                    // do nothing
                }
            }

            if (flag)
            {
                cout << "Element was deleted successfully" << endl;
            }
            else
            {
                cout << "Element not present" << endl;
            }
        }
        else
        {
            cout << "Element not present hehe" << endl;
        }
    }
};

int main()
{

    Dictionary d;
    int choice;
    while (true)
    {

        cout << "\n--------Program MENU----------" << endl;
        cout << " 1.INSERT" << endl;
        cout << " 2.DISPLAY" << endl;
        cout << " 3.DELETE" << endl;
        cout << " 4.SEARCH" << endl;
        cout << " 0.EXIT" << endl;
        cout << "\n------------------------------" << endl;

        cout << "Enter The Choice from the Menu." << endl;

        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting the program" << endl;
            break;
        }

        else if (choice == 1)
        {
            int n;
            cout << "Enter number of keys to be inserted in dictionary" << endl;
            cin >> n;
            while (n--)
            {
                string key, value;
                cout << "Enter key" << endl;
                cin >> key;
                cout << "Enter value" << endl;
                cin >> value;
                d.insertElement(key, value);
            }
        }

        else if (choice == 2)
        {
            cout << "Displaying Dictionary" << endl;
            d.printDictionary();
        }

        else if (choice == 3)
        {
            string key;
            cout << "Enter key" << endl;
            cin >> key;
            d.deleteElement(key);
        }

        else if (choice == 4)
        {
            string key;
            cout << "Enter key" << endl;
            cin >> key;
            d.searchElement(key);
        }
    }
    return 0;
}