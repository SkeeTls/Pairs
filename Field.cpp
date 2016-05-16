#include "Field.hpp"

#include "Cell.hpp"

#include <QDebug>

Field::Field(QObject *parent) :
    QObject(parent),
    m_width(10),
    m_height(10),
    count(1),
    m_firstCell(nullptr),
    m_secondCell(nullptr),
    fcell(-1),
    scell(-1)
{
    applySize();
}

Cell *Field::cellAt(int x, int y)
{
    if (x < 0 || x >= width()) {
        return nullptr;
    }

    if (y < 0 || y >= height()) {
        return nullptr;
    }

    int index = x + y * width();

    if (index >= m_cells.count()) {
        return nullptr;
    }

    return m_cells.at(index);
}

void Field::setWidth(int width)
{
    if (m_width == width) {
        return;
    }

    m_width = width;
    emit widthChanged(width);
}

void Field::setHeight(int height)
{
    if (m_height == height) {
        return;
    }

    m_height = height;
    emit heightChanged(height);
}

void Field::onCellOpened(Cell *cell)
{
    if (m_firstCell == nullptr) {
        m_firstCell = cell;
        fcell = cell->key();
    } else {
        m_secondCell = cell;
        scell = cell->key();
    }
    if (m_firstCell != nullptr && m_secondCell != nullptr && count % 3 == 0) {
        m_firstCell = cell;
        m_secondCell = nullptr;
    }

    if (fcell == scell) {
        return;
    } else {
        closeCells();
    }

    qDebug()<<m_firstCell;
if (count % 2 == 0) {
    qDebug()<<m_secondCell<<"\n";
}
count++;
}

void Field::closeCells()
{
    m_firstCell->close();
    m_secondCell->close();
}



void Field::applySize()
{
    for (Cell *cell : m_cells) {
        delete cell;
    }

    m_cells.clear();

    for (int y = 0; y < height(); ++y) {
        for (int x = 0; x < width(); ++x) {
            Cell *cell = new Cell(this);
            cell->setKey(qrand() % 6);
            connect (cell, SIGNAL(cellOpened(Cell*)), this, SLOT(onCellOpened(Cell*)));
            m_cells.append(cell);
        }
    }
}
