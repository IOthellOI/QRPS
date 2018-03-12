#include "baseWidget.h"

#include <typeinfo>
#include <QString>

base::BaseWidget::BaseWidget(QWidget * _parent) :
	QWidget(_parent)
{
	m_ident = -1;
	m_name = "";
}

base::BaseWidget::~BaseWidget()
{
}

void base::BaseWidget::setTitle(const QString &) const
{
}

void base::BaseWidget::setText(const QString &) const
{
}

void base::BaseWidget::setChecked(bool) const
{
}

void base::BaseWidget::setState(int) const
{
}

void base::BaseWidget::setValue(int) const
{
}

void base::BaseWidget::setValue(double) const
{
}

void base::BaseWidget::setValue(const QString &) const
{
}

void base::BaseWidget::setUnit(const QString &) const
{
}

void base::BaseWidget::loadConfig(const QString &) const
{
}

void base::BaseWidget::setImage(const QImage &) const
{
}

void base::BaseWidget::setIcon(const QIcon &) const
{
}

void base::BaseWidget::setGroup(int) const
{
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
	m_name = _name;
}

const QString & base::BaseWidget::name() const
{
	return m_name;
}
