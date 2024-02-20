//
// Created by John on 2/18/2024.
//

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>
#include <QMap>
#include <JournalEntry.hpp>

#ifndef JOURNALQT_MAINWINDOW_HPP
#define JOURNALQT_MAINWINDOW_HPP


class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;
public slots:
    void createNewEntry();
    void saveEntry(const JournalEntry& entry);
    void loadEntryContent(QListWidgetItem* listItem);
    void initializeEntriesFromFolder();

    void updateTitleLabel(const QString &title);
    void toggleSidebar();

private:
    QListWidget *journalEntries;
    QTextEdit* contentTextEdit;
    QMap<QString, JournalEntry> entryMap;
    QLabel* titleLabel;
    QString journalFolderPath;
    QString imagesFolderPath;
    QString entriesFolderPath;
};

#endif //JOURNALQT_MAINWINDOW_HPP
