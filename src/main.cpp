#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Car.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  Car car;

  engine.rootContext()->setContextProperty("car", &car);
  engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

  if (engine.rootObjects().isEmpty()) return -1;

  return QCoreApplication::exec();
}