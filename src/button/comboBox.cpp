#include "comboBox.h"

#include <QComboBox>
#include <QLabel>
#include <QLayout>

struct button::ComboBox::ComboBoxData
{
	QLabel * label;
	QComboBox * button;
};

button::ComboBox::ComboBox(QWidget * _parent) :
	data(new ComboBoxData)
{
	QHBoxLayout * layout = new QHBoxLayout;
	layout->setMargin(0);
	
	data->label = new QLabel(tr("Î´ÃüÃû"));
	data->label->setFixedWidth(30);
	
	data->button = new QComboBox;
	
	layout->addWidget(data->label);
	layout->addWidget(data->button);

	setLayout(layout);
}

button::ComboBox::~ComboBox()
{

}

void button::ComboBox::setText(const QString & _text) const
{
	data->label->setText(_text);
}

void button::ComboBox::setValue(const QString & _value) const
{
	data->button->addItem(QString(_value) + ("1"));
	data->button->addItem(QString(_value) + ("2"));
	data->button->addItem(QString(_value) + ("3"));
	data->button->addItem(QString(_value) + ("4"));
}
