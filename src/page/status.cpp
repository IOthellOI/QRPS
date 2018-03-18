#include "status.h"

#include <QLayout>
#include <QVariant>
#include <QLabel>

struct page::Status::StatusData
{
	QHBoxLayout * layout;
};

page::Status::Status(QWidget * _parent) :
	BaseWidget(_parent),
	data(new StatusData)
{
	setMaximumHeight(30);
	data->layout = new QHBoxLayout;
	data->layout->setSpacing(20);
	data->layout->setMargin(0);

	QLabel * leftLabel = new QLabel("δִ�в���");
	QLabel * centerLabel = new QLabel("2018��01��01�� 12:00");
	centerLabel->setAlignment(Qt::AlignCenter);
	QLabel * rightLabel = new QLabel("ʣ����̿ռ�: 80%");
	rightLabel->setAlignment(Qt::AlignRight | Qt::AlignHCenter);

	data->layout->addWidget(leftLabel);
	data->layout->addWidget(centerLabel);
	data->layout->addWidget(rightLabel);
	setLayout(data->layout);
}

page::Status::~Status()
{
	delete data;
}
