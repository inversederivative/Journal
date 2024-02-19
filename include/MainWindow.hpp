//
// Created by John on 2/18/2024.
//

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>

#ifndef JOURNALQT_MAINWINDOW_HPP
#define JOURNALQT_MAINWINDOW_HPP

class JournalEntry {
private:
    QString title;
    QString content;

public:
    QString getTitle()
    {
        return title;
    }

    void setTitle(const QString& titleString)
    {
        title = titleString;
    }

    QString getContent()
    {
        return content;
    }

    void setContent(const QString& contentString)
    {
        content = contentString;
    }
};

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;
public slots:
    void createNewEntry();
    void saveEntry();
    void loadEntryContent(QListWidgetItem* listItem);
    void populateEntriesFromFolder();

    void updateTitleLabel(const QString &title);
    void toggleSidebar();
private:
    QListWidget *journalEntries;
    QTextEdit* contentTextEdit;
    JournalEntry currentEntry;
    QLabel* titleLabel;
    QString journalFolderPath;
    QString imagesFolderPath;
    QString entriesFolderPath;
};



#endif //JOURNALQT_MAINWINDOW_HPP
