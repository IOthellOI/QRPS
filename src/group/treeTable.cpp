#include "treeTable.h"
#include "dataTree.h"
#include "tableGroup.h"

#include <QLayout>

struct group::TreeTable::TreeTableData
{
	tree::DataTree * tree;
	table::TableGroup * table;
};

group::TreeTable::TreeTable(QWidget * _parent) :
	data(new TreeTableData),
	BaseWidget(_parent)
{
	QHBoxLayout * layout = new QHBoxLayout;

	data->tree = new tree::DataTree;
	data->tree->setMaximumWidth(300);
	
	data->table = new table::TableGroup;
	
	layout->addWidget(data->tree);
	layout->addWidget(data->table);

	connect(data->tree, SIGNAL(signalItemChanged(const QString &)),
		data->table, SLOT(slotTableChanged(const QString &)));

	setLayout(layout);
}

group::TreeTable::~TreeTable()
{
}

void group::TreeTable::loadConfig(const QString & _path) const
{	
	QString treePath;
	QString tablePath;
	QString::const_iterator i = _path.cbegin();
	for (; *i != ','; i++)
	{
		treePath.push_back(*i);
	}
	for (i++; i != _path.cend(); i++)
	{
		tablePath.push_back(*i);
	}
	data->tree->loadConfig(treePath);
	data->table->loadConfig(tablePath);
}
