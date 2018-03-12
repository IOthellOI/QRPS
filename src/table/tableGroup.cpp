#include "tableGroup.h"
#include "dataTable.h"
#include "xmlRead.h"

#include <QStackedWidget>
#include <QLayout>

struct table::TableGroup::TableGroupData
{
	QStackedWidget * stack;
};

table::TableGroup::TableGroup(QWidget * _parent) :
	BaseWidget(_parent),
	data(new TableGroupData)
{
	data->stack = new QStackedWidget;

	QVBoxLayout * layout = new QVBoxLayout;
	layout->setMargin(0);
	layout->addWidget(data->stack);

	setLayout(layout);
}

table::TableGroup::~TableGroup()
{
}

void table::TableGroup::loadConfig(const QString & _path) const
{
	xml::XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}
	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	DataTable * table = nullptr;

	while (!element.isNull())
	{
		table = new DataTable;
		table->setTitle(element.attribute("title",tr("Î´ÃüÃû")));
		table->setName(element.attribute("name"));
		table->loadConfig(element.attribute("path"));
		
		data->stack->addWidget(table);

		element = element.nextSiblingElement();
	}
}

void table::TableGroup::slotTableChanged(const QString & _table)
{
	for (size_t i = 0; i < data->stack->count(); i++)
	{
		if (dynamic_cast<DataTable *>(data->stack->widget(i))->name() == _table)
		{
			data->stack->setCurrentIndex(i);
			break;
		}
	}
}
