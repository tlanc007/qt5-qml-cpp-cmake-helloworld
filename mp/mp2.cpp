/***
 Simple example showing how to read a property.
 Specifically getting the text property from a Text object.
 and converting it to std::string.
 
 NOTE: The findChild searches on objectName and not id.  
 id is internal to Quick.
 
 
 1/17/17 -- Tal Lancaster
 ***/

#include <iostream>
#include <string>

#include <QGuiApplication>
#include <QQuickView>
#include <QtQuick>
#include <QtQml>
#include <QtCore>

int main (int argc, char* argv[])
{

    QGuiApplication q_app (argc, argv);
    
    // Using QQuickView
    QQuickView view;
    view.setSource(QUrl::fromLocalFile("../qml/hw.qml"));
    view.show();
    QObject* object {view.rootObject () };
    QObject* text {object->findChild<QObject*> ("helloText") };
    if (text) {
        std::string str {text->property ("text").toString().toStdString() };
        std::cout << "from text obj " << str << "\n";
    }
    else {
        std::cout << "text object not found.\n";
    }
    
    return q_app.exec ();
}

