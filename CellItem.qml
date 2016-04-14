import QtQuick 2.3
import QtQuick.Window 2.2

import Pairs 1.0

Rectangle {
    id: cellItem
    width: 48
    height: 32
    property Cell cell: field.cellAt(index % field.width, index / field.width)
    
    Flipable {
        anchors.fill:parent
        front : Rectangle {
            anchors.fill:parent
            color : "gray"
            border.color: "black"
            border.width: 2
        }
        back : Image {
            anchors.centerIn: parent
            width:40
            height:40
            id:image5
            source: "qrc:///smeshariki/" + cell.key + ".png"
        }
        transform: Rotation {
            axis.x: 1
            axis.y: 0
            axis.z: 0

            origin.x: cellItem.width / 2
            origin.y: cellItem.height / 2

            angle : cellItem.cell.open ? 180 : 0

            Behavior on angle {
                NumberAnimation {
                    duration: 1000
                }
            }
        }
    }

    MouseArea {
        anchors.fill:parent
        onClicked: cellItem.cell.open = true
    }
}
