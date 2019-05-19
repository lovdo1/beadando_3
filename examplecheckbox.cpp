#include "examplecheckbox.hpp"
#include "graphics.hpp"
#include <cmath>
#include <vector>
#include<iostream>
using namespace genv;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    che=false;


    for(int i=0;i<14;i++){
        for(int j=0;j<14;j++)
        {
            palya[i][j]=0;
            std::cout << palya[i][j];

        }
        std::cout<< std::endl;
}

}
void ExampleCheckBox::rajzol()
{


    for(int j=0;j<15;j++){
    for(int i=0;i<15;i++){
    if(palya[i][j]==0){


    gout << move_to(_x+i*_size_x, _y+j*_size_y) << color(200,200,200) << box(_size_x, _size_y)<< move_to(_x+i*_size_x+4, _y+j*_size_y+4) << color(255,255,255) << box(_size_x-8, _size_y-8);
    }



    if (_checked)
    {

        palya[i][j]=2;
        gout << color(0,0,0);
        gout << move_to(_x+t*_size_x+_size_x+4, _y+g*_size_y+_size_y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+t*_size_x+_size_x+4, _y+g*_size_y+_size_y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+t*_size_x+_size_x-4+_size_x, _y+g*_size_y+_size_y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+t*_size_x+_size_x-5+_size_x, _y+g*_size_y+_size_y+4) << line(-_size_x+8, _size_y-8);
    }

    if(che)
    {
        palya[i][j]=1;
        gout <<color(0,0,0) << move_to(t*_size_x+3*_size_x,g*_size_y+3*_size_y);
                for (double i = 0; i < 360 ; i+=0.1)
        {
            double alpha = i/180*pi;
            int yy = 12*sin(alpha);
            int xx = 12*cos(alpha);
            gout << move_to(xx+t*_size_x-2+2*_size_x,yy+g*_size_y-2+2*_size_y) << dot << move_to(t*_size_x+3*_size_x,g*_size_y+3*_size_y);
        }
    }
    }
    }
}

void ExampleCheckBox::handle(event ev)
{



    if (ev.type == ev_mouse && ev.button==btn_left) {
            if (ev.button==btn_left&& katt==false){


    q=ev.pos_x;
    w=ev.pos_y;

    katt=true;


    }
    else if(ev.button==btn_left&& katt==true){
        e=ev.pos_x;
        r=ev.pos_y;


        katt=false;

    }


        a++;
        if(a%2 && is_selected(q,w))
        {
           _checked = true;
           che=false;


        }
        else if(is_selected(e,r))
        {


            che = true;
            _checked=false;


        }

    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            std::cout << palya[i][j];
            if(palya[i][j]==palya[i+1][j] && palya[i][j]==palya[i+2][j] &&palya[i][j]==palya[i+3][j] &&palya[i][j]==palya[i+4][j] && palya[i][j]>0)
            {
                std::cout << "Nyert";
            }
            if(palya[i][j]==palya[i][j+1] && palya[i][j]==palya[i][j+2] &&palya[i][j]==palya[i][j+3] &&palya[i][j]==palya[i][j+4] && palya[i][j]>0){
                    std::cout << "Nyert";
        }
        }
        std::cout<< std::endl;
    }


}

bool ExampleCheckBox::is_checked()
{
    return _checked;
}
