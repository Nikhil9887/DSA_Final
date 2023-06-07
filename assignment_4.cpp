#include <bits/stdc++.h>
#define size 10
using namespace std;

class DataItem
{
public:
    string name;
    long long data;

    DataItem()
    {
        name = "";
        data = 0;
    }

    DataItem(string k, long long d)
    {
        name = k;
        data = d;
    }
};

class Hash
{
public:
    int hashIndex;
    // DataItem *hashArray[size];
    DataItem *hashArray = new DataItem[size];

    Hash()
    {
        hashIndex = 0;
    }

    int hashCode(string name)
    {
        return (name.length() % size);
    }

    int search(string name)
    {
        hashIndex = hashCode(name);
        while (hashArray[hashIndex].name != "")
        {
            if (hashArray[hashIndex].name == name)
            {
                return hashArray[hashIndex].data;
            }
            hashIndex++;
            hashIndex %= size;
        }
        return -1; // if we don't find the element with the given name
    }

    void insertWithoutReplacement(string name, long long data)
    {
        DataItem *item = new DataItem(name, data);

        hashIndex = hashCode(name);

        while (hashArray[hashIndex].name != "")
        {
            hashIndex++;
            hashIndex %= size;
        }

        hashArray[hashIndex].data = data;
        hashArray[hashIndex].name = name;
    }

    void insertWithReplacement(string name, long long data)
    {

        DataItem *item = new DataItem(name, data);
        hashIndex = hashCode(name);

        if (hashArray[hashIndex].name == "")
        {
            hashArray[hashIndex].name = name;
            hashArray[hashIndex].data = data;
            return;
        }

        if ((hashArray[hashIndex].name != "") && ((hashArray[hashIndex].name.length()) % size != hashIndex))
        {
            DataItem temp;
            temp.data = hashArray[hashIndex].data;
            temp.name = hashArray[hashIndex].name;

            hashArray[hashIndex].data = data;
            hashArray[hashIndex].name = name;

            data = temp.data;
            name = temp.name;

            hashIndex = hashCode(name);
        }

        while (hashArray[hashIndex].name != "")
        {
            hashIndex++;
            hashIndex %= size;
        }

        hashArray[hashIndex].data = data;
        hashArray[hashIndex].name = name;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (hashArray[i].name != "")
            {
                cout << "index :" << i << "\t";
                cout << "Name : " << hashArray[i].name << "\t";
                cout << "Data : " << hashArray[i].data << endl;
            }
        }
    }

    void deletion(string name)
    {
        hashIndex = hashCode(name);
        hashIndex = hashIndex % size;
        if (hashArray[hashIndex].name == name)
        {
            // delete hashArray[hashIndex];
            hashArray[hashIndex].data = 0;
            hashArray[hashIndex].name = "";
            cout << "Record deleted successfully" << endl;
            return;
        }
        int count = 0;
        while (hashArray[hashIndex].name != name && count < size)
        {
            count++;
            hashIndex++;
            hashIndex %= size;
        }

        if (count < size)
        {
            hashArray[hashIndex].data = 0;
            hashArray[hashIndex].name = "";
            cout << "Record deleted successfully" << endl;
            return;
        }

        else
        {
            cout << "Person not listed in directory" << endl;
        }
    }
};

int main()
{
    Hash abc;
    Hash pqr;
    while (true)
    {
        cout << "Start of the Program\n";
        cout << "1. Insert data item in directory " << endl;
        cout << "2. Search by name in directory" << endl;
        cout << "3. Delete a record in directory" << endl;
        cout << "4. Display complete directory" << endl;
        cout << "5. Exit" << endl;

        int res;
        cout << "Enter your choice: ";
        cin >> res;

        if (res == 1)
        {
            string name;
            long long data;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Data : " << endl;
            cin >> data;
            cout << "Without Replacement : " << endl;
            abc.insertWithoutReplacement(name, data);
            cout << endl;
            cout << "With Replacement : " << endl;
            pqr.insertWithReplacement(name, data);
            cout << endl;
            cout << "Insert Operation Performed Successfully" << endl;
        }

        else if (res == 2)
        {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Without Replacement :" << endl;
            int x = abc.search(name);
            if (x == -1)
            {
                cout << "Data Item with given name is not present" << endl;
            }
            else
            {
                cout << "Data associated with the given name is " << x << endl;
            }

            cout << "With Replacement :" << endl;
            int y = pqr.search(name);

            if (y == -1)
            {
                cout << "Data Item with given name is not present" << endl;
            }
            else
            {
                cout << "Data associated with the given name is " << y << endl;
            }
        }

        else if (res == 3)
        {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Without Replacement :" << endl;
            abc.deletion(name);
            cout << "With Replacement :" << endl;
            pqr.deletion(name);
        }
        else if (res == 4)
        {
            cout<<"Without Replacement"<<endl;
            cout << "Displaying Data Items : " << endl;
            abc.display();
            cout<<endl;
            cout<<"With Replacement"<<endl;
            cout<<"Displaying Data Items : "<<endl;
            pqr.display();
        }
        else if (res == 5)
        {
            break;
        }

        else
        {
            continue;
        }
    }
    return 0;
}
