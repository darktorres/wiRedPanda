// Copyright 2015 - 2025, GIBIS-UNIFESP and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#include "logicnot.h"

LogicNot::LogicNot()
    : LogicElement(1, 1, 1)
{
}

void LogicNot::updateLogic()
{
    if (!updateInputs()) {
        return;
    }

    if (isTempSimulationOn()) {
        updateInputBuffer();
        setOutputValue(!m_inputBuffer.last()[0]);
    } else {
        setOutputValue(!m_inputValues.at(0));
    }
}
