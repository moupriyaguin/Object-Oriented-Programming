#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h> 

using namespace std;

char matrix[31][31];

class Shape
{
    public:
    virtual void move(int x,int y) = 0 ;
};
 
class SimpleShape : public Shape
{
    public:
    int pos[2];
    int color;
    void move(int x,int y)
    {
       pos[0] += x;
       pos[1] += y;
    //    cout<<"I am move function"<<endl;
    }
    void set(int x,int y,int color)
    {
        pos[0]=x;
        pos[1]=y;
        this->color = color;
        // cout<<"I am set function"<<endl;
    }
    void getcolor()
    {
        switch(color)
        {
            case 1: system("Color 01");break;
            case 2: system("Color 02");break;
            case 3: system("Color 03");break;
            case 4: system("Color 04");break;
            case 5: system("Color 05");break;
            case 6: system("Color 06");break;
            case 7: system("Color 07");break;
            case 8: system("Color 08");break;
            case 9: system("Color 09");break;
            case 0: system("Color 00");break;
            case 10: system("Color 0A");break;
            case 11: system("Color 0B");break;
            case 12: system("Color 0C");break;
            case 13: system("Color 0D");break;
            case 14: system("Color 0E");break;
            case 15: system("Color 0F");break;
        }
        // cout<<"I am get color function"<<endl;
    }
};
class Box : virtual public SimpleShape
{
    public:
    virtual void draw()
    {
        for(int i=pos[0];i<=pos[0]+8;i++)
        {
            for(int j=pos[1];j<=pos[1]+8;j++)
            {
                if(i==pos[0]||i==pos[0]+8)
                {
                    matrix[i][j] = '*';
                }
                else
                {
                    if(j==pos[1]||j==pos[1]+8)
                    {
                        matrix[i][j] = '*';
                    }
                }
                
            }
        }
        // cout<<"I am box draw function"<<endl;
    }
};
 
class Tent : virtual public SimpleShape
{
    public:
    virtual void draw()
    {
        int count=pos[1];
        for(int i=pos[0];i<pos[0]+3;i++)
        {
            for(int j=pos[1];j<=count;j++)
            {
                matrix[i][j] = '*';
            }
            count = count+2;
        }
        // cout<<"I am tent draw function"<<endl;
    }
};
 
class ComplexShape : public Shape
{
    int pos[2];
    int color;
    public:
    void move(int x, int y)
    {
        pos[0] += x;
        pos[1] += y;
    }
    void setDirection(int x,int y,int color)
    {   
        pos[0] = x;
        pos[1] = y;
        this->color = color;
    }
    void getcolor()
    {
        switch(color)
        {
            case 1: system("Color 01");break;
            case 2: system("Color 02");break;
            case 3: system("Color 03");break;
            case 4: system("Color 04");break;
            case 5: system("Color 05");break;
            case 6: system("Color 06");break;
            case 7: system("Color 07");break;
            case 8: system("Color 08");break;
            case 9: system("Color 09");break;
            case 0: system("Color 00");break;
            case 10: system("Color 0A");break;
            case 11: system("Color 0B");break;
            case 12: system("Color 0C");break;
            case 13: system("Color 0D");break;
            case 14: system("Color 0E");break;
            case 15: system("Color 0F");break;
        }
    }
    void draw()
    {
        int count=1;
        int i;
        for( i=pos[0];i<pos[0]+4;i++)
        {
            for(int j=pos[1];j<pos[1]+count;j++)
            {
                matrix[i][j] = '*';
            }
            count++;
        }
        for(int k=i;k<=i+4;k++)
        {
            for(int j=pos[1];j<=pos[1]+4;j++)
            {
                if(k==i||k==i+4)
                {
                    matrix[k][j] = '*';
                }
                else
                {
                    if(j==pos[1]||j==pos[1]+4)
                    {
                        matrix[k][j] = '*';
                    }
                }
            }
        }
    }
};
 
void clear()
{
    system("pause");
    system("cls");
}

