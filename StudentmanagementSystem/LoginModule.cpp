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
    return true;
}
void saveuser()
{
    ofstream ofs;
    ofs.open("admin.bin",ios::app|ios::binary);
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
    saveuser();
    return 0;
}
