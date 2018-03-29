#include "kernelData.h"

#include <QVariant>

struct data::KernelData::KernelDataData
{
	QString * name;
	QString * descriptor;
	QString * type;
	QVariant * data;
	QString * unit;
	QString * address;
	QString * min;
	QString * max;
};

data::KernelData::KernelData()
{
	
}

data::KernelData::~KernelData()
{

}
