/***
 Simple example showing how to set properties.
 item->setWidth (300);
 rect->setProperty ("color", "red");
 
 1/17/17 -- Tal Lancaster
 ***/
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
    view.setSource(QUrl::fromLocalFile("../qml/itemRect.qml"));
    view.show();
    QQuickItem* item {view.rootObject () };
    item->setWidth (300);
    
    QObject* rect = item->findChild<QObject*> ("rect");
    if (rect) {
        rect->setProperty ("color", "red");
    }
    
    
    return q_app.exec ();
}

