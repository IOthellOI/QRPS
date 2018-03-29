#include "widgetFactory.h"
#include "tableGroup.h"
#include "dataTree.h"
#include "clickButton.h"
#include "lineEdit.h"
#include "textLabel.h"
#include "dataSlider.h"
#include "dataCurve.h"
#include "treeTable.h"
#include "fileTable.h"
#include "checkBox.h"
#include "comboBox.h"

base::BaseWidget * base::WidgetFactory::create(const QString & _type)
{
	if (_type.toUpper() == "TREETABLE")
	{
		return new group::TreeTable;
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
	else if (_type.toUpper() == "DATACURVE")
	{
		return new curve::DataCurve;
	}
	else if (_type.toUpper() == "FILETABLE")
	{
		return new table::FileTable;
	}
	else if (_type.toUpper() == "CHECKBOX")
	{
		return new button::CheckBox;
	}
	else if (_type.toUpper() == "COMBOBOX")
	{
		return new button::ComboBox;
	}
	else
	{
		return nullptr;
	}
}
