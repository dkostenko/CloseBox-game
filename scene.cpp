#include "scene.h"

Scene::Scene()
{
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    this->clear();

    qDebug() << "нажато в сцене";
//    switch(event->key())
//    {
//    case Qt::Key_Left:
//        this->addEllipse(QRectF(-100.0, -100.0, 50.0, 50.0));
//        break;
//    case Qt::Key_Up:
//        this->addEllipse(QRectF(-50.0, -50.0, 50.0, 50.0));
//        break;
//    case Qt::Key_Down:
//        this->addEllipse(QRectF(-0.0, -0.0, 50.0, 50.0));
//        break;
//    case Qt::Key_Right:
//        this->addEllipse(QRectF(-50.0, -50.0, 100.0, 100.0));
//        break;
//    }
}
