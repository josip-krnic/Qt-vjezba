import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Protocol 1.0

Window {
    width: 500
    height: 400
    visible: true
    title: qsTr("Hello World")
    color: "green"

    Protocol {
        id: protocol
    }

    Item {
        width: 200
        height: 200
        x: 40
        y: 20

        Item {
            anchors.centerIn: parent
            width: 180; height: 28

            Rectangle {
                width: 180
                height: 30
                border.color: "white"
                border.width: 5
                radius: 10
            }

            Label {
                text: "message:"
                font.pixelSize: 22
                anchors.centerIn: parent
            }

        }
    }


    Item {
        width: 200
        height: 200

        x: 250
        y: 20


        Item {
            property alias text: message.text
            anchors.centerIn: parent
            width: 180; height: 28

            Rectangle {
                width: 180
                height: 30
                border.color: "white"
                border.width: 5
                radius: 10
            }


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

    Item {
        width: 200
        height: 200
        x: 40
        y: 60

        Item {
            anchors.centerIn: parent
            width: 180; height: 28

            Rectangle {
                width: 180
                height: 30
                border.color: "white"
                border.width: 5
                radius: 10
            }

            Label {
                text: "ID:"
                font.pixelSize: 22
                anchors.centerIn: parent
            }

        }
    }


    Item {
        width: 200
        height: 200

        x: 250
        y: 60


        Item {
            property alias text: frame_id.text
            anchors.centerIn: parent
            width: 180; height: 28

            Rectangle {
                width: 180
                height: 30
                border.color: "white"
                border.width: 5
                radius: 10
            }


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

    Item {
        width: 100
        height: 100

        x: 175
        y: 180


        Item {
            anchors.centerIn: parent
            width: 50; height: 40

            Rectangle {
                width: 100
                height: 30
                border.width: 5
                radius: 10
            }

            Button {
                text: "Send"
                highlighted: true
                onClicked: protocol.setData(message.text, frame_id.text)
            }
        }
    }
}
