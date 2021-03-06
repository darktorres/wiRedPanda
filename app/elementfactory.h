#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include "graphicelement.h"

#include <deque>
#include <QObject>

class Editor;
class ElementFactory : public QObject {
  Q_OBJECT

  size_t _lastId;

public:
  static ElementFactory *instance;
  QMap< size_t, ItemWithId* > map;

  static ElementType textToType( QString text );
  static QString typeToText( ElementType type );
  static QString translatedName( ElementType type );
  static QPixmap getPixmap( ElementType type );
  static GraphicElement* buildElement( ElementType type, QGraphicsItem *parent = nullptr );
  static QNEConnection* buildConnection( QGraphicsItem *parent = nullptr );
  static ItemWithId* getItemById( size_t id );
  static bool contains( size_t id );
  static void updateItemId( ItemWithId *item, size_t newId );
  static void removeItem( ItemWithId *item );
  static void addItem( ItemWithId *item );

  size_t getLastId( ) const;
  size_t next_id( );
  void clear( );

private:
  ElementFactory( );
};

#endif /* ELEMENTFACTORY_H */
