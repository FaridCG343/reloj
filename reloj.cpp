#include <iostream>
#include <string>
#include <cmath>
#include<map>
using namespace std;
int gethora(string h)
{
    string temp = "";
    int cont = 0;
    for (char x : h)
    {
        if (cont == 0 || cont == 1)
        {
            temp += x;
        }
        cont++;
    }
    return stoi(temp);
}
int getmin(string h)
{
    string temp = "";
    int cont = 0;
    for (char x : h)
    {
        if (cont == 3 || cont == 4)
        {
            temp += x;
        }
        cont++;
    }
    return stoi(temp);
}
int palindromo(int hrs, int min, int m)
{
    int cont=0;
    string sh, sm;
    map<string,int> mapa;
    do
    {
        
        if (hrs < 10)
        {
            sh = "0" + to_string(hrs);
        }
        else
        {
            sh = to_string(hrs);
        }
        if (min < 10)
        {
            sm = "0" + to_string(min);
        }
        else
        {
            sm = to_string(min);
        }
        if(sh[0]==sm[1] && sh[1]==sm[0]){
            cont++;
            
        }
        mapa[sh+sm]=1;
        if (min+m>= 60)
        {
            hrs += floor((min + m) / 60);
            if (hrs >= 24)
            {
                hrs -= 24;
            }
            min+=m;
            min-=floor(min/60)*60;
        }
        else
        {
            min += m;
        }
        if (hrs < 10)
        {
            sh = "0" + to_string(hrs);
        }
        else
        {
            sh = to_string(hrs);
        }
        if (min < 10)
        {
            sm = "0" + to_string(min);
        }
        else
        {
            sm = to_string(min);
        }
    } while (mapa[sh+sm]!=1);
    
    return cont;
}
int main(int argc, char const *argv[])
{
    int tc, min, hrs, m, cont = 0;
    string hora;
    cin >> tc;
    while (tc--)
    {
        cin >> hora >> m;
        hrs = gethora(hora);
        min = getmin(hora);
        cout<<palindromo(hrs, min, m)<<endl;
    }

    return 0;
}
