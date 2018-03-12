#include "page.h"
#include "xmlRead.h"
#include "widgetFactory.h"
#include "dataTree.h"
#include "tableGroup.h"

#include <QLayout>
#include <QGroupBox>
#include <QVariant>

struct page::Page::PageData
{
	QGridLayout * layout;
};

page::Page::Page(QWidget * _parent) :
	BaseWidget(_parent),
	data(new PageData)
{
	data->layout = new QGridLayout;

	setLayout(data->layout);
}

page::Page::~Page()
{
	delete data;
}

void page::Page::loadConfig(const QString & _path) const
{
	xml::XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}

	QDomElement root = xmlRead.rootElement();
	
	QDomElement component = root.firstChildElement();
	QGroupBox * box = nullptr;
	QGridLayout * layout = nullptr;
	BaseWidget * widget = nullptr;
	while (!component.isNull())
	{
		box = new QGroupBox;
		box->setTitle(component.attribute("title"));

		layout = new QGridLayout;
		box->setLayout(layout);

		data->layout->addWidget(box, 
			component.attribute("row").toInt(), 
			component.attribute("column").toInt(), 
			component.attribute("rowSpan").toInt(),
			component.attribute("columnSpan").toInt());

		QDomElement element = component.firstChildElement();
		
		tree::DataTree * tree = nullptr;
		table::TableGroup * group = nullptr;

		while (!element.isNull())
		{
			widget = base::WidgetFactory::create(element.attribute("type"));

			if (widget == nullptr)
			{
				element = element.nextSiblingElement();
				continue;
			}

			if (element.hasAttribute("width"))
			{
				widget->setFixedWidth(element.attribute("width").toInt());
			}	
			if (element.hasAttribute("height"))
			{
				widget->setFixedHeight(element.attribute("height").toInt());
			}
			if (element.hasAttribute("title"))
			{
				widget->setTitle(element.attribute("title"));
			}
			if (element.hasAttribute("text"))
			{
				widget->setText(element.attribute("text"));
			}
			if (element.hasAttribute("value"))
			{
				widget->setValue(element.attribute("value"));
			}
			if (element.hasAttribute("path"))
			{
				widget->loadConfig(element.attribute("path"));
			}

			layout->addWidget(widget,
				element.attribute("row").toInt(),
				element.attribute("column").toInt(),
				element.attribute("rowSpan").toInt(),
				element.attribute("columnSpan").toInt());

			if (typeid(widget).name() == typeid(tree::DataTree *).name())
			{
				tree = reinterpret_cast<tree::DataTree *>(widget);
			}
			if (typeid(widget).name() == typeid(table::TableGroup *).name())
			{
				group = reinterpret_cast<table::TableGroup *>(widget);
			}
			if (tree != nullptr && group != nullptr)
			{
				connect(tree, SIGNAL(signalItemChanged(const QString &)),
					group, SLOT(slotTableChanged(const QString &)));
			}

			element = element.nextSiblingElement();
		}

		component = component.nextSiblingElement();
	}
}


