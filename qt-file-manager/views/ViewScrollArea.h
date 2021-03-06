#pragma once
#ifndef VIEWSCROLLAREA_H
#define VIEWSCROLLAREA_H

#include <QtWidgets>

class View;

class ViewScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit ViewScrollArea(View *view);

    void scroll_to(int index);

protected:
    virtual void keyReleaseEvent(QKeyEvent *);
    virtual void focusInEvent(QFocusEvent *);

signals:
    
public slots:
    
};

#endif // VIEWSCROLLAREA_H
