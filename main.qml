import QtQuick 2.3
import QtQuick.Window 2.2

import Pairs 1.0

Window {
    visible: true
    width: 800
    height: 600
    Field {
        id: field
    }

    Rectangle {
        id: board
        color: "lightgray"
        anchors.fill: parent
        anchors.margins: 10

        Grid {
            id: grid
            rows: field.width
            columns: field.height
            spacing: 4

            Repeater {
                model: field.width * field.height

                CellItem {
                    id: cellItem
                }
            }
        }
    }
}
