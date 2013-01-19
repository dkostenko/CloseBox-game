#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QtGui>

class Scene : public QGraphicsScene
{
public:
    Scene();

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
