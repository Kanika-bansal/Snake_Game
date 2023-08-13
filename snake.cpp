#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <vector>
using namespace std;
int w;
int h;
const int wid=20;
const int len=10;
int n=1;
vector<int> u;
vector<int> v;
void fruit()
{
    srand(time(NULL));
    w=rand()%(wid-2);
    h=rand()%(len-2);
};
void position(int a, int b,int c,int d)
{
    system("cls");
    int p;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            p=1;
            if (j==0||j==wid-1){cout<<"#"<<" ";}
            else if (i==0||i==len-1)
            {
                cout<<"#"<<" ";
            }
            else if (j==a && i==b)
            {
                cout<<"O"<<" ";
            }
            else if(j==c+1 && i==d+1)
            {
                cout<<"F"<<" ";
            }
            else if(u.size()!=0 && v.size()!=0)
            {
                for (int k=0;k<u.size();k++)
                {
                    if(j==u[k] && i==v[k])
                    {
                        cout<<"o";cout<<" ";
                        p=0;
                        break;
                    }
                }
                if (p==1)
                {
                    cout<<"  ";
                }
            }
            else
            {
                cout<<"  ";
            }
        }
        cout << endl;
    }
};
int main()
{
    srand(96);
    int a,b;
    char c,d;
    int x = rand() % (wid-2);
    int y= rand() % (len-2);
    a=x; b=y;
    fruit();
    position(x + 1, y + 1, w, h);
    while (n)
    {
        int p=1;
        clock_t t;
        t=clock();
        while(!_kbhit())
        {
            if((clock()-t)==500)
            {
                p=0;
                break;
            }
        }
        if(p)
        {
            c=getch();
        }
        switch (c)
        {
        case 'a':
            x--;
            break;
        case 'w':
            y--;
            break;
        case 'd':
            x++;
            break;
        case 's':
            y++;
            break;
        default:
            break;
        }
        if (x < 0)
        {
            x = x + wid-2;
        }
        if (y < 0)
        {
            y = y + len-2;
        }
        if (u.size()>0){
        for (int i=u.size()-1;i>0;i--)
        {
            u[i]=u[i-1];
        }
        u[0]=a%(wid-2)+1;
        for (int i=v.size()-1;i>0;i--)
        {
            v[i]=v[i-1];
        }
        v[0]=b%(len-2)+1;}
        position(x %(wid-2) + 1, y %(len-2) + 1, w, h);
        for(int k=0;k<u.size();k++)
        {
            if (x%(wid-2)+1==u[k] && y%(len-2)+1==v[k])
            {
                n=0;
            }
        }
        if (x %(wid-2)+ 1 == w + 1 && y % (len-2) + 1 == h + 1)
        {
            u.push_back(w+1);
            v.push_back(h+1);
            fruit();
        }
        a=x;
        b=y;
    }
}