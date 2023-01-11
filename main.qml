import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Protocol 1.0

Window {

    width: 600
    height: 600
    visible: true
    title: qsTr("Hello World")
    color: "green"

    Protocol {
        id: protocol
    }

    Rectangle {
        anchors.centerIn: parent


        Column {
            anchors.centerIn: parent
            spacing: 20

            Row {
                spacing: 30
                width: parent.width

                Rectangle {

                    width: 180
                    height: 30
                    border.color: "white"
                    border.width: 5
                    radius: 10

                    Label {
                        text: "message:"
                        font.pixelSize: 22
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    width: 180
                    height: 30
                    border.color: "white"
                    border.width: 5
                    radius: 10

                    TextInput {
                        id: message
                        color: "black";
                        selectionColor: "green"
                        font.pixelSize: 16; font.bold: true
                        width: parent.width-16
                        maximumLength: 16
                        anchors.centerIn: parent
                        focus: true
                    }
                }
            }

            Row {
                spacing: 30

                Rectangle {
                    width: 180
                    height: 30
                    border.color: "white"
                    border.width: 5
                    radius: 10

                    Label {
                        text: "ID:"
                        font.pixelSize: 22
                        anchors.centerIn: parent
                    }
                }


                Rectangle {
                    width: 180
                    height: 30
                    border.color: "white"
                    border.width: 5
                    radius: 10

                    TextInput {
                        id: frame_id
                        color: "black";
                        selectionColor: "green"
                        font.pixelSize: 16; font.bold: true
                        width: parent.width-16
                        maximumLength: 16
                        anchors.centerIn: parent
                        focus: true
                    }
                }
            }

            Row {
                spacing: 30

                Rectangle {
                    width: 100
                    height: 30
                    border.width: 5
                    radius: 10

                    Button {
                        text: "Send"
                        highlighted: true
                        onClicked: protocol.setData(message.text, frame_id.text)
                    }
                }
            }
        }
    }
}
