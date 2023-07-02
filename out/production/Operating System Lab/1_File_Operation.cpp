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
        //string prefix = "E:\\1. Academic\\3-2 Semester\\Operating System\\";
        //name = prefix + name; 
        ofstream newFile(name.c_str());
        cout << "File successfully created";
        newFile << "Hello World";
        newFile.close();
    }
    else if (operation == "Rename")
    {
        string oldname, newname;
        getline(cin, oldname);
        getline(cin, newname);
        int mark = rename(oldname.c_str(), newname.c_str());
        if (mark)
        {
            cout << "Error renaming file!";
        }
        else
            cout << "File successfully renamed";
    }
    else if (operation == "Delete")
    {
        string fileName;
        getline(cin, fileName);
        int mark = remove(fileName.c_str());
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
        ifstream sourceFile(from.c_str(), ios::binary);
        ofstream destinationFile(to.c_str(), ios::binary);
        string line;
        if (sourceFile and destinationFile)
        {
            while (getline(sourceFile, line))
            {
                destinationFile << line << "\n";
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
        ifstream sourceFile(from.c_str(), ios::binary);
        ofstream destinationFile(to.c_str(), ios::binary);
        string line;
        if (sourceFile and destinationFile)
        {
            while (getline(sourceFile, line))
            {
                destinationFile << line << "\n";
            }
            sourceFile.close(); //... Otherwise, can't delete
            cout << "File successfully moved";
            remove(from.c_str());
        }
        else
            cout << "Couldn't move file!";
    }
    else
        cout << "Invalid operation!";
}

/*//... Input Output:

...............Input:
Create
E:\\1. Academic\\3-2 Semester\\Operating System\\x.txt

..............Output:
File successfully created

...............Input:
Rename
E:\\1. Academic\\3-2 Semester\\Operating System\\x.txt
E:\\1. Academic\\3-2 Semester\\Operating System\\z.txt

..............Output:
File successfully renamed

...............Input:
Delete
E:\\1. Academic\\3-2 Semester\\Operating System\\z.txt

..............Output:
File successfully deleted

...............Input:
Copy
F:\\C++ Codes\\Operating System Lab\\x.txt
F:\\C++ Codes\\x.txt

..............Output:
File successfully deleted

...............Input:
Move
E:\\1. Academic\\3-2 Semester\\Operating System\\x.txt
F:\\C++ Codes\\x.txt

..............Output:
File successfully moved
*/
