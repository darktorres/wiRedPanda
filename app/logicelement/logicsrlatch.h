// Copyright 2015 - 2025, GIBIS-UNIFESP and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "logicelement.h"

class LogicSRLatch : public LogicElement
{
public:
    explicit LogicSRLatch();

    void updateLogic() override;

private:
    Q_DISABLE_COPY(LogicSRLatch)
};
