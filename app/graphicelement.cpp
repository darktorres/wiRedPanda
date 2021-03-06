#include "graphicelement.h"
#include "nodes/qneconnection.h"
#include "scene.h"
#include "thememanager.h"

#include <iostream>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <stdexcept>

//! carmesim -- warning: non-POD static
static QMap< QString, QPixmap > loadedPixmaps;


GraphicElement::GraphicElement( int minInputSz, int maxInputSz, int minOutputSz, int maxOutputSz,
                                QGraphicsItem *parent ) : QGraphicsObject( parent ), label( new QGraphicsTextItem(
                                                                                              this ) )
{
  pixmap = nullptr;
  COMMENT( "Setting flags of elements. ", 4 );
  setFlag( QGraphicsItem::ItemIsMovable );
  setFlag( QGraphicsItem::ItemIsSelectable );
/*  setFlag(QGraphicsItem::ItemSendsScenePositionChanges); */
  setFlag( QGraphicsItem::ItemSendsGeometryChanges );

  COMMENT( "Setting attributes. ", 4 );
  label->hide( );
  QFont font( "SansSerif" );
  font.setBold( true );
  label->setFont( font );
  label->setPos( 64, 30 );
  label->setParentItem( this );
  label->setDefaultTextColor( Qt::black );
  m_bottomPosition = 64;
  m_topPosition = 0;
  m_minInputSz = minInputSz;
  m_minOutputSz = minOutputSz;
  m_maxInputSz = maxInputSz;
  m_maxOutputSz = maxOutputSz;
/*
 *  m_visited = false;
 *  m_beingVisited = false;
 */
  m_rotatable = true;
  m_hasColors = false;
  m_hasTrigger = false;
  m_hasFrequency = false;
  m_hasLabel = false;
  m_disabled = false;
  m_outputsOnTop = true;

  COMMENT( "Including input and output ports.", 4 );
  for( int i = 0; i < minInputSz; i++ ) {
    addInputPort( );
  }
  for( int i = 0; i < minOutputSz; i++ ) {
    addOutputPort( );
  }
  updateTheme( );
}

QPixmap GraphicElement::getPixmap( ) const {
  if( pixmap ) {
    return( *pixmap );
  }
  else {
    return( QPixmap( ) );
  }
}


void GraphicElement::disable( ) {
  m_disabled = true;
}

void GraphicElement::enable( ) {
  m_disabled = false;
}

void GraphicElement::setPixmap( const QString &pixmapName, QRect size ) {
  QString pixmapPath = pixmapName;
  if( ThemeManager::globalMngr ) {
    if( pixmapPath.contains( "memory" ) ) {
      switch( ThemeManager::globalMngr->theme( ) ) {
          case Theme::Panda_Light:
          pixmapPath.replace( "memory", "memory/light" );
          break;
          case Theme::Panda_Dark:
          pixmapPath.replace( "memory", "memory/dark" );
          break;
      }
    }
  }
  if( pixmapPath != currentPixmapName ) {
    if( !loadedPixmaps.contains( pixmapPath ) ) {
        //! carmesim-TODO: use QPixmap::loadFromData() here
        QPixmap pixmap;
        if (!pixmap.load(pixmapPath))
        {
            throw std::runtime_error( ERRORMSG("Couldn't load pixmap.") );
        }
        loadedPixmaps[ pixmapPath ] = pixmap.copy( size );
    }
    pixmap = &loadedPixmaps[ pixmapPath ];
    setTransformOriginPoint( pixmap->rect( ).center( ) );
    update( boundingRect( ) );
  }
  currentPixmapName = pixmapName;
}

QVector< QNEOutputPort* > GraphicElement::outputs( ) const {
  return( m_outputs );
}

const QNEInputPort* GraphicElement::input( int pos ) const {
  return( m_inputs.at( pos ) );
}

const QNEOutputPort* GraphicElement::output( int pos ) const {
  return( m_outputs.at( pos ) );
}

QNEInputPort* GraphicElement::input( int pos ) {
  return( m_inputs.at( pos ) );
}

QNEOutputPort* GraphicElement::output( int pos ) {
  return( m_outputs.at( pos ) );
}

void GraphicElement::setOutputs( const QVector< QNEOutputPort* > &outputs ) {
  m_outputs = outputs;
}

