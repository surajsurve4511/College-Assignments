#include <iostream> 
#include <graphics.h> 
using namespace std;
void display(int xc, int yc, int x, int y)
{ putpixel(xc+x,yc+y,GREEN); 
 putpixel(xc-x,yc+y,GREEN); 
 putpixel(xc+x,yc-y,GREEN); 
 putpixel(xc-x,yc-y,GREEN); 
 putpixel(xc+y,yc+x,GREEN); 
 putpixel(xc-y,yc+x,GREEN); 
 putpixel(xc+y,yc-x,GREEN); 
 putpixel(xc-y,yc-x,GREEN); 
}
void circle_algo(int x1, int y1, int r)
{ int d = 3 - 2 * r; int x = 0, y = r;
display(x1, y1, x, y); while (y >= x)
{  x++;
if (d > 0)
{ y--;
d = d + 4 * (x - y) + 10;	} else
{d = d + 4 * x + 6;	} display(x1, y1, x, y);
}
}

int main()
{ int gd = DETECT, gm; 
initgraph(&gd, &gm, "");
circle_algo(300, 300, 80); 
getch();
closegraph();
return 0; }
