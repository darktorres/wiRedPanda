// Copyright 2015 - 2025, GIBIS-UNIFESP and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "logicelement.h"

class LogicInput : public LogicElement
{
public:
    explicit LogicInput(const bool defaultValue = false, const int nOutputs = 1);

    void updateLogic() override;

private:
    Q_DISABLE_COPY(LogicInput)
};
