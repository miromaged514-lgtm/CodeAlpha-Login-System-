#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser()
{
    string username, password;
    string checkUser, checkPass;

    cout << "\nEnter Username: ";
    cin >> username;

    ifstream readFile("users.txt");

    while (readFile >> checkUser >> checkPass)
    {
        if (username == checkUser)
        {
            cout << "\nUsername Already Exists!\n";
            readFile.close();
            return;
        }
    }

    readFile.close();

    cout << "Enter Password: ";
    cin >> password;

    ofstream writeFile("users.txt", ios::app);

    writeFile << username << " " << password << endl;

    writeFile.close();

    cout << "\nRegistration Successful!\n";
}

void loginUser()
{
    string username, password;
    string fileUser, filePass;

    int attempts = 3;

    while (attempts > 0)
    {
        cout << "\nEnter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ifstream file("users.txt");

        bool found = false;

        while (file >> fileUser >> filePass)
        {
            if (username == fileUser &&
                password == filePass)
            {
                found = true;
                break;
            }
        }

        file.close();

        if (found)
        {
            cout << "\nWelcome " << username << "!\n";
            cout << "Login Successful!\n";
            return;
        }

        attempts--;

        cout << "\nInvalid Username or Password!\n";

        if (attempts > 0)
        {
            cout << "Remaining Attempts: "
                 << attempts << endl;
        }
    }

    cout << "\nAccess Denied!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Login System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "\nGood Bye!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
