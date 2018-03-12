//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   TableGroup
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef TABLEGROUP_H
#define TABLEGROUP_H

#include "baseWidget.h"

namespace table
{
	class TableGroup : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit TableGroup(QWidget * _parent = nullptr);
		virtual ~TableGroup();
	
	public:
		virtual void loadConfig(const QString & _path) const;

	public slots:
		void slotTableChanged(const QString & _table);

	private:
		struct TableGroupData;
		TableGroupData * data;
	};
}

#endif // !TABLEGROUP_H

