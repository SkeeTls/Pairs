import QtQuick 2.3
import QtQuick.Window 2.2

import Pairs 1.0

Rectangle {
    id: cellItem
    width: 48
    height: 32
    property Cell cell: field.cellAt(index % field.width, index / field.width)
    
    Text {
        anchors.centerIn: parent
        text: cell.key
    }
    Image{
        anchors.centerIn: parent
        width:40
        height:40
        id:image5
        source: "qrc:///smeshariki/" + cell.key + ".png"
    }
    
}