void display()
{
    for(int i=0;i<31;i++)
    {
        for(int j=0;j<31;j++)
        {
            cout << matrix[i][j]<<" ";
        }
        cout<<endl;          
    } 
    clear();
}
void reset()
{
    for(int i=0;i<31;i++)
    {
        for(int j=0;j<31;j++)
        {
            matrix[i][j] = ' ';
        }        
    }
}
int main()
{
    int dir;
    int x,y;
    int n,c1;
    SimpleShape s;
    ComplexShape c;
    Box b;
    Tent t;
    for(int i=0;i<31;i++)
    {
        for(int j=0;j<31;j++)
        {
            matrix[i][j] = ' ';
        }      
    }
    cout << "For Shape:\nEnter 1:Box\nEnter 2:Tent\nEnter 3:Complex shape"<<endl;
    cin >> n;
    cout << "For Colour:\nEnter 0:Over\nEnter 1:Blue\nEnter 2:Green\nEnter 3:Aqua Blue\nEnter 4:Red\nEnter 5:Purple\nEnter 6:Yellow\nEnter 7:White\nEnter 8:Grey\nEnter 9:Deep Blue\nEnter 10:Light Green\n" << endl;
    cin >> c1;
    cout<<"Enter the initial position of shape: ";
    cin>>x>>y;
    if(n==1)
    {
        b.set(x,y,c1);
        b.getcolor();
        b.draw();
    }
    else if(n==2)
    {
        t.set(x,y,c1);
        t.getcolor();
        t.draw();
    }
    else if(n==3)
    {
        c.setDirection(x,y,c1);
        c.getcolor();
        c.draw();
    }
    // switch(n)
    // {
    //     case1: b.set(x,y,c1);
    //            b.getcolor();
    //            b.draw();  
    //            break;
    //     case2: t.set(x,y,c1);
    //            t.getcolor();
    //            t.draw();  
    //            break;
    //     case3: c.set(x,y,c1);
    //            c.draw();  
    //            break;
    // }
    
    cout<<"Enter the direction of movement: "<<endl;
    cout<<"Enter 1 for North: "<<endl;
    cout<<"Enter 2 for South: "<<endl;
    cout<<"Enter 3 for East: "<<endl;
    cout<<"Enter 4 for West: "<<endl;
    cout<<"Enter 5 for South-East: "<<endl;
    cout<<"Enter 6 for South-West: "<<endl;
    cout<<"Enter 7 for North-East: "<<endl;
    cout<<"Enter 8 for North-West: "<<endl;
    cin>>dir;
    switch(n)
    {
          case 1: switch(dir)
                  {
                    case 1: 
                            b.move(-1,0); 
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(-1,0);
                                b.draw();
                            }
                            break;
                    case 2: 
                            b.move(1,0);
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(1,0);
                                b.draw();
                            }
                            break;
                    case 3: 
                            b.move(0,1);  
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(0,1);
                                b.draw();
                            }
                            break;
                    case 4: 
                            b.move(0,-1);  
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(0,-1);
                                b.draw();
                            }
                            break;
                    case 5: 
                            b.move(1,1);  
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(1,1);
                                b.draw();
                            }
                            break;
                    case 6: 
                            b.move(1,-1);  
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(1,-1);
                                b.draw();
                            }
                            break;
                    case 7: 
                            b.move(-1,1);  
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(-1,1);
                                b.draw();
                            }
                            break;
                    case 8: 
                            b.move(-1,-1);  
                            for(int i=0;i<20;i++)
                            {
                                display();
                                reset();
                                b.move(-1,-1);
                                b.draw();
                            }
                            break;
                  }
            break;

            case 2: switch(dir)
                    {
                        case 1: 
                                t.move(-1,0); 
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(-1,0);
                                    t.draw();
                                } 
                                break;
                        case 2: 
                                t.move(1,0);  
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(1,0);
                                    t.draw();
                                } 
                                break;
                        case 3: 
                                t.move(0,1);   
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(0,1);
                                    t.draw();
                                } 
                                break;
                        case 4: 
                                t.move(0,-1);  
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(0,-1);
                                    t.draw();
                                } 
                                break;
                        case 5: 
                                t.move(1,1);  
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(1,1);
                                    t.draw();
                                } 
                                break;
                        case 6: 
                                t.move(1,-1);  
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(1,-1);
                                    t.draw();
                                } 
                                break;
                        case 7: 
                                t.move(-1,1);  
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(-1,1);
                                    t.draw();
                                } 
                                break;
                        case 8: 
                                t.move(-1,-1);  
                                for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    t.move(-1,-1);
                                    t.draw();
                                } 
                                break;
                    }
         case 3: switch(dir)
                {
                    case 1: c.move(-1,0);
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(-1,0);
                                    c.draw();
                                }    
                            break;
                    case 2: c.move(1,0);  
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(1,0);
                                    c.draw();
                                } 
                            break;
                    case 3: c.move(0,1);  
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(0,1);
                                    c.draw();
                                } 
                            break;
                    case 4: c.move(0,-1);  
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(0,-1);
                                    c.draw();
                                } 
                            break;
                    case 5: c.move(1,1);  
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(1,1);
                                    c.draw();
                                } 
                            break;
                    case 6: c.move(1,-1);  
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(1,-1);
                                    c.draw();
                                } 
                            break;
                    case 7: c.move(-1,1);  
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(-1,1);
                                    c.draw();
                                } 
                            break;
                    case 8: c.move(-1,-1);  
                            for(int i=0;i<20;i++)
                                {
                                    display();
                                    reset();
                                    c.move(-1,-1);
                                    c.draw();
                                } 
                            break;
                }
    }
    return 0;
}