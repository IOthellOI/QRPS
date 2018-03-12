#include "lineEdit.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>

struct edit::LineEdit::LineEditData
{
	QLabel * label;
	QLineEdit * edit;
};

edit::LineEdit::LineEdit(QWidget * _parent):
	data(new LineEditData),
	BaseWidget(_parent)
{
	QHBoxLayout * layout = new QHBoxLayout;
	layout->setMargin(0);

	data->label = new QLabel("Î´¶¨Òå");

	data->edit = new QLineEdit;
	data->edit->setAlignment(Qt::AlignRight);

	layout->addWidget(data->label);
	layout->addWidget(data->edit);

	setLayout(layout);
}

edit::LineEdit::~LineEdit()
{
	delete data;
}

void edit::LineEdit::setText(const QString & _text) const
{
	data->label->setText(_text);
}

void edit::LineEdit::setValue(const QString & _value) const
{
	data->edit->setText(_value);
}