void GraphicElement::save( QDataStream &ds ) const {
  COMMENT( "Saving element. Type: " << objectName( ).toStdString( ), 4 );
  ds << pos( );
  ds << rotation( );

  /* <Version1.2> */
  ds << getLabel( );
  /* <\Version1.2> */

  /* <Version1.3> */
  ds << m_minInputSz;
  ds << m_maxInputSz;
  ds << m_minOutputSz;
  ds << m_maxOutputSz;
  /* <\Version1.3> */
  /* <Version1.9> */
  ds << m_trigger;
  /* <\Version1.9> */
  ds << static_cast< quint64 >( m_inputs.size( ) );
  for( QNEPort *port: m_inputs ) {
    ds << reinterpret_cast< quint64 >( port );
    ds << port->portName( );
    ds << port->portFlags( );
  }
  ds << static_cast< quint64 >( m_outputs.size( ) );
  for( QNEPort *port: m_outputs ) {
    ds << reinterpret_cast< quint64 >( port );
    ds << port->portName( );
    ds << port->portFlags( );
  }
  COMMENT( "Finished saving element.", 4 );
}

void GraphicElement::load( QDataStream &ds, QMap< quint64, QNEPort* > &portMap, double version ) {
  COMMENT( "Loading element. Type: " << objectName( ).toStdString( ), 4 );
  loadPos( ds );
  loadAngle( ds );
  /* <Version1.2> */
  loadLabel( ds, version );
  /* <\Version1.2> */
  /* <Version1.3> */
  loadMinMax( ds, version );
  /* <\Version1.3> */
  /* <Version1.9> */
  loadTrigger( ds, version );
  /* <\Version1.9> */
  loadInputPorts( ds, portMap );
  loadOutputPorts( ds, portMap );
  COMMENT( "Updating port positions.", 4 );
  updatePorts( );
  COMMENT( "Finished loading element.", 4 );
}


void GraphicElement::loadPos( QDataStream &ds ) {
  QPointF p;
  ds >> p;
  setPos( p );
}

void GraphicElement::loadAngle( QDataStream &ds ) {
  qreal angle;
  ds >> angle;
  setRotation( angle );
}

void GraphicElement::loadLabel( QDataStream &ds, double version ) {
  if( version >= 1.2 ) {
    QString label_text;
    ds >> label_text;
    setLabel( label_text );
  }
}

void GraphicElement::loadMinMax( QDataStream &ds, double version ) {
  if( version >= 1.3 ) {
    quint64 min_isz, max_isz, min_osz, max_osz;
    ds >> min_isz;
    ds >> max_isz;
    ds >> min_osz;
    ds >> max_osz;
//     FIXME: Was it a bad decision to store Min and Max input/ouput sizes?
    /* Version 2.2 ?? fix ?? */
    if( !( ( m_minInputSz == m_maxInputSz ) && ( m_minInputSz > max_isz ) ) ) {
      m_minInputSz = min_isz;
      m_maxInputSz = max_isz;
    }
    if( !( ( m_minOutputSz == m_maxOutputSz ) && ( m_minOutputSz > max_osz ) ) ) {
      m_minOutputSz = min_osz;
      m_maxOutputSz = max_osz;
    }
  }
}

void GraphicElement::loadTrigger( QDataStream &ds, double version ) {
  if( version >= 1.9 ) {
    QKeySequence trigger;
    ds >> trigger;
    setTrigger( trigger );
  }
}


void GraphicElement::loadInputPorts( QDataStream &ds, QMap< quint64, QNEPort* > &portMap ) {
  COMMENT( "Loading input ports.", 4 );
  quint64 inputSz;
  ds >> inputSz;
  if( inputSz > MAXIMUMVALIDINPUTSIZE ) {
    throw std::runtime_error( ERRORMSG( "Corrupted DataStream!" ) );
  }
  for( size_t port = 0; port < inputSz; ++port ) {
    loadInputPort( ds, portMap, port );
  }
  removeSurplusInputs( inputSz, portMap );
}


void GraphicElement::loadInputPort( QDataStream &ds, QMap< quint64, QNEPort* > &portMap, size_t port ) {
  QString name;
  int flags;
  quint64 ptr;
  ds >> ptr;
  ds >> name;
  ds >> flags;
  if( ( port < static_cast< size_t >( m_inputs.size() ) ) ) {
    if( elementType( ) == ElementType::BOX ) {
      m_inputs[ port ]->setName( name );
    }
    m_inputs[ port ]->setPortFlags( flags );
    m_inputs[ port ]->setPtr( ptr );
  }
  else {
    addPort( name, false, flags, ptr );
  }
  portMap[ ptr ] = m_inputs[ port ];
}


