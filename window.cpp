#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;
const int INF=1<<29;
struct tac
{
public:
    int x,y,pr;
    tac(){}
    tac(int _x,int _y,int _pr)
    {
        x=_x;y=_y;pr=_pr;
    }
    bool operator < (const tac &o)const
    {
        if(o.x==x && o.y==y)return pr<o.pr;
        if(o.x==x)
            return y<o.y;
        else
            return x<o.x;
    }
};

set<tac> tacke;

struct window
{
    tac upl,dwr,upr,dwl;
    int pr;
    window(){}
    window(int x1,int y1,int x2,int y2,int _pr)
    {
        pr=_pr;
        upl=tac(min(x1,x2),min(y1,y2),pr);
        dwr=tac(max(x1,x2),max(y1,y2),pr);
        upr=tac(min(x1,x2),max(y1,y2),pr);
        dwl=tac(max(x1,x2),min(y1,y2),pr);
        tacke.insert(upl);
        tacke.insert(upr);
        tacke.insert(dwl);
        tacke.insert(dwr);
    }
    void unisti()
    {
        pr=INF;
        tacke.erase(upl);
        tacke.erase(upr);
        tacke.erase(dwl);
        tacke.erase(dwr);
    }
    void change(int _pr)
    {
        unisti();
        pr=_pr;
        upl.pr=pr;
        upr.pr=pr;
        dwl.pr=pr;
        dwr.pr=pr;
        tacke.insert(upl);
        tacke.insert(upr);
        tacke.insert(dwl);
        tacke.insert(dwr);
    }
    int pov()
    {
        return abs((dwl.x-upl.x)*(upr.y-upl.y));
    }
};

char s[5000];
window svi[200];

int sweepaj(int vr)
{
    int pov=0;

}

int main()
{
    int x1,y1,x2,y2,up=0,down=-1;
    char tmp,ozn;
	while(scanf(" %s",s)==1)
    {
        switch (s[0]){

        case 'w':
            sscanf(s+1,"(%c,%d,%d,%d,%d)",&ozn,&x1,&y1,&x2,&y2);
            svi[ozn]=window(x1,y1,x2,y2,up++);
            break;
        case 't':
            sscanf(s+1,"(%c)",&ozn);
            svi[ozn].change(up++);
            break;
        case 'd':
            sscanf(s+1,"(%c)",&ozn);
            svi[ozn].unisti();
            break;
        case 'b':
            sscanf(s+1,"(%c)",&ozn);
            svi[ozn].change(down--);
            break;
        case 's':
            sscanf(s+1,"(%c)",&ozn);
            printf("%.3lf\n",100.*(double)sweepaj(svi[ozn].pr)/svi[ozn].pov());
            break;
        }
    }
    return 0;
}
