///-------------------------------------------
// Author: Jacob Tovar
// Date: 9/28/17
// Assignment: 3 - Linked-Lists with Pointers
//--------------------------------------------
#include "Cone.h"

Cone::Cone(int id) : Shape(id)
{

}
void Cone::get_size(double &height, double &rx, double &ry)
{
    height = mheight;
    rx = mradx;
    ry = mrady;
}
void Cone::set_size(double height, double rx, double ry)
{
    mheight = height;
    mradx = rx;
    mrady = ry;
}
QString Cone::print()
{
    QString output;
    output = "Cone ID: " + QString::number(mid) + "\n"
            + "Translation: " + QString::number(mtx) + " " + QString::number(mty) + " " + QString::number(mtz) + "\n"
            + "Rotations: " + QString::number(mrx) + " " + QString::number(mry) + " " + QString::number(mrz) + "\n"
            + "Scales: " + QString::number(msx) + " " + QString::number(msy) + " " + QString::number(msz) + "\n"
            + "Color R: " + QString::number(mred) + " " + QString::number(mgreen) + " " + QString::number(mblue) + "\n"
            + "Height: " + QString::number(mheight) + " " + QString::number(mradx) + " " + QString::number(mrady) + "\n";

//    std::cout << "Cone ID: " << mid << std::endl;
//    std::cout << "Translations: " << mtx << " " << mty << " " << mtz << std::endl;
//    std::cout << "Roatations: " << mrx << " " << mry << " " << mrz << std::endl;
//    std::cout << "Scales: " << msx << " " << msy << " " << msz << std::endl;
//    std::cout << "Color: Red: " << mred << " Green: " << mgreen << " Blue: " << mblue  << std::endl;
//    std::cout << "Height: " << mheight << ", RadiusX: " << mradx << ", RadiusY: " << mrady << std::endl <<std::endl;

    return output;
}
