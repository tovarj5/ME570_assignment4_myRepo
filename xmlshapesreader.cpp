#include "xmlshapesreader.h"
#include <QString>
//#include "linkedlist.h"
#include "shape.h"
#include "box.h"
#include "Cone.h"
#include "Ellipsoid.h"

//XmlShapesReader::XmlShapesReader(std::list <Shape*> *linkedlist):
//    mLinkedList{linkedlist}
//{
////    mLinkedList.push_back(linkedlist);
//}
QString XmlShapesReader::errorString() const
{
    return QObject::tr("%1\nLine %2, column %3")
            .arg(mReader.errorString())
            .arg(mReader.lineNumber())
            .arg(mReader.columnNumber());
}

bool XmlShapesReader::read(QIODevice *device)
{
    mReader.setDevice(device);

    if (mReader.readNextStartElement()) {
        if (mReader.name() == "shapes")
            read_shapes();
        else
            mReader.raiseError(QObject::tr("Not a Shapes file"));
    }
    return !mReader.error();
}

void XmlShapesReader::read_shapes()
{
    while(mReader.readNextStartElement())
    {
        if(mReader.name() == "shape")
            read_shape();
        else
            mReader.skipCurrentElement();
    }
}

void XmlShapesReader::read_shape()
{
    int id{0};
    Vector3 color;
    Vector3 translation;
    Vector3 rotation;
    Vector3 scale;

    Shape* shape{nullptr};

    while (mReader.readNextStartElement())
    {
        //Check for any type of listed properties in the xml file.
        if (mReader.name() == "id")
            read_id(id);
        else if(mReader.name() == "color")
            read_color(color);
        else if (mReader.name() == "translation")
            read_xyz(translation);
        else if (mReader.name() == "rotation")
            read_xyz(rotation);
        else if (mReader.name() == "scale")
            read_xyz(scale);
        else if (mReader.name() == "box" && shape==nullptr)
            read_box(id,shape);
        else if (mReader.name()=="cone" && shape==nullptr)
            read_cone(id,shape);
        else if (mReader.name()=="ellipsoid" && shape==nullptr)
            read_ellipsoid(id,shape);
        else
            mReader.skipCurrentElement();
    }
    //Set the aquired properties into the shape class, then add the shape to the linked-list.
    if(shape!=nullptr)
    {
        shape->set_color(color.mX,color.mY,color.mZ);
        shape->set_translation(translation.mX,translation.mY,translation.mZ);
        shape->set_rotation(rotation.mX,rotation.mY,rotation.mZ);
        shape->set_scale(scale.mX,scale.mY,scale.mZ);
        //mLinkedList->push_back(shape);
        mLinkedList.push_back(shape);
    }


}
//Read the id from the XML file.
void XmlShapesReader::read_id(int &id)
{
    if (mReader.name() == "id")
        id=mReader.readElementText().toInt();
}
void XmlShapesReader::read_color(Vector3 &color)
{

    while(mReader.readNextStartElement())
    {
        if (mReader.name() == "red")
        {
            color.mX = mReader.readElementText().toDouble();
        }
        else if(mReader.name() == "green")
        {
            color.mY = mReader.readElementText().toDouble();
        }
        else if(mReader.name() == "blue")
        {
            color.mZ = mReader.readElementText().toDouble();
        }
        else
            mReader.skipCurrentElement();
    }

}
void XmlShapesReader::read_xyz(Vector3 &vec)
{
    vec.mX=0;
    vec.mY=0;
    vec.mZ=0;

    while(mReader.readNextStartElement())
    {
        if(mReader.name() == "x")
        {
            vec.mX = mReader.readElementText().toDouble();
        }
        else if(mReader.name() == "y")
        {
            vec.mY = mReader.readElementText().toDouble();
        }
        else if(mReader.name() == "z")
        {
            vec.mZ = mReader.readElementText().toDouble();
        }
        else
            mReader.skipCurrentElement();
    }
}
void XmlShapesReader::read_box(int id,Shape *&shape)
{
    //Create new box with initialized properties, then fill in with values from the file.
    Box* box = new Box(id);
    double height{1};
    double width{1};
    double depth{1};

    while(mReader.readNextStartElement())
    {
        if(mReader.name() == "height")
        {
            height = mReader.readElementText().toDouble();
        }
        else if(mReader.name() == "width")
        {
            width = mReader.readElementText().toDouble();
        }
        else if(mReader.name() == "depth")
        {
            depth = mReader.readElementText().toDouble();
        }
        else
            mReader.skipCurrentElement();
    }

    box->set_size(height,width,depth);

    shape=box;
}

void XmlShapesReader::read_cone(int id, Shape *&shape)
{
    Cone *cone = new Cone(id);
    double height{0}, rx{0}, ry{0};

    //Read through file and get basic properties
    while (mReader.readNextStartElement())
    {
        if(mReader.name() == "height")
        {
            height = mReader.readElementText().toDouble();
        }
        else if (mReader.name() == "radiusX")
        {
            rx = mReader.readElementText().toDouble();
        }
        else if (mReader.name() == "radiusY")
        {
            ry = mReader.readElementText().toDouble();
        }
        else
            mReader.skipCurrentElement();

    }
    //Set properties of new cone
    cone->set_size(height,rx,ry);

    shape = cone;
}

void XmlShapesReader::read_ellipsoid(int id, Shape *&shape)
{
    Ellipsoid *ellipse = new Ellipsoid(id);
    double rx{0}, ry{0}, rz{0};
    Vector3 xyz_ellipsoid;
    mReader.readNextStartElement();

    while(mReader.readNextStartElement())//ERROR HERE I NEED TO GO DOWN ONE MORE LEVEL TO READ
    {

        if(mReader.name()=="x")
        {
            rx = mReader.readElementText().toDouble();
        }
        else if(mReader.name() =="y")
        {
            ry = mReader.readElementText().toDouble();
        }
        else if (mReader.name() == "z")
        {
            rz = mReader.readElementText().toDouble();
        }
        else
            mReader.skipCurrentElement();

    }
    //Set properties of the new Ellipsoid
    ellipse->set_size(rx,ry,rz);

    shape = ellipse;
}
