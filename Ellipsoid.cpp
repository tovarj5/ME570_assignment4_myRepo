///-------------------------------------------
// Author: Jacob Tovar
// Date: 9/28/17
// Assignment: 3 - Linked-Lists with Pointers
//--------------------------------------------
#include "Ellipsoid.h"


Ellipsoid::Ellipsoid(int id) :Shape(id)
{

}
void Ellipsoid::get_size(double &rx, double &ry, double &rz)
{
    rx = mradx;
    ry = mrady;
    rz = mradz;
}
void Ellipsoid::set_size(double rx, double ry, double rz)
{
    mradx = rx;
    mrady = ry;
    mradz = rz;
}
QString Ellipsoid::print()
{
    QString output;
    output = "Cone ID: " + QString::number(mid) + "\n"
            + "Translation: " + QString::number(mtx) + " " + QString::number(mty) + " " + QString::number(mtz) + "\n"
            + "Rotations: " + QString::number(mrx) + " " + QString::number(mry) + " " + QString::number(mrz) + "\n"
            + "Scales: " + QString::number(msx) + " " + QString::number(msy) + " " + QString::number(msz) + "\n"
            + "Color R: " + QString::number(mred) + " " + QString::number(mgreen) + " " + QString::number(mblue) + "\n"
            + "RadiusX: " + QString::number(mradx) + " RadiusY: " + QString::number(mrady) + " RadiusZ: " + QString::number(mradz)
            + "\n";

//    std::cout << "Ellipsoid ID: " << mid << std::endl;
//    std::cout << "Translations: " << mtx << " " << mty << " " << mtz << std::endl;
//    std::cout << "Roatations: " << mrx << " " << mry << " " << mrz << std::endl;
//    std::cout << "Scales: " << msx << " " << msy << " " << msz << std::endl;
//    std::cout << "Color: Red: " << mred << " Green: " << mgreen << " Blue: " << mblue  << std::endl;
//    std::cout << "RadiusX: " << mradx << ", RadiusY: " << mrady << ", RadiusZ:" << mradz << std::endl <<std::endl;

    return output;
}
