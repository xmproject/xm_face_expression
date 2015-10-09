#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include "xm_face.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    xm_normal_face_(":/new/prefix1/xm_face/normal.png"),
    xm_angry_face_(":/new/prefix1/xm_face/angry.png"),
    xm_confused_face_(":/new/prefix1/xm_face/confused.png"),
    xm_fire_face_(":/new/prefix1/xm_face/fire.png"),
    xm_sad_face_(":/new/prefix1/xm_face/sad.png"),
    xm_speak_face_(":/new/prefix1/xm_face/smile.png")
{
    //need to set the width and height of the widget firstly
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->showFullScreen() ;
    face_server = new QTcpServer() ;
    bool ok;
    ok = face_server->listen(QHostAddress::Any,8001) ;
    if (false == ok)
    {
        qDebug() << "Fail to listen the server";
        return;
    }
    getRobotFace(0) ;
    setRobotFace();
    connect(face_server,SIGNAL(newConnection()),this,SLOT(acceptConnection())) ;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::acceptConnection()
{
    qDebug()<<"in read" ;
    face_client = face_server->nextPendingConnection() ;
    connect(face_client,SIGNAL(readyRead()),this,SLOT(readClient())) ;
}

void Widget::readClient()
{
     QByteArray current_byte ;
     current_byte = face_client->readAll() ;
    int current_id = current_byte.toInt();
    qDebug()<<"current id = "<<current_id ;
    getRobotFace(current_id) ;
    setRobotFace();
}

void Widget::setRobotFace()
{
    QPalette current_palette ;
    QPixmap after_scaled_pixmap = QPixmap(current_face_image_).scaled(this->width(),this->height()) ;
        current_palette.setBrush(QPalette::Background,QBrush(QPixmap(after_scaled_pixmap)));
        this->setPalette(current_palette);
}

void Widget::getRobotFace(int id)
{
    switch (id) {
    case 0:
        current_face_image_ = xm_normal_face_ ;
        break;
    case 1:
        current_face_image_ = xm_confused_face_ ;
        break;

   case 2:
        current_face_image_ = xm_sad_face_ ;
        break ;

    case 3:
        current_face_image_ = xm_angry_face_ ;
         break ;

    case 4:
        current_face_image_ = xm_speak_face_ ;
         break ;

    case 5:
       current_face_image_ = xm_fire_face_ ;
         break ;

     default:
        this->close() ;
    }
}
