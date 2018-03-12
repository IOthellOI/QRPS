//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ClickButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "baseWidget.h"

namespace edit
{
	class LineEdit : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit LineEdit(QWidget * _parent = nullptr);
		virtual ~LineEdit();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(const QString & _value) const;

	private:
		struct LineEditData;
		LineEditData * data;
	};
}


#endif // !LINEEDIT_H


