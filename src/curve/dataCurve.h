//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataCurve
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef DATACURVE_H
#define DATACURVE_H

#include "baseWidget.h"

namespace curve
{
	class DataCurve : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataCurve(QWidget * _parent = nullptr);
		virtual ~DataCurve();

	private:
		struct DataCurveData;
		DataCurveData * data;
	};
}

#endif // !DATACURVE_H
