#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QString>
#include <QPalette>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void acceptConnection() ;
    void readClient() ;

private:
    void setRobotFace() ;
    void getRobotFace(int id) ;

private:
    Ui::Widget *ui;

    QString xm_normal_face_ ;
    QString xm_confused_face_ ;
    QString xm_sad_face_ ;
    QString xm_angry_face_ ;
    QString xm_speak_face_ ;
    QString xm_fire_face_ ;
    QPixmap *xm_face_image_ ;
    QString current_face_image_ ;

   QTcpServer *face_server ;
   QTcpSocket *face_client ;
};

#endif // WIDGET_H
