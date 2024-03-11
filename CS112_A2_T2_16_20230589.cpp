// File: CS112_A2_T2_16_20230589
// Purpose: encrypt and decrypt a string the user inputs
// Author: Husam Zaid (Section: 16)
// Husam Zaid did cipcher 9
// Emails: 2006husamzaid@gmail.com
// IDs: 20230589 (Husam Zaid)

#include <iostream>
#include <string>
using namespace std;

void encrypt_9()
{
    string s, m = "", n1 = "", n2 = "", n3 = "";
    cout << "Please enter the message to cipher: ";
    getline(cin, s);
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] != ' ')
        {
            m = m + s[j];
        }
    }
  
    for (int i = 0; i < m.size(); i++)
    {
        if (i % 2 == 1)
        {
            n2 = n2 + m[i];
        }
        else if (i % 4 == 0)
        {
            n1 = n1 + m[i];
        }
        else
        {
            n3 = n3 + m[i];
        }
    }
    cout << "cipchered message: " << n1 << n2 << n3 << endl;
}

void decrypt_9()
{
    string s,m,h="",l[3]={""};
    long c[3]={0};
    cout<<"Please enter the message to decipher: ";
    
    getline(cin, s);
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] != ' ')
        {
            m = m + s[j];
        }
    }
    
    for (int y=0;y<4;y++)
    {
        if (m.size()%4==y)
        {
            for (int z=0;z<3;z++)
            {
                c[z]=m.size()/4;
                if (z==1)
                {
                    c[z] = c[z]*2;
                }
                if (y>0)
                {
                    c[z]=c[z]+1;
                    y--;
                }
            }
            for (long u=0;u<m.size();u++)
            {
                if (u<c[0])
                {
                    l[0]=l[0]+m[u];
                }
                else if (u<c[0]+c[1])
                {
                    l[1]=l[1]+m[u];
                }
                else
                {
                    l[2]=l[2]+m[u];
                }
            }
        }
    }
    
    for (int k=0;k<m.size();k++)
    {
        if ( k % 2 == 1 )
        {
            h=h+l[1][k/2];
        }
        else if ( k % 4 == 0)
        {
            h=h+l[0][k/4];
        }
        else
        {
            h=h+l[2][k/4];
        }
    }
    cout<<"Deciphered message: "<<h<<endl;
}


int main()
{
    int u=2;
    while (u==2)
    {
        cout<<"Ahlan ya user ya habibi."<<endl;
        cout<<"What do you like to do today?"<<endl;
        cout<<"1 - Cipcher a message"<<endl;
        cout<<"2 - Decipcher a message"<<endl;
        cout<<"3 - End"<<endl;
        cout<<">> ";
        int y;
        cin>>y;
        cin.ignore();
        if (y==1)
        {
            cout<<"Which Cipher do you like to choose?"<<endl;
            cout<<"1 - Rail-fence Cipher"<<endl;
            cout<<"2 - Return"<<endl;
            cout<<">> ";
            cin>>u;
            cin.ignore();
            if (u==1)
            {
                encrypt_9();
            }
        }
        else if (y==2)
        {
            cout<<"Which Cipher do you like to choose?"<<endl;
            cout<<"1 - Rail-fence Cipher"<<endl;
            cout<<"2 - Return"<<endl;
            cout<<">> ";
            cin>>u;
            cin.ignore();
            if (u==1)
            {
                decrypt_9();
            }
        }
        else break;
    }
    
    return 0;
}


