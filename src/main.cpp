#include <QApplication>

#include "mainWindow.h"
#include <QFile>

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	a.setFont(QFont("Microsoft Yahei", 9));
	a.setWindowIcon(QIcon("./res/ico/main.ico"));

	QFile file("./res/qss/psblack.css");
	if (file.open(QFile::ReadOnly))
	{
		QString qss = QLatin1String(file.readAll());
		QString paletteColor = qss.mid(20, 7);
		qApp->setPalette(QPalette(QColor(paletteColor)));
		qApp->setStyleSheet(qss);
		file.close();
	}

	page::MainWindow w;
	w.show();

	return a.exec();
}