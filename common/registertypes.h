#include "ic.h"
#include "inputvcc.h"
#include "and.h"
#include "audiobox.h"
#include "buzzer.h"
#include "clock.h"
#include "demux.h"
#include "dflipflop.h"
#include "display_14.h"
#include "display_7.h"
#include "dlatch.h"
#include "inputbutton.h"
#include "inputgnd.h"
#include "inputrotary.h"
#include "inputswitch.h"
#include "jkflipflop.h"
#include "led.h"
#include "line.h"
#include "mux.h"
#include "nand.h"
#include "node.h"
#include "nor.h"
#include "not.h"
#include "or.h"
#include "qneconnection.h"
#include "qneport.h"
#include "srflipflop.h"
#include "text.h"
#include "tflipflop.h"
#include "truth_table.h"
#include "xnor.h"
#include "xor.h"

inline void registerTypes() {
    qRegisterMetaType<And>();
    qRegisterMetaType<AudioBox>();
    qRegisterMetaType<Buzzer>();
    qRegisterMetaType<Clock>();
    qRegisterMetaType<Demux>();
    qRegisterMetaType<DFlipFlop>();
    qRegisterMetaType<Display14>();
    qRegisterMetaType<Display7>();
    qRegisterMetaType<DLatch>();
    qRegisterMetaType<InputButton>();
    qRegisterMetaType<InputGnd>();
    qRegisterMetaType<InputRotary>();
    qRegisterMetaType<InputSwitch>();
    qRegisterMetaType<InputVcc>();
    qRegisterMetaType<JKFlipFlop>();
    qRegisterMetaType<Led>();
    qRegisterMetaType<Line>();
    qRegisterMetaType<Mux>();
    qRegisterMetaType<Nand>();
    qRegisterMetaType<Node>();
    qRegisterMetaType<Nor>();
    qRegisterMetaType<Not>();
    qRegisterMetaType<Or>();
    qRegisterMetaType<SRFlipFlop>();
    qRegisterMetaType<Text>();
    qRegisterMetaType<TFlipFlop>();
    qRegisterMetaType<TruthTable>();
    qRegisterMetaType<Xnor>();
    qRegisterMetaType<Xor>();
    qRegisterMetaType<GraphicElement>();
    qRegisterMetaType<IC>();
    qRegisterMetaType<QNEConnection>();
    qRegisterMetaType<QNEInputPort>();
    qRegisterMetaType<QNEOutputPort>();
}
