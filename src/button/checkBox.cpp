#include "checkBox.h"

#include <QCheckBox>
#include <QLayout>

struct button::CheckBox::CheckBoxData
{
	QCheckBox * button;
};

button::CheckBox::CheckBox(QWidget * _parent):
	data(new CheckBoxData),
	BaseWidget(_parent)
{
	QVBoxLayout * layout = new QVBoxLayout;

	data->button = new QCheckBox;

	layout->addWidget(data->button);

	setLayout(layout);
	
}

button::CheckBox::~CheckBox()
{
	delete data;
}

void button::CheckBox::setText(const QString & _text) const
{
	data->button->setText(_text);
}

void button::CheckBox::setChecked(bool _checked) const
{
	data->button->setChecked(_checked);
}
