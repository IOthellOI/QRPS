#include "dataSlider.h"

#include <QLayout>
#include <QSlider>
#include <QLabel>

struct slider::DataSlider::DataSliderData
{
	QLabel * name;
	QLabel * value;
	QLabel * unit;
	QSlider * slider;
	QHBoxLayout * layout;
};

slider::DataSlider::DataSlider(QWidget * _parent) :
	BaseWidget(_parent),
	data(new DataSliderData)
{
	data->slider = new QSlider;
	data->slider->setOrientation(Qt::Horizontal);

	data->name = new QLabel;
	data->value = new QLabel;
	data->unit = new QLabel;

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->name);
	data->layout->addWidget(data->slider);
	data->layout->addWidget(data->value);
	data->layout->addWidget(data->unit);
	data->layout->setMargin(0);

	setLayout(data->layout);
	connect(data->slider, SIGNAL(valueChanged(int)), this, SLOT(slotSilde(int)));
}

slider::DataSlider::~DataSlider()
{
	delete data;
}

void slider::DataSlider::setText(const QString & _text) const
{
	data->name->setText(_text);
}

void slider::DataSlider::setValue(int _value) const
{
	data->value->setText(QString::number(_value));
}
	
void slider::DataSlider::setUnit(const QString & _unit) const
{
	data->unit->setText(_unit);
}

void slider::DataSlider::slotSilde(int _value)
{
	data->value->setText(QString::number(_value));
}