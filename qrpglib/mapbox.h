#ifndef MAPBOX_H
#define MAPBOX_H 1

#ifdef WIN32
#include <windows.h>
#endif
#define Q_QUICK1_EXPORT

#include <QtOpenGL>
#include <QDeclarativeView>
#include <QDeclarativeEngine>
#include <QtGui>
#include <QGraphicsSceneMouseEvent>
#include "map.h"
#include "globals.h"
#include "entity.h"

class MapScene;
class Map;

/* Note: To do this in QtQuick 2, I need to paint to a QQuickView, which isn't a widget.
   Fortunately it can render to a framebuffer, which can be set with
   QQuickCanvas::setRenderTarget()
*/

class MapBox : public QDeclarativeView {
  Q_OBJECT
  Q_PROPERTY(int width READ width)
  Q_PROPERTY(int height READ height)
  
  friend class MapScene;

public:
  MapBox(QWidget * parent=0);
  MapScene * mapScene;

public slots:
  void setX(int);
  void setY(int);
  void move(int, int);
  int getX();
  int getY();
  void setLayer(int);
  void addLayer(int, int, bool, QString);
  void deleteLayer(int);
  void setMap(int);
  Map * getMap();
  bool hasMap();
  //void LoadMap(char *);
  void saveMap(char *);
  LayerView::LayerViewMode getDrawMode();
  void setCamera(EntityPointer);
  EntityPointer getCamera();
  void setDrawMode(LayerView::LayerViewMode);
  void setCurrentTile(int);
  void addWidget(QWidget *);
  EntityPointer entityAt(int x, int y);
  int edgeAt(EntityPointer entity, int x, int y);
  QList < EntityPointer > entitiesAt(int x, int y);
  Map::Layer * getCurrentLayer();
  
  void setEditMode();
  void setEntityMode();
  void setSelectMode();
  void setBrushMode();
  void setMode(int mode);
  int getMode();

signals:
  void setXRange(int, int);
  void setYRange(int, int);
  void setXScroll(int);
  void setYScroll(int);
  void setLayerRange(int, int);
  void modeChanged(int);
  void mousePos(int, int, int, int);  
  void resized(int, int);

private:
  void setTile(QMouseEvent * e);
  void setTile(QGraphicsSceneMouseEvent * e);
  void resizeEvent(QResizeEvent *event);

  /*
  bool viewportEvent(QEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  bool event(QEvent *event);
  bool eventFilter(QObject *, QEvent *);
  */

  Map * map;
  int xo, yo;
  int layer;
  int mouse_start_x, mouse_start_y;
  LayerView::LayerViewMode drawMode;
  int currentTile;
  int xrange, yrange;
  EntityPointer camera;
  EntityPointer dragEntity;
  int resizeDirection;
  int mapEditorMode;
  int dragMode;
};

#endif
