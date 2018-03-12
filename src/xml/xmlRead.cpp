#include "xmlRead.h"

#include <QFile>

struct xml::XmlRead::XmlReadData
{
	QFile * file;
	QDomDocument * document;
	QDomElement * element;
};

xml::XmlRead::XmlRead() : 
	data(new XmlReadData)
{
	//empty
}

xml::XmlRead::~XmlRead()
{
	delete data;
}

bool xml::XmlRead::loadFile(const QString & _path)
{
	if (_path.isEmpty())
	{
		return false;
	}
	else
	{
		data->file = new QFile(_path);
	}

	if (data->file == nullptr)
	{
		return false;
	}
	else
	{
		data->file->open(QFile::ReadOnly);
	}

	data->document = new QDomDocument;

	if (!data->document->setContent(data->file))
	{
		return false;
	}

	data->element = new QDomElement;
	*data->element = data->document->documentElement();
	
	return true;
}

QDomElement xml::XmlRead::rootElement()
{
	return *data->element;
}
