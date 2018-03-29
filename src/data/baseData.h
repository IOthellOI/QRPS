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
#ifndef BASEDATA_H
#define BASEDATA_H

namespace data
{
	class BaseData
	{
	public:
		explicit BaseData();
		virtual ~BaseData();

	private:
		int m_id;
	};
}

#endif // !BASEDATA_H

