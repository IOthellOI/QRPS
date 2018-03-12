//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataTree
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 12,2018
//////////////////////////////////////////////////
#pragma once
#ifndef DATATREE_H
#define DATATREE_H

#include "baseWidget.h"

#include <QTreeWidget>

namespace tree
{
	class DataTree : public base::BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataTree(QWidget * _parent = nullptr);
		virtual ~DataTree();

	public:
		virtual void setTitle(const QString & _text) const;
		virtual void loadConfig(const QString & _path) const;

	private slots:
		void slotItemClicked(QTreeWidgetItem * _item, int _column);

	signals:
		void signalItemChanged(const QString & _item);

	private:
		struct DataTreeData;
		DataTreeData * data;
	};
}

#endif // !DATATREE_H

