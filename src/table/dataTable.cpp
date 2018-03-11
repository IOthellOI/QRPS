#include "dataTable.h"

#include <QTableWidget>
#include <QLayout>

struct table::DataTable::DataTableData
{
	QTableWidget * table;
};

table::DataTable::DataTable(QWidget * _parent):
	data(new DataTableData),
	BaseWidget(_parent)
{
	QVBoxLayout * layout = new QVBoxLayout;

	data->table = new QTableWidget;
	data->table->setFrameShape(QFrame::NoFrame);
	data->table->setColumnCount(4);

	QStringList header;
	header << tr("序号") << tr("数据名称") << tr("变量名称") << tr("数据类型");
	data->table->setHorizontalHeaderLabels(header);

	layout->addWidget(data->table);

	setLayout(layout);
}

table::DataTable::~DataTable()
{

}
