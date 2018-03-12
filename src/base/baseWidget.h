//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   BaseWidget
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 11,2018
//////////////////////////////////////////////////
#pragma once
#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QIcon>

#pragma execution_character_set("utf-8")

namespace base
{
	class BaseWidget : public QWidget
	{
		Q_OBJECT
	public:
		explicit BaseWidget(QWidget * _parent = nullptr);
		virtual ~BaseWidget();

	public:
		virtual void setTitle(const QString & _text) const;
		virtual void setText(const QString & _text) const;
		virtual void setChecked(bool _checked) const;
		virtual void setState(int _state) const;
		virtual void setValue(int _value) const;
		virtual void setValue(double _value) const;
		virtual void setValue(const QString & _value) const;
		virtual void setUnit(const QString & _unit) const;
		virtual void loadConfig(const QString & _path) const;
		virtual void setImage(const QImage & _image) const;;
		virtual void setIcon(const QIcon & _icon) const;
		virtual void setGroup(int _group) const;
		
	public:
		void setIdent(int _ident);
		int ident() const;
		void setName(const QString & _name);
		const QString & name()const;

	private:
		int m_ident;
		QString m_name;
	};
}

#endif // !BASEWIDGET_H