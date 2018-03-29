#include "fileTable.h"
#include "xmlRead.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

struct table::FileTable::FileTableData
{
	QTableWidget * table;
	QLabel * label;
};

table::FileTable::FileTable(QWidget * _parent) :
	BaseWidget(_parent),
	data(new FileTableData)
{
	QVBoxLayout * layout = new QVBoxLayout;
	layout->setSpacing(0);

	setMinimumHeight(700);

	data->table = new QTableWidget;
	data->table->setFrameShape(QFrame::NoFrame);
	data->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	data->table->setSelectionBehavior(QAbstractItemView::SelectRows);
	data->table->setColumnCount(7);
	data->table->setRowCount(9);

	QStringList header;
	header << tr("记录名称") << tr("记录时间")
		<< tr("教员") << tr("学员") << tr("飞行科目")
		<< tr("记录时长") << tr("加载选择");

	data->table->setHorizontalHeaderLabels(header);

	QTableWidgetItem * item = nullptr;

	QTableWidgetItem * a = new QTableWidgetItem("100");
	data->table->setItem(0, 0, a);
	QPushButton * button;
	QHBoxLayout * alayout;
	QWidget * widget;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			switch (j)
			{
			case 0:
				item = new QTableWidgetItem(QString("名称%1").arg(QString::number(i + 1)));
				item->setTextAlignment(Qt::AlignCenter);
				data->table->setItem(i, j, item);
				break;
			case 1:
				item = new QTableWidgetItem(QString("2018010%1").arg(QString::number(i + 1)));
				item->setTextAlignment(Qt::AlignCenter);
				data->table->setItem(i, j, item);
				break;
			case 2:
				item = new QTableWidgetItem(QString("教员%1").arg(QString::number(i + 1)));
				item->setTextAlignment(Qt::AlignCenter);
				data->table->setItem(i, j, item);
				break;
			case 3:
				item = new QTableWidgetItem(QString("学员%1").arg(QString::number(i + 1)));
				item->setTextAlignment(Qt::AlignCenter);
				data->table->setItem(i, j, item);
				break;
			case 4:
				item = new QTableWidgetItem(QString("飞行科目%1").arg(QString::number(i + 1)));
				item->setTextAlignment(Qt::AlignCenter);
				data->table->setItem(i, j, item);
				break;
			case 5:
				item = new QTableWidgetItem(QString("%1小时").arg(QString::number(i + 1)));
				item->setTextAlignment(Qt::AlignCenter);
				data->table->setItem(i, j, item);
				break;
			case 6:
				button = new QPushButton("加载");
				alayout = new QHBoxLayout;
				widget = new QWidget;
				widget->setLayout(layout);
				layout->addWidget(button);
				layout->setAlignment(Qt::AlignCenter);
				button->setCheckable(true);
				data->table->setCellWidget(i, j, button);
				connect(button, SIGNAL(clicked()), this, SLOT(slotButtonChecked()));
				break;
			default:
				break;
			}
		}
	}


	data->label = new QLabel(QString(tr("记录数据")));
	data->label->setFixedHeight(20);
	data->label->setStyleSheet("border:1px solid #000000;background:rgb(180, 180, 240)");
	data->label->setAlignment(Qt::AlignCenter);

	layout->addWidget(data->label);
	layout->addWidget(data->table);

	setLayout(layout);
}


table::FileTable::~FileTable()
{
	delete data;
}

void table::FileTable::setTitle(const QString & _text) const
{
	data->label->setText(_text);
}

void table::FileTable::slotButtonChecked()
{
	for (size_t i = 0; i < 9; i++)
	{
		reinterpret_cast<QPushButton *>(data->table->cellWidget(i, 6))->setChecked(false);
		reinterpret_cast<QPushButton *>(sender())->setChecked(true);
	}
}
