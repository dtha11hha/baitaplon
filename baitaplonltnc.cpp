#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>

#define rong 25
#define dai  30

using namespace std;

//hàm xóa con trỏ
void xoacontro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle

(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

//Hàm dịch chuyển con trỏ
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle

(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput ,Cursor_an_Pos);
}

// Hàm xóa màn hình.
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

//hàm giới thiệu game !!!
void gioithieugame()
{
    xoacontro();
    char c;
    ifstream filein ;
    filein.open ("gioithieugame.txt");

    while (!filein.eof())
    {
        filein.get(c);
        Sleep(5);
        textcolor(10);
        cout<<c;
        if (kbhit())
        {
            char key=_getch();
            if (key=='G' || key =='g')
            break;
        }
    }

    filein.close();


}

struct toado {int y, x;};

struct vatpham
{
    toado td;
    char vp;
};

struct hinhdang{char a[3][3];};

struct Dan
{
    toado td;
    int sl;
    char d;

};
struct car
{
    toado td;
    hinhdang hd;
    Dan dan;
    int diem;
    int mang;
};
struct vatcan
{
    toado td;
    hinhdang hd;
};

//ĐỊNH NGHĨA

void dinhnghia(car &xe,vatcan &vc,vatcan &vc2 ,vatcan &vc3,vatpham &Vatpham)
{
    xe.td.x=3*rong/2+1;
    xe.td.y=dai-1;
    xe.diem=0;
    xe.mang=1;

    //Định nghĩa hình dạng xe người chơi
    xe.hd.a[0][0]=xe.hd.a[2][0]=xe.hd.a[0][2]=xe.hd.a[2][2]='o';
    xe.hd.a[0][1]='^';
    xe.hd.a[1][1]='x';
    xe.hd.a[1][0]=xe.hd.a[1][2]='|';
    xe.hd.a[2][1]='_';


    //Định nghĩa hình dạng vật cản 1

     vc.td.x=rand()%(rong-6)+rong+5;
     vc.td.y=rand()%5+2;

    vc.hd.a[0][0]=vc.hd.a[2][0]=vc.hd.a[0][2]=vc.hd.a[2][2]=char(254);
    vc.hd.a[0][1]=char(239);
    vc.hd.a[1][1]='x';
    vc.hd.a[1][0]=vc.hd.a[1][2]='|';
    vc.hd.a[2][1]='Y';

    //Định nghĩa hình dạng vật cản 2

     vc2.td.x=rong+3;
     vc2.td.y=rand()%5+2;

    vc2.hd.a[0][0]=vc2.hd.a[2][0]=vc2.hd.a[0][2]=vc2.hd.a[2][2]=char(254);
    vc2.hd.a[0][1]=char(239);
    vc2.hd.a[1][1]='x';
    vc2.hd.a[1][0]=vc2.hd.a[1][2]='|';
    vc2.hd.a[2][1]='Y';

     //Định nghĩa hình dạng vật cản 3

     vc3.td.x=2*rong-2;
     vc3.td.y=rand()%5+2;

    vc3.hd.a[0][0]=vc3.hd.a[2][0]=vc3.hd.a[0][2]=vc3.hd.a[2][2]=char(254);
    vc3.hd.a[0][1]=char(239);
    vc3.hd.a[1][1]='x';
    vc3.hd.a[1][0]=vc3.hd.a[1][2]='|';
    vc3.hd.a[2][1]='Y';

    //Định nghĩa hình dạng vật phẩm
        Vatpham.td.x=rand()%(rong-4)+2+rong;
        Vatpham.td.y=rand()%(dai/2+1)+dai/2;
        Vatpham.vp=char(254);

    //Định nghĩa hình dạng đạn
        xe.dan.d=char(254);
        xe.dan.sl=0;
}

