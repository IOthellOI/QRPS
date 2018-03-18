#include "dataTable.h"
#include "xmlRead.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>
#include <QVariant>

struct table::DataTable::DataTableData
{
	QTableWidget * table;
	QLabel * label;
};

table::DataTable::DataTable(QWidget * _parent):
	BaseWidget(_parent),
	data(new DataTableData)
{
	QVBoxLayout * layout = new QVBoxLayout;
	layout->setMargin(0);

	setMinimumHeight(700);

	data->table = new QTableWidget;
	data->table->setFrameShape(QFrame::NoFrame);
	data->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	data->table->setSelectionBehavior(QAbstractItemView::SelectRows);
	data->table->setColumnCount(7);

	QStringList header;
	header << tr("数据名称") << tr("变量名称") 
		<< tr("数据类型") << tr("数据值") << tr("数据单位")
		<< tr("数据地址") << tr("数据范围");
	data->table->setHorizontalHeaderLabels(header);

	data->label = new QLabel(QString(tr("未命名")));
	data->label->setFixedHeight(20);
	data->label->setStyleSheet("border:1px solid #000000;background:rgb(180, 180, 240)");
	data->label->setAlignment(Qt::AlignCenter);

	layout->addWidget(data->label);
	layout->addWidget(data->table);

	setLayout(layout);
}


table::DataTable::~DataTable()
{
	delete data;
}

void table::DataTable::setTitle(const QString & _text) const
{
	data->label->setText(_text);
}

void table::DataTable::loadConfig(const QString & _path) const
{
	xml::XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	QTableWidgetItem * item = nullptr;
	QCheckBox * box = nullptr;

	int row = 0;
	int column = 0;

	while (!element.isNull())
	{
		data->table->setRowCount(data->table->rowCount() + 1);
		item = new QTableWidgetItem(element.attribute("dataName", tr("未定义")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("variableName", tr("未定义")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataType", tr("未定义")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataValue", tr("未定义")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataUnit", tr("未定义")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataAddress", tr("未定义")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataRange", tr("未定义")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);		
		
		row++;
		column = 0;
		element = element.nextSiblingElement();
	}
}
