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

    DataItem(string n, long long d)
    {
        name = n;
        data = d;
    }
};

class Hash
{
public:
    int hashIndex;

    DataItem **arr; // double pointer pointing to array of pointers (these pointers in
    // the array will be pointing to the dataitem objects)

    Hash()
    {
        arr = new DataItem *[size]; // arr is now pointing to the start of the array of
        // pointers which will be pointing to the dataitem objects

        hashIndex = 0;

        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
        
    }

    int hashCode(string name)
    {
        return (name.length() % size);
    }

    void insertWithoutReplacement(string n, long long d)
    {
        DataItem *newElement = new DataItem(n, d);

        hashIndex = hashCode(n);

        while (arr[hashIndex] != NULL)
        {
            hashIndex++;
            hashIndex % size;
        }

        arr[hashIndex] = newElement;
    }

    void insertWithReplacement(string n, long long d)
    {
        DataItem *newElement = new DataItem(n, d);

        DataItem *temp;

        hashIndex = hashCode(n);

        if (arr[hashIndex] == NULL)
        {
            arr[hashIndex] = newElement;
            return;
        }

        if (arr[hashIndex] != NULL && (arr[hashIndex]->name.length() % size) != hashIndex)
        {
            string temp_name = arr[hashIndex]->name;
            long long temp_data = arr[hashIndex]->data;
            temp = new DataItem(temp_name, temp_data);

            arr[hashIndex] = newElement;

            hashIndex = hashCode(temp_name);
        }

        while (arr[hashIndex] != NULL)
        {
            hashIndex++;
            hashIndex % size;
        }

        arr[hashIndex] = temp;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != NULL)
            {
                cout << "Index : " << i << endl;
                cout << "Name : " << arr[i]->name << endl;
                cout << "Data : " << arr[i]->data << endl;
            }
        }
    }

    int search(string n)
    {
        int count = 0;

        hashIndex = hashCode(n);

        while (arr[hashIndex] != NULL && count < size)
        {

            if (arr[hashIndex]->name == n)
            {
                cout << "Element found." << endl;
                cout << "Name : " << arr[hashIndex]->name << endl;
                cout << "Data : " << arr[hashIndex]->data << endl;
                return 1;
            }
            count++;
            hashIndex++;
            hashIndex % size;
        }

        return 0;
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

        if (res==1){
            string name;
            long long data;
            cout<<"Enter name : "<<endl;
            cin>>name;
            cout<<"Enter data : "<<endl;
            cin>>data;
            cout<<"Without replacement : "<<endl;
            abc.insertWithoutReplacement(name, data);
            cout<<endl;

            cout<<"With replacement : "<<endl;
            pqr.insertWithReplacement(name, data);

            cout<<endl;
            cout<<"Insertion performed"<<endl;
        }

        else if (res==2){
            string name;
            cout<<"Enter name : "<<endl;
            cin>>name;
            cout<<"Without replacement : "<<endl;
            int x = abc.search(name);
            if (x==0){
                cout<<"Data Item with given name is not present"<<endl;
            }

            cout<<"With replacement : "<<endl;
            int y = pqr.search(name);

            if (y==0){
                cout<<"Data Item with given name is not present"<<endl;
            }
        }

        // else if (res==3){
        //     string name;
        //     cout<<"Enter name : "<<endl;
        //     cin>>name;
        //     cout<<"Without replacement : "<<endl;
        // }

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
            cout<<"Please enter correct option number"<<endl;
            continue;
        }


    }

    return 0;
}