#include "Cell.hpp"
/*0=file:///C:/Users/user-pc/Desktop/smeshariki/0.png;
1=file:///C:/Users/user-pc/Desktop/smeshariki/1.png;
2=file:///C:/Users/user-pc/Desktop/smeshariki/2.png;
3=file:///C:/Users/user-pc/Desktop/smeshariki/3.png;
4=file:///C:/Users/user-pc/Desktop/smeshariki/4.png;
5=file:///C:/Users/user-pc/Desktop/smeshariki/5.png;*/
Cell::Cell(QObject *parent) :
    QObject(parent),
    m_key(0)
{

}

void Cell::setKey(int key)
{
    if (m_key == key) {
        return;
    }

    m_key = key;
    emit keyChanged(key);
}
