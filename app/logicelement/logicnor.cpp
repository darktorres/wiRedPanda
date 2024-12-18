// Copyright 2015 - 2024, GIBIS-UNIFESP and the WiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#include "logicnor.h"

#include <functional>

LogicNor::LogicNor(const int inputSize)
    : LogicElement(inputSize, 1)
{
}

void LogicNor::updateLogic()
{
    if (!updateInputs()) {
        return;
    }

    const auto result = std::accumulate(m_inputValues.cbegin(), m_inputValues.cend(), false, std::bit_or<>());
    setOutputValue(!result);
}
