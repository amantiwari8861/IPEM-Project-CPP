#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class user
{
    public:
    string uname;
    string pass;
};
bool isValid(string username,string password)
{
    user temp;
    ifstream ifobj;
    ifobj.open("admin.dat",ios::binary);

    while (ifobj.read(reinterpret_cast<char *>(&temp),sizeof(user)))
    {  
        cout<<"hello"; 
        cout<<temp.uname<<" hiii "<<temp.pass<<endl;
        if(ifobj.eof())
        {
            cout<<"reached endf  of file "<<endl;
            break;
        }
        if (temp.uname==username && temp.pass==password)
        {
            cout<<"Login succesfully!"<<endl;
            return true;
        }
           
    }
    cout<<"invalid username or password !"<<endl;
    ifobj.close();
    return false;
}
void saveuser()
{
    ofstream ofs;
    ofs.open("admin.dat",ios::app|ios::binary);
    user u1;
    cout<<"Enter Username :";
    getline(cin,u1.uname);
    cout<<"Enter Password :";
    char pass[8]={""};
    for (int i = 0; i < 8; i++)
    {
        pass[i]=getch();
        cout<<"*";
    }
    u1.pass=pass;   
    ofs.write(reinterpret_cast<char*>(&u1),sizeof(user));
    cout<<endl;
    ofs.close();
}

int main()
{
    // saveuser();
    // saveuser();
    // saveuser();
    // saveuser();
    isValid("nidhi","nidhijha");
    isValid("Aman","12345678");
    isValid("rajkiran","6464544");
    return 0;
}
