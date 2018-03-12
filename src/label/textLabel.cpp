#include "textLabel.h"

#include <QLayout>
#include <QLabel>

struct label::TextLabel::TextLabelData
{
	QLabel * label;
	QHBoxLayout * layout;
};

label::TextLabel::TextLabel(QWidget * _parent) :
	BaseWidget(_parent),
	data(new TextLabelData)
{
	data->label = new QLabel;

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->label);
	data->layout->setMargin(0);

	setLayout(data->layout);
}

label::TextLabel::~TextLabel()
{
	delete data;
}

void label::TextLabel::setText(const QString & _text) const
{
	data->label->setText(_text);
}
