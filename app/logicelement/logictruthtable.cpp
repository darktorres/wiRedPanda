// Copyright 2015 - 2025, GIBIS-UNIFESP and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#include "logictruthtable.h"

LogicTruthTable::LogicTruthTable(const int inputSize, const int outputSize, const QBitArray &key)
    : LogicElement(inputSize, outputSize)
{
    m_proposition = key;
    m_nOutputs = outputSize;
}

void LogicTruthTable::updateLogic()
{
    if (!updateInputs()) {
        return;
    }

    for (int i = 0; i < this->m_nOutputs; ++i) {
        const auto pos = std::accumulate(m_inputValues.cbegin(), m_inputValues.cend(), QString(""),
                                         [](QString acc, bool b) {
                                             acc += (b == 1) ? '1' : '0';
                                             return acc;
                                         }).toUInt(nullptr, 2);
        const bool result = m_proposition.at(256 * i + pos);
        setOutputValue(i, result);
    }
}
