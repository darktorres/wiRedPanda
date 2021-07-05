/*
 * Copyright 2015 - 2021, GIBIS-Unifesp and the wiRedPanda contributors
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QObject>

class GraphicElement;
class QNEConnection;

class Scene : public QGraphicsScene
{
public:
    explicit Scene(QObject *parent = nullptr, int id=0);
    Scene(const QRectF &sceneRect, QObject *parent = nullptr);
    Scene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);

    /* QGraphicsScene interface */
    int gridSize() const;
    int m_id;
    QVector<GraphicElement *> getElements();
    QVector<GraphicElement *> getElements(const QRectF &rect);
    QVector<QNEConnection *> getConnections();
    QVector<GraphicElement *> selectedElements();

    void setDots(const QPen &dots);

    QVector<GraphicElement *> getVisibleElements();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    static constexpr int m_gridSize = 16;
    QPen m_dots;
};

#endif /* SCENE_H */
