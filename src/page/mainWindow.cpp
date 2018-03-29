#include "mainWindow.h"
#include "navigation.h"
#include "mainPage.h"
#include "status.h"

#include <QLayout>

struct page::MainWindow::MainWindowData
{
	Navigation * navigation;
	MainPage * mainPage;
	Status * status;
};

page::MainWindow::MainWindow(QWidget * _parent):
	BaseWidget(_parent),
	data(new MainWindowData)
{
	data->navigation = new Navigation;
	data->mainPage = new MainPage;
	data->status = new Status;

	data->navigation->loadConfig("./data/page/navigation.xml");
	data->mainPage->loadConfig("./data/page/mainPage.xml");

	QVBoxLayout * vlayout = new QVBoxLayout;
	QHBoxLayout * layout = new QHBoxLayout;

	layout->setMargin(2);
	layout->setSpacing(2);

	layout->addWidget(data->navigation);
	layout->addWidget(data->mainPage);

	vlayout->addLayout(layout);
	vlayout->addWidget(data->status);

	setLayout(vlayout);

	//setWindowFlags(Qt::FramelessWindowHint);
	setFixedWidth(1440);
	setFixedHeight(900);

	connect(data->navigation,
		SIGNAL(signalPageChanged(const QString &)),
		data->mainPage,
		SLOT(slotPageChanged(const QString &)));
}

page::MainWindow::~MainWindow()
{
	delete data;
}
