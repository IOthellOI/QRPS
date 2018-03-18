//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   LogicalData
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 13,2018
//////////////////////////////////////////////////
#pragma once
#ifndef LOGICALDATA_H
#define LOGICALDATA_H

#include <QObject>

namespace data
{
	class LogicalData : public QObject
	{
	public:
		explicit LogicalData();
		virtual ~LogicalData();

	private:
		struct LogicalDataData;
		LogicalDataData * data;
	};
}

#endif // !LOGICALDATA_H

