#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstring>
#include <iomanip>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

string s[15];



void note(int j, int i, bool doi, bool diez)
{
    s[i][j] = '@';
    s[i][j-1] = '(';
    s[i][j+1] = ')';
    if(diez)
        s[i][j-2] = '#';
    if(i >= 6)
    {
        s[i-1][j+1] = '|';
        s[i-2][j+1] = '|';
        s[i-3][j+1] = '|';
    }
    else
    {
        s[i+1][j-1] = '|';
        s[i+2][j-1] = '|';
        s[i+3][j-1] = '|';
    }
}

void update(int p)
{
    p-=1;
    string n;
    bool ten = false;
    bool doi = false;
    cin>>n;
    if(n.size() == 2)
    {
        if(n[1] == '#')
            ten = true;
        else two = true;
    }
    else if(n.size() == 3)
    {
        ten = two = true;
    }
    char root = n[0];
    if(root == 'C' && !two)
        note(p,11,false,ten);
    else if(root == 'D')
        note(p,10,false,ten);
    else if(root == 'E')
        note(p,9,false,ten);
    else if(root == 'F')
        note(p,8,false,ten);
    else if(root == 'G')
        note(p,7,false,ten);
    else if(root == 'A')
        note(p,6,false,ten);
    else if(root == 'B')
        note(p,5,false,ten);
    else if(root == 'C')
        note(p,4,true,ten);
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    s[1] = "----|-\\---";
    s[2] = "    |  }  ";
    s[3] = "----|-/---";
    s[4] = "    |/   4";
    s[5] = "---/|-----";
    s[6] = "  / |    4";
    s[7] = "-{--|-\\---";
    s[8] = "  \\_|_/   ";
    s[9] = "----|\\----";
    s[10]= "    |_}   ";
    s[11]= "          ";
    int n;
    cin>>n;
    int pos = 10;
     for(int i= 1;i<=11;i++)
        for(int j = 1;j<5*(n+1);j++)
            if(i % 2 == 1 && i <=10)
                s[i] += '-';
            else s[i] += ' ';

    for(int i =1;i<=n;i++)
    {
        pos+=5;
        update(pos);
    }
    for(int i = 1; i<=11; i++)
    {
        cout<<s[i];
        if(i == 1 || i==9)
            cout<<"+";
        else if(i<10)
            cout<<"|";
        cout<<'\n';
    }
    return 0;
}

