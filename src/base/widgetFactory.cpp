#include "widgetFactory.h"
#include "tableGroup.h"
#include "dataTree.h"
#include "clickButton.h"
#include "lineEdit.h"
#include "textLabel.h"
#include "dataSlider.h"

base::BaseWidget * base::WidgetFactory::create(const QString & _type)
{
	if (_type.toUpper() == "DATATREE")
	{
		return new tree::DataTree;
	}
	else if (_type.toUpper() == "TABLEGROUP")
	{
		return new table::TableGroup;
	}
	else if (_type.toUpper() == "CLICKBUTTON")
	{
		return new button::ClickButton;
	}
	else if (_type.toUpper() == "LINEEDIT")
	{
		return new edit::LineEdit;
	}
	else if (_type.toUpper() == "TEXTLABEL")
	{
		return new label::TextLabel;
	}
	else if (_type.toUpper() == "DATASLIDER")
	{
		return new slider::DataSlider;
	}
	else
	{
		return nullptr;
	}
}
