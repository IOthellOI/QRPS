//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataSlider
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef DATASLIDER_H
#define DATASLIDER_H

#include "baseWidget.h"

namespace slider
{
	class DataSlider : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataSlider(QWidget * _parent = nullptr);
		virtual ~DataSlider();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(int _value) const;
		virtual void setUnit(const QString & _unit) const;

	public slots:
		void slotSilde(int _value);

	private:
		struct DataSliderData;
		DataSliderData * data;
	};
}

#endif // !DATASLIDER_H