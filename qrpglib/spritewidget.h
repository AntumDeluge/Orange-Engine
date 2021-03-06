#ifndef SPRITEWIDGET_H
#define SPRITEWIDGET_H 1

#ifdef WIN32
#include <windows.h>
#endif
#include <qgl.h>
#include <qtimer.h>
#include "sprite.h"

class SpriteWidget : public QGLWidget {
  Q_OBJECT
public:
  enum Mode {
    PLAY,
    PAUSE,
    FRAME
  };

  SpriteWidget(QWidget * parent=0);
  void setSprite(Sprite * s);
  Sprite * sprite;
public slots:
  void play();
  void pause();
  void stop();
  void setState(int);
  void setFrame(int);
  void updateDuration(int);
  void setDrawBoundingBox(bool);
signals:
  void setStateRange(int, int);
  void setFrameRange(int, int);
  void setFrameDuration(int);
  void setSelectedTile(int);
  void updateTime(int);
private:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  //void mousePressEvent(QMouseEvent * e);
  void updateSpinners();
  
  Mode mode;
  int time_since_start;
  int last_time;

  int state;
  int frame;
  int duration;
  int sw;
  int sh;

  bool drawBoundingBox;
  QTimer * timer;
  QTime spriteTime;
};


#endif
