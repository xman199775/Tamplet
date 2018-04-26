import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.3
ApplicationWindow {
    visible: true
    title: "Emolyee Data"
    width:  520
    height: 720
    maximumWidth: 520
    maximumHeight:  720
    minimumWidth:   520
    minimumHeight:  720
    color:"#000c14"
    Item {
        id: emplyeeData
        width: parent.width
        height:parent.height
        transformOrigin: Item.Center
        Rectangle
        {
            id :   borderRectangle
            width: parent.width
            height:parent.height
            color: "#bfbfbf"
            radius: 20
            border.color: "#000c14"
            border.width: 10
            GridLayout
            {
                id: mainLayout
                anchors.fill: parent
                layoutDirection: Qt.RightToLeft
                anchors.margins: 12
                columns: 4
                rows :14
                GridLayout
                {
                    Layout.columnSpan: 4
                    Layout.rowSpan: 3
                    columns: 4
                    layoutDirection: Qt.RightToLeft
                    GridLayout
                    {
                        Layout.columnSpan: 3
                        rows : 3
                        columns: 2
                        layoutDirection: Qt.RightToLeft
                        Label
                        {
                            id : titleLabel
                            text: "بيانات الموظف"
                            Layout.columnSpan: 2
                            Layout.rowSpan: 2
                            Layout.fillWidth: true
                            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                            font.pixelSize: 30
                            color: "#000c14"
                            fontSizeMode: Text.Fit
                            font.family: "Arial"
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.bold: true
                        }
                        Label
                        {
                            id : emplyeeCodeLabel
                            text: "كود الموظف"
                            Layout.fillWidth: true
                            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                            font.pixelSize: 20
                            color: "#000c14"
                            fontSizeMode: Text.Fit
                            font.family: "Arial"
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.bold: true
                        }
                        TextField
                        {
                            id : emplyeeCodeTextField
                            Layout.fillWidth: true
                            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                            font.pixelSize: 15
                            placeholderText: "ادخل كود الموظف ..."
                            font.family: "Arial"
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.bold: true
                        }

                    }
                    Rectangle {
                        id: emplyeePhoto
                         color: "#000c14"
                        //   source: "c:/Users/xman1/Desktop/images.png"
                    //  fillMode: Image.PreserveAspectFit
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                    }
                }
                Label
                {
                    id : emplyeeNameLabel
                    text: " اسم الموظف : "
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    wrapMode: Text.WrapAnywhere
                    font.pixelSize: 20
                    color: "#000c14"
                    fontSizeMode: Text.Fit
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                TextField
                {
                    id : emplyeeNameTextField
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    font.pixelSize: 15
                    placeholderText: " ادخل اسم الموظف ..."
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                Label
                {
                    id : emplyeeNickNamelabel
                    text: " لقب الموظف  : "
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    font.pixelSize: 20
                    color: "#000c14"
                    fontSizeMode: Text.Fit
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                TextField
                {
                    id :emplyeeNickNameTextField
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    placeholderText: "ادخل لقب الموظف ..."
                    font.pixelSize: 15
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                Label
                {
                    id : emplyeePhoneNumberlabel
                    text: "رقم الهاتف : "
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    font.pixelSize: 20
                    color: "#000c14"
                    fontSizeMode: Text.Fit
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                TextField
                {
                    id :emplyeePhoneNumberTextField
                    Layout.columnSpan: 3
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    placeholderText: "ادخل رقم الهاتف ... "
                    font.pixelSize: 15
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                Label
                {
                    id : emplyeeSSNlabel
                    text: "الرقم القومي : "
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    font.pixelSize: 20
                    color: "#000c14"
                    fontSizeMode: Text.Fit
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                TextField
                {
                    id :emplyeeSSNTextField
                    Layout.columnSpan: 3
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    placeholderText: " ادخل الرقم القومي ..."
                    font.pixelSize: 15
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                Label
                {
                    id : emplyeeAddresslabel
                    text: "عنوان الموظف : "
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    font.pixelSize: 20
                    color: "#000c14"
                    fontSizeMode: Text.Fit
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                TextField
                {
                    id :emplyeeAddressTextField
                    Layout.columnSpan: 3
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    placeholderText: "ادخل عنوان الموظف ... "
                    font.pixelSize: 15
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                Label
                {
                    id : emplyeeEmaillabel
                    text: "البريد الالكتروني : "
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    font.pixelSize: 20
                    color: "#000c14"
                    fontSizeMode: Text.Fit
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }
                TextField
                {
                    id :emplyeeEmailTextField
                    Layout.columnSpan: 3
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    placeholderText: "ادخل البريد الالكتروني ... "
                    font.pixelSize: 15
                    font.family: "Arial"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                }


            }

        }
    }
}

