///-------------------------------------------
// Author: Jacob Tovar
// Date: 9/28/17
// Assignment: 3 - Linked-Lists with Pointers
//--------------------------------------------
#include "shape.h"

Shape::Shape(int id)
{
    mid = id;
}

int Shape::get_id()
{
    return mid;
}

void Shape::get_translation(double &tx, double &ty, double &tz)
{
tx = mtx;
ty = mty;
tz = mtz;
}
void Shape::set_translation(double tx, double ty, double tz)
{
mtx = tx;
mty = ty;
mtz = tz;
}

void Shape::get_rotation(double &rx, double &ry, double &rz)
{
rx = mrx;
ry = mry;
rz = mrz;
}
void Shape::set_rotation(double rx, double ry, double rz)
{
mrx = rx;
mry = ry;
mrz = rz;
}

void Shape::get_scale(double &sx, double &sy, double &sz)
{
sx = msx;
sy = msy;
sz = msz;
}
void Shape::set_scale(double sx, double sy, double sz)
{
msx = sx;
msy = sy;
msz = sz;
}

void Shape::get_color(double &r, double &g, double &b)
{
r = mred;
g = mgreen;
b = mblue;
}
void Shape::set_color(double r, double g, double b)
{
mred = r;
mgreen = g;
mblue = b;
}

QString Shape::print()
{
//An id. A color. A set of translations in the x, y and z directions. A set of rotations about the x axis, y axis and z axis. A set of scale factors in the x, y and z directions.
/*    std::cout <<"ID: " <<mid << std::endl
             <<"Color: Red: " << mred << ", Green: " << mgreen << ", Blue: " << mblue << std::endl
            <<"Translation: X: " << mtx << ", Y: " << mty << ", Z: " << mtz << std::endl
           <<"Rotations X: " << mrx << ", Y: " << mry << ", Z: " <<mrz << std::endl
          <<"Scale X: " <<msx << ", Y: " << msy << ", Z: " << msz << std::endl;
*/
}
