#ifndef CELL_HPP
#define CELL_HPP

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int key READ key NOTIFY keyChanged)
    Q_PROPERTY(bool open READ open WRITE setOpen NOTIFY openChanged)
public:
    explicit Cell(QObject *parent = 0);

    int key() const { return m_key; }
    int open() {return m_open;}
    void setKey(int key);

signals:
    void keyChanged(int key);
    void openChanged (bool open);

public slots:
    void setOpen(bool open);

private:
    int m_key;
    bool m_open;
};

#endif // CELL_HPP
