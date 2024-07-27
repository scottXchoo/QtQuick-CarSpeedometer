#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CarModel.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  CarModel carModel;
  engine.rootContext()->setContextProperty("carModel", &carModel);

  const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
				   &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
		  QCoreApplication::exit(-1);
	  }, Qt::QueuedConnection);

  engine.load(url);

  return QGuiApplication::exec();
}
