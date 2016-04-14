#include "Cell.hpp"

Cell::Cell(QObject *parent) :
    QObject(parent),
    m_key(0)
{
    m_open = false;
}

void Cell::setKey(int key)
{
    if (m_key == key) {
        return;
    }

    m_key = key;
    emit keyChanged(key);
}

void Cell::setOpen(bool open)
{
    if (m_open == open){
        return;
    }

    m_open = open;
    emit openChanged(open);
}
