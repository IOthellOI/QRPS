#include "baseWidget.h"

#include <typeinfo>
#include <QString>

base::BaseWidget::BaseWidget(QWidget * _parent) :
	QWidget(_parent)
{
	m_ident = -1;
	setStyleSheet("border-image: url();");
}

base::BaseWidget::~BaseWidget()
{
	//empty
}

void base::BaseWidget::setText(const QString &) const
{
	//empty
}

void base::BaseWidget::setChecked(bool) const
{
	//empty
}

void base::BaseWidget::setState(int) const
{
	//empty
}

void base::BaseWidget::setValue(int) const
{
	//empty
}

void base::BaseWidget::setValue(double) const
{
	//empty
}

void base::BaseWidget::setUnit(const QString &) const
{
	//empty
}

void base::BaseWidget::loadConfig(const QString &) const
{
	//empty
}

void base::BaseWidget::setImage(const QImage &) const
{
	//empty
}

void base::BaseWidget::setIcon(const QIcon &) const
{
	//empty
}

void base::BaseWidget::setGroup(int) const
{
	//empty
}

void base::BaseWidget::setIdent(int _ident)
{
	m_ident = _ident;
}

int base::BaseWidget::ident() const
{
	return m_ident;
}

void base::BaseWidget::setName(const QString & _name)
{
	setObjectName(_name);
}

const QString & base::BaseWidget::name() const
{
	return objectName();
}
