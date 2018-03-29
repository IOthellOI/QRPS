//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   CheckBox
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "baseWidget.h"

namespace button
{
	class CheckBox : public base::BaseWidget
	{
	public:
		explicit CheckBox(QWidget * _parent = nullptr);
		virtual ~CheckBox();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setChecked(bool _checked) const;

	private:
		struct CheckBoxData;
		CheckBoxData * data;
	};
}

#endif // !CHECKBOX_H