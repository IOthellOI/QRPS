#include "navigationButton.h"

#include <QPushButton>
#include <QToolButton>
#include <QButtonGroup>
#include <QLayout>

struct button::NavigationButton::NavigationButtonData
{
	QToolButton * button;
	QHBoxLayout * layout;
	QString * bindPage;
	static QButtonGroup * buttonGroup;
};

QButtonGroup * button::NavigationButton::NavigationButtonData::buttonGroup = new QButtonGroup;

button::NavigationButton::NavigationButton(QWidget * _parent) :
	BaseWidget(_parent),
	data(new NavigationButtonData)
{
	data->button = new QToolButton;
	data->button->setObjectName("NavigationButton");
	QSizePolicy sizePolicy = data->button->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->button->setSizePolicy(sizePolicy);
	data->button->setCheckable(true);

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->button);
	data->layout->setMargin(0);
	setLayout(data->layout);

	data->bindPage = new QString;

	data->buttonGroup->addButton(data->button);

	connect(data->button, SIGNAL(clicked(bool)), this, SLOT(slotClicked(bool)));
}

button::NavigationButton::~NavigationButton()
{
	delete data;
}

void button::NavigationButton::setText(const QString & _text) const
{
	data->button->setText(_text);
}

void button::NavigationButton::setIcon(const QIcon & _icon) const
{
	data->button->setIcon(QIcon(_icon));
	QSize size(100, 100);
	data->button->setIconSize(size);
}

void button::NavigationButton::setChecked(bool _checked) const
{
	data->button->setChecked(_checked);
}

void button::NavigationButton::setBindPage(const QString & _page) const
{
	*data->bindPage = _page;
}

void button::NavigationButton::slotClicked(bool _clicked)
{
	if (_clicked)
	{
		emit signalClicked(*this->data->bindPage);
	}
	else
	{
		setChecked(true);
	}
}
