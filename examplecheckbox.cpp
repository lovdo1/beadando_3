#include "examplecheckbox.hpp"
#include "graphics.hpp"
#include <cmath>
using namespace genv;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    che=false;
}

void ExampleCheckBox::rajzol()
{
    gout <<color(255,255,255) << move_to(0,0) << box(500,500);
    for(int j=0;j<15;j++){
    for(int i=0;i<15;i++){
    gout << move_to(_x+i*_size_x, _y+j*_size_y) << color(0,0,0) << box(_size_x, _size_y)<< move_to(_x+i*_size_x+4, _y+j*_size_y+4) << color(200,200,200) << box(_size_x-8, _size_y-8);
    }

    }
    //gout << move_to(_x+_size_x, _y) << color(0,0,0) << box(_size_x, _size_y)<< move_to(_x+_size_x+4, _y+4) << color(200,200,200) << box(_size_x-8, _size_y-8);
    if (_checked)
    {
        gout << color(0,0,0);
        gout << move_to(_x+t*_size_x+4+_size_x, _y+g*_size_y+4+_size_y) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+t*_size_x+4+_size_x, _y+g*_size_y+4+_size_y) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+t*_size_x+_size_x-4+_size_x, _y+g*_size_y+4+_size_y) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+t*_size_x+_size_x-5+_size_x, _y+g*_size_y+4+_size_y) << line(-_size_x+8, _size_y-8);
    }
    if(che)
    {
        gout <<color(0,0,0) << move_to(t*_size_x+_size_x,g*_size_y+_size_y);
                for (double i = 0; i < 360 ; i+=0.1)
        {
            double alpha = i/180*pi;
            int yy = 12*sin(alpha);
            int xx = 12*cos(alpha);
            gout << move_to(xx+t*_size_x-2,yy+g*_size_y-2) << dot << move_to(t*_size_x+_size_x,g*_size_y+_size_y);
        }
    }
}

void ExampleCheckBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        a++;
        if(a%2)
        {
           _checked = true;

        }
        else
        {

            che = true;
        }

    }



}

bool ExampleCheckBox::is_checked()
{
    return _checked;
}