void GraphicElement::removeSurplusInputs( quint64 inputSz, QMap< quint64, QNEPort* > &portMap ) {
  while( inputSize( ) > static_cast< int >( inputSz ) && inputSz >= m_minInputSz ) {
    QNEPort *deletedPort = m_inputs.back( );
    removePortFromMap( deletedPort, portMap );
    delete deletedPort;
    m_inputs.pop_back( );
  }
}

void GraphicElement::removePortFromMap( QNEPort *deletedPort, QMap< quint64, QNEPort* > &portMap ) {
  for( auto it = portMap.begin( ); it != portMap.end( ); ) {
    if( it.value( ) == deletedPort ) {
      it = portMap.erase( it );
    }
    else {
      ++it;
    }
  }
}

void GraphicElement::loadOutputPorts( QDataStream &ds, QMap< quint64, QNEPort* > &portMap ) {
  COMMENT( "Loading output ports.", 4 );
  quint64 outputSz;
  ds >> outputSz;
  if( outputSz > MAXIMUMVALIDINPUTSIZE ) {
    throw std::runtime_error( ERRORMSG( "Corrupted DataStream!" ) );
  }
  for( size_t port = 0; port < outputSz; ++port ) {
    loadOutputPort( ds, portMap, port );
  }
}

void GraphicElement::loadOutputPort( QDataStream &ds, QMap< quint64, QNEPort* > &portMap, size_t port ) {
  QString name;
  int flags;
  quint64 ptr;
  ds >> ptr;
  ds >> name;
  ds >> flags;
  if( ( port < static_cast< size_t >( m_outputs.size( ) ) ) ) {
    if( elementType( ) == ElementType::BOX ) {
      m_outputs[ port ]->setName( name );
    }
    m_outputs[ port ]->setPortFlags( flags );
    m_outputs[ port ]->setPtr( ptr );
  }
  else {
    addPort( name, true, flags, ptr );
  }
  portMap[ ptr ] = m_outputs[ port ];
}


QVector< QNEInputPort* > GraphicElement::inputs( ) const {
  return( m_inputs );
}

void GraphicElement::setInputs( const QVector< QNEInputPort* > &inputs ) {
  m_inputs = inputs;
}


QRectF GraphicElement::boundingRect( ) const {
  return( pixmap->rect( ) );
}

void GraphicElement::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) {
  Q_UNUSED( widget )
  painter->setClipRect( option->exposedRect );
  if( isSelected( ) ) {
    painter->setBrush( m_selectionBrush );
    painter->setPen( QPen( m_selectionPen, 0.5, Qt::SolidLine ) );
    painter->drawRoundedRect( boundingRect( ), 5, 5 );
  }
  painter->drawPixmap( QPoint( 0, 0 ), getPixmap( ) );
}

QNEPort* GraphicElement::addPort( const QString &name, bool isOutput, int flags, int ptr ) {
  COMMENT( "Adding new port.", 4 );
  if( isOutput && ( static_cast< quint64 >( m_outputs.size( ) ) >= m_maxOutputSz ) ) {
    return( nullptr );
  }
  else if( !isOutput && ( static_cast< quint64 >( m_inputs.size( ) ) >= m_maxInputSz ) ) {
    return( nullptr );
  }
  QNEPort *port = nullptr;
  if( isOutput ) {
    m_outputs.push_back( new QNEOutputPort( this ) );
    port = dynamic_cast< QNEPort* >( m_outputs.last( ) );
    port->setIndex( outputSize( ) - 1 );
  }
  else {
    m_inputs.push_back( new QNEInputPort( this ) );
    port = dynamic_cast< QNEPort* >( m_inputs.last( ) );
    port->setIndex( inputSize( ) - 1 );
  }
  port->setName( name );
  port->setGraphicElement( this );
  port->setPortFlags( flags );
  port->setPtr( ptr );
  COMMENT( "Updating new port.", 4 );
  this->updatePorts( );
  port->show( );
  return( port );
}

void GraphicElement::addInputPort( const QString &name ) {
  addPort( name, false );
}

void GraphicElement::addOutputPort( const QString &name ) {
  addPort( name, true );
}

void GraphicElement::setPortName( QString name ) {
  setObjectName( name );
  setToolTip( name );
}

