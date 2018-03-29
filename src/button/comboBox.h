//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ClickButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 18,2018
//////////////////////////////////////////////////
#pragma once
#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "baseWidget.h"

namespace button
{
	class ComboBox : public base::BaseWidget
	{
	public:
		explicit ComboBox(QWidget * _parent = nullptr);
		virtual ~ComboBox();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(const QString & _value) const;

	private:
		struct ComboBoxData;
		ComboBoxData * data;
	};
}
#endif // !COMBOBOX_H

