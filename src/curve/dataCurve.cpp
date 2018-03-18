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
	setMinimumHeight(334);

	QHBoxLayout * layout = new QHBoxLayout;
	layout->setMargin(0);

	data->curve = new QCustomPlot;

	data->curve->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	data->curve->xAxis->setLabel(tr("数据1"));
	data->curve->yAxis->setLabel(tr("数据1"));
	data->curve->yAxis->setRange(0, 1000);
	data->curve->addGraph();
	data->curve->graph(0)->setPen(QPen(Qt::blue));
	data->curve->graph(0)->setName("数据1");

	for (double i = 0; i < 5; i += 0.1)
	{
		data->curve->graph(0)->addData(i, i * 200);
	}

	layout->addWidget(data->curve);
	setLayout(layout);
}

curve::DataCurve::~DataCurve()
{
	delete data;
}
