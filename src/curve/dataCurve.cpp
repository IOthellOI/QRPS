#include "dataCurve.h"
#include "qcustomplot.h"

#include <QPushButton>
#include <QComboBox>
#include <QLayout>

struct curve::DataCurve::DataCurveData
{
	QCustomPlot * curve;
};

curve::DataCurve::DataCurve(QWidget * _parent):
	data(new DataCurveData),
	BaseWidget(_parent)
{
	QGridLayout * layout = new QGridLayout;

	data->curve = new QCustomPlot;
	QPushButton * button1 = new QPushButton(tr("绘制"));
	QPushButton * button2 = new QPushButton(tr("暂停"));
	QPushButton * button3 = new QPushButton(tr("放大"));
	QPushButton * button4 = new QPushButton(tr("缩小"));
	QPushButton * button5 = new QPushButton(tr("复位"));
	button1->setFixedHeight(50);
	button2->setFixedHeight(50);
	button3->setFixedHeight(50);
	button4->setFixedHeight(50);
	button5->setFixedHeight(50);

	QComboBox * combo = new QComboBox;
	combo->addItem(tr("数据1"));
	combo->addItem(tr("数据2"));
	combo->addItem(tr("数据3"));
	combo->addItem(tr("数据4"));
	combo->addItem(tr("数据5"));
	combo->addItem(tr("数据6"));

	layout->addWidget(data->curve, 0, 0, 4, 4);
	layout->addWidget(combo, 4, 0, 1, 4);
	layout->addWidget(button1, 0, 4, 1, 1);
	layout->addWidget(button2, 1, 4, 1, 1);
	layout->addWidget(button3, 2, 4, 1, 1);
	layout->addWidget(button4, 3, 4, 1, 1);
	layout->addWidget(button5, 4, 4, 1, 1);

	setLayout(layout);
}

curve::DataCurve::~DataCurve()
{
	delete data;
}