void GraphicElement::updatePorts( ) {
/*  qDebug() << "UpdatePorts"; */
  COMMENT( "Updating port positions that belong to the box.", 4 );
  int inputPos = m_topPosition;
  int outputPos = m_bottomPosition;
  if( m_outputsOnTop ) {
    inputPos = m_bottomPosition;
    outputPos = m_topPosition;
  }
  if( !m_outputs.isEmpty( ) ) {
    int step = qMax( 32 / m_outputs.size( ), 6 );
    int x = 32 - m_outputs.size( ) * step + step;
    foreach( QNEPort * port, m_outputs ) {
      port->setPos( x, outputPos );
      port->update( );
      x += step * 2;
    }
  }
  if( !m_inputs.isEmpty( ) ) {
    int step = qMax( 32 / m_inputs.size( ), 6 );
    int x = 32 - m_inputs.size( ) * step + step;
    foreach( QNEPort * port, m_inputs ) {
      port->setPos( x, inputPos );
      port->update( );
      x += step * 2;
    }
  }
}

void GraphicElement::refresh( ) {

}

/*
 * void GraphicElement::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * e) {
 *  if(e->button() == Qt::LeftButton) {
 *    addOutputPort();
 *  } else {
 *    addInputPort();
 *  }
 * }
 */

QVariant GraphicElement::itemChange( QGraphicsItem::GraphicsItemChange change, const QVariant &value ) {
  COMMENT( "Align to grid.", 4 );
  if( ( change == ItemPositionChange ) && scene( ) ) {
    QPointF newPos = value.toPointF( );
    Scene *customScene = dynamic_cast< Scene* >( scene( ) );
    if( customScene ) {
      int gridSize = customScene->gridSize( );
      qreal xV = qRound( newPos.x( ) / gridSize ) * gridSize;
      qreal yV = qRound( newPos.y( ) / gridSize ) * gridSize;
      return( QPointF( xV, yV ) );
    }
    else {
      return( newPos );
    }
  }
  COMMENT( "Moves wires.", 4 );
  if( ( change == ItemScenePositionHasChanged ) || ( change == ItemRotationHasChanged ) ||
      ( change == ItemTransformHasChanged ) ) {
    foreach( QNEPort * port, m_outputs ) {
      port->updateConnections( );
    }
    foreach( QNEPort * port, m_inputs ) {
      port->updateConnections( );
    }
  }
  update( );

  return( QGraphicsItem::itemChange( change, value ) );
}

bool GraphicElement::hasAudio( ) const {
  return( m_hasAudio );
}

void GraphicElement::setHasAudio( bool hasaudio ) {
  m_hasAudio = hasaudio;
}

QKeySequence GraphicElement::getTrigger( ) const {
  return( m_trigger );
}

void GraphicElement::setTrigger( const QKeySequence &trigger ) {
  m_trigger = trigger;
  updateLabel( );
}

QString GraphicElement::genericProperties( ) {
  return( QString( ) );
}

void GraphicElement::updateLabel( ) {
  QString label = m_labelText;
  if( !hasTrigger( ) || getTrigger( ).toString( ).isEmpty( ) ) {
    this->label->setPlainText( label );
  }
  else {
    if( !label.isEmpty( ) ) {
      label += " ";
    }
    this->label->setPlainText( label + QString( "(%1)" ).arg( getTrigger( ).toString( ) ) );
  }
}

void GraphicElement::setLabel( QString label ) {
  m_labelText = label;
  updateLabel( );
}

QString GraphicElement::getLabel( ) const {
  return( m_labelText );
}

void GraphicElement::updateTheme( ) {
  if( ThemeManager::globalMngr ) {
    const ThemeAttrs attrs = ThemeManager::globalMngr->getAttrs( );

    label->setDefaultTextColor( attrs.graphicElement_labelColor );
    m_selectionBrush = attrs.selectionBrush;
    m_selectionPen = attrs.selectionPen;
    for( QNEInputPort *input  : m_inputs ) {
      input->updateTheme( );
    }
    for( QNEOutputPort *output : outputs( ) ) {
      output->updateTheme( );
    }
    updateThemeLocal( );

    setPixmap( currentPixmapName );
    update( );
  }
}

void GraphicElement::updateThemeLocal( ) {

}

