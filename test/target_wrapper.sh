#!/bin/sh
LD_LIBRARY_PATH=/home/runner/work/wiRedPanda/Qt/6.6.3/wasm_multithread/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/home/runner/work/wiRedPanda/Qt/6.6.3/wasm_multithread/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
