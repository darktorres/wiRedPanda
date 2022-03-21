// Copyright 2015 - 2022, GIBIS-Unifesp and the WiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#include "logicinput.h"

LogicInput::LogicInput(bool defaultValue, int n_outputs)
    : LogicElement(0, n_outputs)
{
    setOutputValue(0, defaultValue);
    for (int port=1; port < n_outputs; ++port) {
        setOutputValue(port, false);
    }
}

void LogicInput::_updateLogic(const std::vector<bool> &)
{
    // Does nothing on update
}
