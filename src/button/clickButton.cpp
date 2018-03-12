#include "clickButton.h"

#include <QPushButton>
#include <QLayout>

struct button::ClickButton::ClickButtonData
{
	QPushButton * button;
	QHBoxLayout * layout;
};

button::ClickButton::ClickButton(QWidget * _parent) :
	BaseWidget(_parent),
	data(new ClickButtonData)
{
	data->button = new QPushButton;
	QSizePolicy sizePolicy = data->button->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->button->setSizePolicy(sizePolicy);

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->button);
	data->layout->setMargin(0);
	setLayout(data->layout);
	
	connect(data->button, SIGNAL(clicked(bool)), this, SLOT(slotClicked(bool)));
}

button::ClickButton::~ClickButton()
{
	delete data;
}

void button::ClickButton::setText(const QString & _text) const
{
	data->button->setText(_text);
}