bool GraphicElement::isValid( ) {
  COMMENT( "Checking if the element has the required signals to comput its value.", 4 );
  bool valid = true;
  for( QNEInputPort *input  : m_inputs ) {
    /* Required inputs must have exactly one connection. */
    if( !input->isValid( ) ) {
      valid = false;
      break;
    }
  }
  if( valid == false ) {
    for( QNEOutputPort *output : outputs( ) ) {
      for( QNEConnection *conn : output->connections( ) ) {
        conn->setStatus( QNEConnection::Status::Invalid );
        QNEInputPort *port = conn->otherPort( output );
        if( port ) {
          port->setValue( -1 );
        }
      }
    }
  }
  return( valid );
}

bool GraphicElement::hasColors( ) const {
  return( m_hasColors );
}

bool GraphicElement::hasTrigger( ) const {
  return( m_hasTrigger );
}

void GraphicElement::setColor( QString ) {

}

QString GraphicElement::getColor( ) const {
  return( QString( ) );
}

void GraphicElement::setAudio( QString ) {

}

QString GraphicElement::getAudio( ) const {
  return( QString( ) );
}

void GraphicElement::setHasColors( bool hasColors ) {
  m_hasColors = hasColors;
}

void GraphicElement::setHasTrigger( bool hasTrigger ) {
  m_hasTrigger = hasTrigger;
}

bool GraphicElement::hasFrequency( ) const {
  return( m_hasFrequency );
}

void GraphicElement::setHasFrequency( bool hasFrequency ) {
  m_hasFrequency = hasFrequency;
}

bool GraphicElement::hasLabel( ) const {
  return( m_hasLabel );
}

void GraphicElement::setHasLabel( bool hasLabel ) {
  m_hasLabel = hasLabel;
  label->setVisible( hasLabel );
}

bool GraphicElement::rotatable( ) const {
  return( m_rotatable );
}

void GraphicElement::setRotatable( bool rotatable ) {
  m_rotatable = rotatable;
}

int GraphicElement::minOutputSz( ) const {
  return( m_minOutputSz );
}

int GraphicElement::inputSize( ) const {
  return( m_inputs.size( ) );
}

void GraphicElement::setInputSize( int size ) {
  if( ( size >= minInputSz( ) ) && ( size <= maxInputSz( ) ) ) {
    if( inputSize( ) < size ) {
      while( inputSize( ) < size ) {
        addInputPort( );
      }
    }
    else {
      while( inputSize( ) > size ) {
        delete m_inputs.back( );
        m_inputs.pop_back( );
      }
      updatePorts( );
    }
  }
}

int GraphicElement::outputSize( ) const {
  return( m_outputs.size( ) );
}

void GraphicElement::setOutputSize( const int size ) {
  if( ( size >= minOutputSz( ) ) && ( size <= maxOutputSz( ) ) ) {
    if( outputSize( ) < size ) {
      for( int port = outputSize( ); port < size; ++port ) {
        addOutputPort( );
      }
    }
    else {
      while( outputSize( ) > size ) {
        m_outputs.pop_back( );
      }
    }
  }
}

float GraphicElement::getFrequency( ) const {
  return( 0.0 );
}

void GraphicElement::setFrequency( float ) {

}

void GraphicElement::setMinOutputSz( int minOutputSz ) {
  m_minOutputSz = minOutputSz;
}

int GraphicElement::minInputSz( ) const {
  return( m_minInputSz );
}

void GraphicElement::setMinInputSz( const int minInputSz ) {
  m_minInputSz = minInputSz;
}


int GraphicElement::maxOutputSz( ) const {
  return( m_maxOutputSz );
}

void GraphicElement::setMaxOutputSz( int maxOutputSz ) {
  m_maxOutputSz = maxOutputSz;
}

int GraphicElement::maxInputSz( ) const {
  return( m_maxInputSz );
}

void GraphicElement::setMaxInputSz( int maxInputSz ) {
  m_maxInputSz = maxInputSz;
}

int GraphicElement::bottomPosition( ) const {
  return( m_bottomPosition );
}

void GraphicElement::setBottomPosition( int bottomPosition ) {
  m_bottomPosition = bottomPosition;
  updatePorts( );
}

int GraphicElement::topPosition( ) const {
  return( m_topPosition );
}

void GraphicElement::setTopPosition( int topPosition ) {
  m_topPosition = topPosition;
  updatePorts( );
}

bool GraphicElement::outputsOnTop( ) const {
  return( m_outputsOnTop );
}

void GraphicElement::setOutputsOnTop( bool outputsOnTop ) {
  m_outputsOnTop = outputsOnTop;
  updatePorts( );
}

bool GraphicElement::disabled( ) {
  return( m_disabled );
}
