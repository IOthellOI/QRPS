#include "dataTree.h"
#include "xmlRead.h"

#include <QLayout>
#include <QLabel>
#include <QMap>

struct tree::DataTree::DataTreeData
{
	QTreeWidget * tree;
	QLabel * label;
	QMap<QTreeWidgetItem *, QString> * map;
};

tree::DataTree::DataTree(QWidget * _parent) :
	BaseWidget(_parent),
	data(new DataTreeData)
{
	QVBoxLayout * layout = new QVBoxLayout;
	layout->setSpacing(0);

	data->label = new QLabel(tr("数据列表"));
	data->label->setStyleSheet("border:1px solid #000000;background:rgb(180, 180, 240)");
	data->label->setFixedHeight(20);
	data->label->setAlignment(Qt::AlignCenter);

	data->tree = new QTreeWidget;
	data->tree->setHeaderHidden(true);

	layout->addWidget(data->label);
	layout->addWidget(data->tree);

	data->map = new QMap<QTreeWidgetItem *, QString>;

	connect(data->tree, SIGNAL(itemClicked(QTreeWidgetItem *, int)),
		this, SLOT(slotItemClicked(QTreeWidgetItem *, int)));

	setLayout(layout);
}

tree::DataTree::~DataTree()
{
	delete data;
}

void tree::DataTree::setTitle(const QString & _text) const
{
	data->label->setText(_text);
}

void tree::DataTree::loadConfig(const QString & _path) const
{
	xml::XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	QTreeWidgetItem * oneLevelItem;
	QTreeWidgetItem * twoLevelItem;
	
	while (!element.isNull())
	{
		oneLevelItem = new QTreeWidgetItem(data->tree,
			QStringList(element.attribute("text", tr("未定义"))));

		QDomElement node = element.firstChildElement();
		while (!node.isNull())
		{
			twoLevelItem = new QTreeWidgetItem(oneLevelItem,
				QStringList(node.attribute("text", tr("未定义"))));
			
			data->map->insert(twoLevelItem, node.attribute("bind"));

			node = node.nextSiblingElement();
		}
		element = element.nextSiblingElement();
	}
}

void tree::DataTree::slotItemClicked(QTreeWidgetItem * _item, int)
{
	if (!data->map->value(_item).isEmpty())
	{
		emit signalItemChanged(data->map->value(_item));
	}
}
