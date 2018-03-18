//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   KernelData
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 13,2018
//////////////////////////////////////////////////
#pragma once
#ifndef KERNELDATA_H
#define KERNELDATA_H

#include <QObject>

namespace data
{
	class KernelData : public QObject
	{
	public:
		explicit KernelData();
		virtual ~KernelData();

	private:
		struct KernelDataData;
		KernelDataData * data;
	};
}

#endif // !KERNELDATA_H

