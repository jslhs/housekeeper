#include "housekeeper.h"
#include <QImage>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDir>

housekeeper::housekeeper(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.view->setParent(nullptr);
	ui.scrollArea->setWidget(ui.view);
	ui.view->setText("drop folders here.");

	connect(&_fs_watcher, SIGNAL(directoryChanged(const QString&)), this, SLOT(directory_changed(const QString&)));
	connect(&_fs_watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(file_changed(const QString&)));
}

housekeeper::~housekeeper()
{

}

void housekeeper::draw()
{
	int w = ui.scrollArea->geometry().width();
	int h = ui.scrollArea->geometry().height();
	QImage img(w, h, QImage::Format_ARGB32);
}

void housekeeper::watch(const QString& folder)
{
	QDir dir(folder);
	if (!dir.exists()) return;

	if (!_folders.contains(folder))
	{
		_folders[folder] = 0;
		_fs_watcher.addPath(folder);
	}
}

void housekeeper::dragEnterEvent(QDragEnterEvent* ev)
{
	ev->accept();
	auto act = Qt::IgnoreAction;
	for (auto &url : ev->mimeData()->urls())
	{
		QDir dir(url.toLocalFile());
		if (dir.exists())
		{
			act = Qt::LinkAction;
			break;
		}
	}

	ev->setDropAction(act);
}

void housekeeper::dropEvent(QDropEvent* ev)
{
	ev->accept();
	for (auto &url : ev->mimeData()->urls())
	{
		auto &path = url.toLocalFile();
		watch(path);
	}
}

void housekeeper::directory_changed(const QString& path)
{

}

void housekeeper::file_changed(const QString& path)
{

}
