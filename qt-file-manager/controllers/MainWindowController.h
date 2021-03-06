#pragma once
#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QObject>

#include "views/RootItem.h"

class MainWindow;
class FileOperationData;
class AsyncFileOperation;
class FileOperationItem;
class DirController;
class DockController;
class WorkspaceController;
class Breadcrumb;

class MainWindowController : public QObject
{
    Q_OBJECT
public:
    static MainWindowController *instance(const QString &initial_path =
                                            QString());
    explicit MainWindowController(const QString &initial_path);
    ~MainWindowController();
    AsyncFileOperation *async_file_op;
    QHash<const FileOperationData *, FileOperationItem *> *file_ops;
    MainWindow *view;
    bool is_showing_drives() const;
    void mark_path_as_important(const QString &path);
    
signals:
    
public slots:

private slots:
    void layout_button_clicked();
    void breadcrumb_clicked();
    void breadcrumb_path_changed(const QString &path);
    void dir_ctrl_path_changed(const QString &path);
    void dir_search_started(const QString &str);
    void location_edit_focused(bool focused);
    void location_edit_changed();
    void search_text_edited(const QString &text);
    void search_timeout();
    void file_op_progressed(FileOperationData *data);
    void file_op_done(FileOperationData *data);

private:
    RootItem::Layout m_layout;
    static MainWindowController *m_instance;
    QTimer m_search_timer;
    QString m_search_buf;
    DirController *m_dir_ctrl;
    DockController *m_dock_ctrl;
    WorkspaceController *m_workspace_ctrl;
    Breadcrumb *m_breadcrumb_ctrl;
};

#endif // MAINWINDOWCONTROLLER_H
