#include "dataCurve.h"
#include "qcustomplot.h"

#include <QPushButton>
#include <QComboBox>
#include <QLayout>
#include <QLabel>

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
	data->curve->xAxis->setLabel(tr("����1"));
	data->curve->yAxis->setLabel(tr("����1"));
	data->curve->yAxis->setRange(0, 1000);
	data->curve->addGraph();
	data->curve->graph(0)->setPen(QPen(Qt::blue));
	data->curve->graph(0)->setName("����1");

	for (double i = 0; i < 5; i += 0.1)
	{
		data->curve->graph(0)->addData(i, i * 200);
	}


	QPushButton * button1 = new QPushButton(tr("����"));
	QPushButton * button2 = new QPushButton(tr("��ͣ"));
	QPushButton * button3 = new QPushButton(tr("�Ŵ�"));
	QPushButton * button4 = new QPushButton(tr("��С"));
	QPushButton * button5 = new QPushButton(tr("��λ"));
	button1->setFixedHeight(50);
	button2->setFixedHeight(50);
	button3->setFixedHeight(50);
	button4->setFixedHeight(50);
	button5->setFixedHeight(50);

	QLabel * xLabel = new QLabel("x��:");
	xLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	QLabel * yLabel = new QLabel("y��:");
	yLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	QComboBox * xCombo = new QComboBox;
	xCombo->addItem(tr("����1"));
	xCombo->addItem(tr("����2"));
	xCombo->addItem(tr("����3"));
	xCombo->addItem(tr("����4"));
	xCombo->addItem(tr("����5"));
	xCombo->addItem(tr("����6"));

	QComboBox * yCombo = new QComboBox;
	yCombo->addItem(tr("����1"));
	yCombo->addItem(tr("����2"));
	yCombo->addItem(tr("����3"));
	yCombo->addItem(tr("����4"));
	yCombo->addItem(tr("����5"));
	yCombo->addItem(tr("����6"));

	layout->addWidget(data->curve, 0, 0, 5, 6);
	layout->addWidget(xLabel, 5, 0, 1, 1);
	layout->addWidget(xCombo, 5, 1, 1, 2);
	layout->addWidget(yLabel, 5, 3, 1, 1);
	layout->addWidget(yCombo, 5, 4, 1, 2);
	layout->addWidget(button1, 0, 6, 1, 1);
	layout->addWidget(button2, 1, 6, 1, 1);
	layout->addWidget(button3, 2, 6, 1, 1);
	layout->addWidget(button4, 3, 6, 1, 1);
	layout->addWidget(button5, 4, 6, 1, 1);

	setLayout(layout);
}

curve::DataCurve::~DataCurve()
{
	delete data;
}
