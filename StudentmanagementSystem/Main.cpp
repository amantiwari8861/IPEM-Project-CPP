#include "Loginmodule.cpp"
#include "addStudent.cpp"
#include "listStudent.cpp"
#include "editStu.cpp"
#include "delStu.cpp"

int main()
{
    int attempt = 3;
    bool status;
    do
    {
        char uname[50], pass[9];
        cout << "Enter Username :";
        cin.getline(uname, 50);
        cout << "Enter Password(8 digit) :";
        for (int i = 0; i < 8; i++)
        {
            pass[i] = getch();
            cout << "*";
        }
        status = isValid(uname, pass);
        attempt--;
    } while (attempt > 0 && status == false);

    if (!status)
    {
        exit(0);
    }
    cout << "Welcome Sir/Ma'am " << endl;
    cout << "1.Add Student !" << endl;
    cout << "2.view Student !" << endl;
    cout << "3.edit Student !" << endl;
    cout << "4.delete Student !" << endl;
    cout << "5.Exit !" << endl;

    do
    {
        int choice;
        cout << "Enter ur choice :";
        cin >> choice;
        switch (choice)
        {
        case  1 :
            addStudent();
            break;
        case  2 :
            listStudent();
            break;
        case  3 :
            editStu();
            break;
        case  4 :
            delStu();
            break;
        case  5 :
            exit(0);
            break;
        default:
            cout << "pls enter a valid choice !!";
            break;
        }
    } while (1);

    return 0;
}
//search
//sort acc to rollno,name
//grade
//marks acc.to sub name
//edit 
//delete