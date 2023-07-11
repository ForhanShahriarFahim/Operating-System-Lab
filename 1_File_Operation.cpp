#include <bits/stdc++.h>

using namespace std;

//... File Name Format: "F:\\C++ Codes\\Operating System Lab\\x.txt"

int main()
{
    string operation;
    cin >> operation;
    cin.ignore();
    if (operation == "Create")
    {
        string name;
        getline(cin, name);
        ofstream new_file(name.c_str());
        cout << "File successfully created";
        new_file << "Hello World";
        new_file.close();
    }
    else if (operation == "Rename")
    {
        string old_name, new_name;
        getline(cin, old_name);
        getline(cin, new_name);
        int mark = rename(old_name.c_str(), new_name.c_str());
        if (mark)
        {
            cout << "Error renaming file!";
        }
        else
            cout << "File successfully renamed";
    }
    else if (operation == "Delete")
    {
        string file_name;
        getline(cin, file_name);
        int mark = remove(file_name.c_str());
        if (mark)
        {
            cout << "Couldn't delete file!";
        }
        else
            cout << "File successfully deleted";
    }
    else if (operation == "Copy")
    {
        string from, to;
        getline(cin, from);
        getline(cin, to);
        ifstream source_file(from.c_str(), ios::binary);
        ofstream destination_file(to.c_str(), ios::binary);
        string line;
        if (source_file and destination_file)
        {
            while (getline(source_file, line))
            {
                destination_file << line << "\n";
            }
            cout << "File successfully copied";
        }
        else
            cout << "Couldn't copy file!";
    }
    else if (operation == "Move")
    {
        string from, to;
        getline(cin, from);
        getline(cin, to);
        ifstream source_file(from.c_str(), ios::binary);
        ofstream destination_file(to.c_str(), ios::binary);
        string line;
        if (source_file and destination_file)
        {
            while (getline(source_file, line))
            {
                destination_file << line << "\n";
            }
            source_file.close(); //... Otherwise, can't delete
            cout << "File successfully moved";
            remove(from.c_str());
        }
        else
            cout << "Couldn't move file!";
    }
    else
        cout << "Invalid operation!";
}

/*//... Sample Input-Output:
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
Create
F:\\C++ Codes\\Operating System Lab\\x.txt
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
File successfully created
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
Rename
F:\\C++ Codes\\Operating System Lab\\x.txt
F:\\C++ Codes\\Operating System Lab\\z.txt
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
File successfully renamed
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
Delete
F:\\C++ Codes\\Operating System Lab\\z.txt
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
File successfully deleted
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
Copy
F:\\C++ Codes\\Operating System Lab\\x.txt
F:\\C++ Codes\\x.txt
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
File successfully copied
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
Move
F:\\C++ Codes\\Operating System Lab\\x.txt
F:\\C++ Codes\\x.txt
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
File successfully moved

*/
//...