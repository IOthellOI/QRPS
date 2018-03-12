#include "dataTable.h"
#include "xmlRead.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QLayout>
#include <QLabel>

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
	layout->setSpacing(10);

	data->table = new QTableWidget;
	data->table->setFrameShape(QFrame::NoFrame);
	data->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	data->table->setColumnCount(7);

	QStringList header;
	header << tr("��������") << tr("��������") 
		<< tr("��������") << tr("����ֵ") << tr("���ݵ�λ")
		<< tr("���ݵ�ַ") << tr("���ݷ�Χ");
	data->table->setHorizontalHeaderLabels(header);

	data->label = new QLabel(QString(tr("δ����")));
	data->label->setFixedHeight(20);
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

	int row = 0;
	int column = 0;

	while (!element.isNull())
	{
		data->table->setRowCount(data->table->rowCount() + 1);
		item = new QTableWidgetItem(element.attribute("dataName", tr("δ����")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("variableName", tr("δ����")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataType", tr("δ����")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataValue", tr("δ����")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataUnit", tr("δ����")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataAddress", tr("δ����")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);

		item = new QTableWidgetItem(element.attribute("dataRange", tr("δ����")));
		item->setTextAlignment(Qt::AlignCenter);
		data->table->setItem(row, column++, item);
		
		row++;
		column = 0;
		element = element.nextSiblingElement();
	}
}
