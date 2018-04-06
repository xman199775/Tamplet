import QtQuick 2.0
import QtQuick.Controls 2.2
ApplicationWindow{
    id:  winRoot
    visible: true
    title: "main"
    width:  400
    height:  300
    Label {
        x: 155
        y: 133
        width: 90
        height: 34
        text:"test"
        font.weight: Font.Normal
        font.pointSize: 20
        font.family: "Arial"
        fontSizeMode: Text.Fit
        lineHeight: 1
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: "red"
    }

}
