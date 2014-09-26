#ifndef HOUSEKEEPER_H
#define HOUSEKEEPER_H

#include <QtWidgets/QMainWindow>
#include "ui_housekeeper.h"
#include <QFileSystemWatcher>

class housekeeper : public QMainWindow
{
	Q_OBJECT

public:
	housekeeper(QWidget *parent = 0);
	~housekeeper();

public slots:
	void directory_changed(const QString& path);
	void file_changed(const QString& path);

protected:
	void dragEnterEvent(QDragEnterEvent* ev) override;
	void dropEvent(QDropEvent* ev) override;

private:
	void draw();
	void watch(const QString& folder);

private:
	Ui::housekeeperClass ui;
	QMap<QString, int> _folders;
	QFileSystemWatcher _fs_watcher;
};

#endif // HOUSEKEEPER_H
