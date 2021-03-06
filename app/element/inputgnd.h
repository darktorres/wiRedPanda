#ifndef INPUTGND_H
#define INPUTGND_H

#include "graphicelement.h"

class InputGnd : public GraphicElement {
public:
  explicit InputGnd( QGraphicsItem *parent = nullptr );
  virtual ~InputGnd( ) override = default;

  /* GraphicElement interface */
public:
  virtual ElementType elementType( ) override {
    return( ElementType::GND );
  }
  virtual ElementGroup elementGroup( ) override {
    return( ElementGroup::STATICINPUT );
  }
  void updateLogic( );
};

#endif /* INPUTGND_H */
