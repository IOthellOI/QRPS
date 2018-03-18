#include <QApplication>
#include <QFile>

#include "mainWindow.h"

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	a.setFont(QFont("Microsoft Yahei", 9));
	a.setWindowIcon(QIcon("./res/ico/main.ico"));

	page::MainWindow w;
	w.setWindowTitle("��¼�ط�ϵͳ���");
	w.show();

	//QFile file("./res/styleSheet.css");
	//if (file.open(QFile::ReadOnly))
	//{
	//	QString qss = QLatin1String(file.readAll());
	//	qApp->setStyleSheet(qss);
	//	file.close();
	//}
	
	return a.exec();
}