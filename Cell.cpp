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

void Cell::open()
{
    if (m_open == true){
        return;
    }

    m_open = true;
    emit isOpenChanged(true);
    emit cellOpened(this);
}

void Cell::close()
{
    if (m_open == false){
        return;
    }

    m_open = false;
    emit isOpenChanged(false);
//    emit cellOpened(this);
}

