#include <QApplication>

#include "dataTable.h"

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	table::DataTable w;
	w.show();

	return a.exec();
}