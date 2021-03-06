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
#ifndef ORDINARYBUTTON_H
#define ORDINARYBUTTON_H

#include "baseWidget.h"

namespace button
{
	class ClickButton : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit ClickButton(QWidget * _parent = nullptr);
		virtual ~ClickButton();

	public:
		virtual void setText(const QString & _text) const;

	private:
		struct ClickButtonData;
		ClickButtonData * data;
	};
}

#endif // !ORDINARYBUTTON_H