//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   TextLabel
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "baseWidget.h"

namespace label
{
	class TextLabel : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit TextLabel(QWidget * _parent = nullptr);
		virtual ~TextLabel();

	public:
		virtual void setText(const QString & _text) const;

	private:
		struct TextLabelData;
		TextLabelData * data;
	};
}

#endif // !TEXTLABEL_H 