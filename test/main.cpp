#include "testelements.h"
#include "testpriorityqueue.h"
#include "testsimulationcontroller.h"
#include <QtTest>

int main( int argc, char **argv ) {
  QApplication a( argc, argv );
  a.setOrganizationName( "WPanda" );
  a.setApplicationName( "WiredPanda" );
  a.setApplicationVersion( APP_VERSION );
  TestPriorityQueue testPriorityQueue;
  TestElements testElements;
  TestSimulationController testSC;
  int status = 0;
  status |= QTest::qExec( &testPriorityQueue, argc, argv );
  status |= QTest::qExec( &testElements, argc, argv );
  status |= QTest::qExec( &testSC, argc, argv );
  /* multiple test suites can be ran like this */
  return( status );
}
