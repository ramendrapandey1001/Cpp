#include <iostream>
#include <string>
#include <list>

using namespace std;

class User
{
public:
    string name;
    string username;
    string password;

    bool haslower = false;
    bool hasupper = false;
    bool hasdigit = false;
    bool hasSpecialChar = false;
    int index = -1;
    string normalChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    bool passwordStrength()
    {

        for (char pass : password)
        {
            if (islower(pass))
                haslower = true;
            if (isupper(pass))
                haslower = true;
            if (isdigit(pass))
                haslower = true;
            if (islower(pass))
                haslower = true;
            if (islower(pass))
                haslower = true;
        }

        index = password.find_first_not_of(normalChar);

        if (index != -1)
            hasSpecialChar = true;
        return haslower && hasupper && hasdigit && hasSpecialChar;
    }
};

list<User> userList;
bool logedin = false;
User currentUser;

void selection(int choice);
bool operator==(const User &lhs, const User &rhs)
{
    return lhs.username == rhs.username && lhs.password == rhs.password ;
}


int introduction()
{
    int choice;

    cout << "*-*-*-*-*-*-*-*-*-*-*-*-Security System-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "_______________________________________________________________" << endl
         << endl;
    cout << "|                       1.Register                            |" << endl;
    cout << "|                       2.Login                               |" << endl;
    cout << "|                       3.End program                         |" << endl;
    cout << "_______________________________________________________________" << endl
         << endl;

    cin >> choice;
    return choice;
}

void regist()
{
    User user;
    string message;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-Register-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "________________________________________________________" << endl
         << endl;
    cout << "Enter Your name" << endl;
    cin >> user.name;
    cout << "Enter Your username" << endl;
    cin >> user.username;
    cout << "Enter Your password" << endl;
    cin >> user.password;
    cout << "_________________________________________________________" << endl
         << endl;

    bool temp = user.passwordStrength();

    if (temp) // Guard Statement
        regist();

    message = "Registration Successfull";
    userList.push_back(user);
    cout << message << endl;
    selection(introduction());
}

string login()
{
    User user1;
    User user2;
    User user3;

    user1.name = "Ramendra";
    user1.password = "Qwert123@";
    user1.username = "ramendra";

    user2.name = "Aman";
    user2.password = "Asdfgh1234@";
    user2.username = "aman";

    user3.name = "Jagdish";
    user3.password = "Zv12@";
    user3.username = "jagdish";

    userList.push_back(user1);
    userList.push_back(user2);
    userList.push_back(user3);

    string message = "Wrong Username or Password";
    string username;
    string password;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-Login-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "_____________________________________________________" << endl
         << endl;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;

    for (User user : userList)
    {
        if (username == user.username && password == user.password)
        {
            message = "Congratulations You have loged in";
            logedin = true;
            currentUser = user;
        }
        else 
            continue;
    }

    return message;
}

string changePassword()
{
    string message;
    string newpass;
    string oldpass;
    string temp;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-Change Password-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "_____________________________________________________" << endl
         << endl;
    cout << "Enter old password" << endl;
    cin >> oldpass;
    cout << "Enter new password" << endl;
    cin >> temp;
    cout << "Confirm new password" << endl;
    cin >> newpass;

    if (temp != newpass)
    {
        cout << "New Password does not confirm " <<endl;
        changePassword();
    }

    for (User user : userList){
        if (user == currentUser)
            user.password = newpass;
        else
            continue;
            }
    message = "Password Changed Successfuly";
    return message;
}

void allUserDetails()
{
    int i = 1;
    cout << "_____________________________________________________" << endl
         << endl;
    for (User user : userList)
    {
        cout << i << "."
             << "Name:- " << user.name << endl;
        cout << " "
             << " User Name:- " << user.username << endl;
        cout << " "
             << " Password:- ";
        for (char ch : user.password)
            cout << "*";
        cout << endl;
        cout << "_____________________________________________________" << endl
             << endl;
        i++;
    }
}

void selection2()
{
    int choice;
    string message;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-Welcome!" << currentUser.name << " -*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "_______________________________________________________________" << endl
         << endl;
    cout << "|                       1.Change Password                     |" << endl;
    cout << "|                       2.All users details                   |" << endl;
    cout << "|                       3.Log Out                             |" << endl;
    cout << "_______________________________________________________________" << endl
         << endl;

    cin >> choice;
    switch (choice)
    {
    case 1:
        message = changePassword();
        break;
    case 2:
        allUserDetails();
        break;
    case 3:
        introduction();
        break;
    default:
        "Wrong entry try again";
        break;
    }

    cout << message;
    if (logedin)
        selection2();
}

void selection(int choice)
{
    string message;
    switch (choice)
    {
    case 1:
                  regist();
        break;
    case 2:
        message = login();
        break;
    case 3:
        message = "Thank You";
        break;
    default:
    {
        "Wrong entry try again";
        selection(choice);
    }
    break;
    }
    cout << message << endl;
    if (logedin)
        selection2();
}

int main()
{
   
    
    selection(introduction());
    return 0;
}