//Hàm hiển thị
void hienthi(car xe,vatcan vc,vatcan vc2,vatcan vc3,vatpham Vatpham)
{
    int x,y,bestscore=0,n=0,luudiem[1000];

        int i;

        clrscr();

        //Hiển thị điểm
        textcolor(13);
        gotoxy(rong-17,10);printf("Score : %d",xe.diem);

        //Hiển thị mạng sống
        textcolor(13);
        gotoxy(rong-17,12);printf("Mang : %d",xe.mang);

        //Hiển thị số viên đạn
        textcolor(13);
        gotoxy(rong-17,14);printf("Dan : %d",xe.dan.sl);
        xoacontro();


        //hiển thị đường đua
        textcolor(110);
        for (i=1;i<=dai;i++)
            {
                gotoxy(rong,i);
                putchar(219);
            }
        for (i=1;i<=dai;i++)
            {
                gotoxy(rong*2,i);
                putchar(219);
            }


        //hiển thị xe người chơi
        textcolor(7);
        for (int kdong=-1;kdong<=1;kdong++)
            for (int kcot=-1;kcot<=1;kcot++)
                {
                       x=kcot+xe.td.x;
                       y=kdong+xe.td.y;
                       gotoxy(x,y);
                       putchar(xe.hd.a[kdong+1][kcot+1]);
                }

        //hiển thị vật cản 1
        textcolor(10);
        for (int kdong=-1;kdong<=1;kdong++)
            for (int kcot=-1;kcot<=1;kcot++)
                {
                       int x=kcot+vc.td.x;
                       int y=kdong+vc.td.y;
                       if (y > 0 && y < dai)
                        {
                            gotoxy(x, y);
                            putchar (vc.hd.a[kdong+1][kcot+1]);
                        }
                }



        //hiển thị vật cản 2
        textcolor(12);
        for (int kdong=-1;kdong<=1;kdong++)
            for (int kcot=-1;kcot<=1;kcot++)
                {
                        x=kcot+vc2.td.x;
                        y=kdong+vc2.td.y;
                       if (y < dai && abs(vc2.td.x-vc.td.x)>2)
                        {
                            gotoxy(x,y);
                            putchar (vc2.hd.a[kdong+1][kcot+1]);
                        }
                }

        //hiển thị vật cản 3
        textcolor(11);
        for (int kdong=-1;kdong<=1;kdong++)
            for (int kcot=-1;kcot<=1;kcot++)
                {
                        x=kcot+vc3.td.x;
                        y=kdong+vc3.td.y;
                       if (y < dai && abs(vc3.td.x-vc.td.x)>2 )
                        {
                            gotoxy(x,y);
                            putchar(vc3.hd.a[kdong+1][kcot+1]);
                        }
                }

        //hiển thị vật phẩm
        if ((xe.diem % 15 == 0 || xe.diem % 15 == 1 || xe.diem % 15 == 2 || xe.diem % 15 == 3 || xe.diem % 15 == 4) && xe.diem>14)
        {
            textcolor(13);
            gotoxy(Vatpham.td.x,Vatpham.td.y);
            putchar(Vatpham.vp);
        }


}
//Hàm điều khiển xe
   void dieukhien(car &xe)
{
    if (_kbhit())
        {
            char key=_getch();
            if ((key=='A' || key=='a' )&&xe.td.x>rong+2)xe.td.x--;else
            if ((key=='D' || key=='d' )&&xe.td.x<rong*2-2) xe.td.x++;
            if ((key=='W' || key=='w' )&&xe.td.y>2) xe.td.y--;else
            if ((key=='S' || key=='s' )&&xe.td.y<dai-1) xe.td.y++;
        }
}
//Ham Xu Ly Va Cham
int xulyvacham(car &xe, vatcan &vc,vatcan &vc2,vatcan &vc3,vatpham &Vatpham,int &timesleep)
{
    int bestscore=0;
    //Cho vật cản di chuyển xuống
    vc.td.y++;
    vc2.td.y++;
    vc3.td.y++;

    if (vc.td.y>dai+1)
    {
        xe.diem++;
        vc.td.x=rand()%(rong-6)+rong+5;
        vc.td.y=2;
        if (timesleep>30)
        {timesleep=timesleep-5;}
    }

    if (vc2.td.y>dai+1 )
    {
        xe.diem++;
        vc2.td.x=rong+3;
        vc2.td.y=rand()%5+2;

    }

    if (vc3.td.y>dai+1 )
    {
        xe.diem++;
        vc3.td.x=2*rong-2;
        vc3.td.y=rand()%5+2;
    }
     //xe bắn đạn
         while (xe.diem%20==0 && xe.diem>19)
         {
           xe.dan.sl++;
           break;
         }

    //Xử lý vật phẩm
        int DX3=abs(xe.td.x-Vatpham.td.x);
        int DY3=abs(xe.td.y-Vatpham.td.y);
        while (DX3<2 && DY3<2 && (xe.diem % 15 == 0 || xe.diem % 15 == 1 || xe.diem % 15 == 2 || xe.diem % 15 == 3 || xe.diem % 1 == 4))
            {xe.diem+=5;Vatpham.vp==' ';break;};

    //Xử lý số mạng sống

        if( xe.diem%30==0 && xe.diem>0)
        {
            xe.diem++;
            xe.mang+=3;
        }

//             //Hiển thị Best Score
//
//        ifstream fileinput("highscore.txt");
//
//        while (!fileinput)
//        {
//            fileinput>>xe.diem;
//        }
//        fileinput.close();
//
//
//        ofstream fileoutput("highscore.txt");
//
//        if (xe.diem>bestscore) {bestscore=xe.diem;}
//        fileoutput<<bestscore;
//
//        gotoxy(rong-17,16);textcolor(13);
//        printf("Best Score : %d " , bestscore);



    //Xử lý kết thúc game

    while (abs (xe.td.x - vc.td.x)<3 && xe.td.x<=2*rong-7)
    {
        xe.td.x++;

    }
     while (abs (xe.td.x - vc.td.x)<3 && xe.td.x>2*rong-7)
    {
        xe.td.x--;

    }
    while (abs (xe.td.x - vc2.td.x)<3 && xe.td.x<=2*rong-7)
    {
        xe.td.x--;

    }
    while (abs (xe.td.x - vc2.td.x)<3 && xe.td.x>2*rong-7)
    {
        xe.td.x--;

    }
    while (abs (xe.td.x - vc3.td.x)<3 && xe.td.x<=2*rong-7)
    {
        xe.td.x++;

    }
     while (abs (xe.td.x - vc3.td.x)<3 && xe.td.x>2*rong-7)
    {
        xe.td.x--;

    }
    int dX = abs (xe.td.x - vc.td.x);
	int dY = abs (xe.td.y - vc.td.y);
    int dX2 = abs (xe.td.x - vc2.td.x);
	int dY2 = abs (xe.td.y - vc2.td.y);
    int dX3 = abs (xe.td.x - vc3.td.x);
	int dY3 = abs (xe.td.y - vc3.td.y);

    if ((dX < 3 && dY < 3 ) || (dX2<3 && dY2<3 ) || (dX3<3 && dY3<3 ))  xe.mang--;
    if (xe.mang>=1) return 0 ; else return -1;

}
int main()
{
    car XE;
    vatcan VC,VC2,VC3;
    vatpham VP;
    int i,n,j,vacham=0 ,timesleep=100;
    srand(time(NULL));
    gioithieugame();
    dinhnghia(XE,VC,VC2,VC3,VP);

    while (true)
        {
                hienthi(XE,VC,VC2,VC3,VP);
                dieukhien(XE);
                vacham=xulyvacham(XE,VC,VC2,VC3,VP,timesleep);
                if (vacham==-1)
                {
                    gotoxy(rong*2+5,10);
                    textcolor(3);
                    printf(" GAME OVER ! ");
                    textcolor(7);
                    while (_getch() != 13);
                    break;
                }

                 Sleep(timesleep);

        }
return 0;
}
