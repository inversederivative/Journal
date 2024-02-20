//
// Created by John on 2/18/2024.
//
#include <MainWindow.hpp>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QStandardPaths>


/*
 * TODO: Very first entry is still being deleted.
 * There's a JournalEntry bug, where the map is set to "", and after we save the JSON, the map value for the
 * very first entry is not being populated.
 */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    /// Create Folders
    journalFolderPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir journalDir(journalFolderPath);
    if (!journalDir.exists()) {
        // Create the Journal folder
        journalDir.mkpath(".");
    }

    // Check if the images folder exists
    imagesFolderPath = journalFolderPath + "/images";
    QDir imagesDir(imagesFolderPath);
    if (!imagesDir.exists()) {
        // Create the images folder
        imagesDir.mkpath(".");
    }

    // Move the pictures:
#ifdef Linux
    QString sourceFile1 = "/usr/share/Journal/images/hamburger.png";
    QString sourceFile2 = "/usr/share/Journal/images/icon.png";

    QString destFile1 = imagesFolderPath + "/hamburger.png";
    QString destFile2 = imagesFolderPath + "/icon.png";

    // Perform the file move operation
    if (QFile::copy(sourceFile1, destFile1) && QFile::copy(sourceFile2, destFile2)) {
        qDebug() << "Files successfully moved to" << imagesFolderPath;
    } else {
        qWarning() << "Failed to move files";
    }
#endif

    // Check if the entries folder exists
    entriesFolderPath = journalFolderPath + "/entries";
    QDir entriesDir(entriesFolderPath);
    if (!entriesDir.exists()) {
        // Create the entries folder
        entriesDir.mkpath(".");
    }

    // Create main window
    setWindowTitle("Journal");
    resize(800, 600);

    QIcon appIcon(imagesFolderPath + "/icon.png");
    setWindowIcon(appIcon);

    // Create central widget and layout for main window
    auto centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create layout for main window
    auto mainLayout = new QVBoxLayout(centralWidget);


    // Create top bar layout
    auto topBarLayout = new QHBoxLayout();

    // Create the hamburger button
    auto  collapseButton = new QPushButton(this);
    QIcon buttonIcon(imagesFolderPath + "/hamburger.png");
    collapseButton->setIcon(buttonIcon);
    collapseButton->setFixedSize(30, 30); // Set the size of the button
    collapseButton->setStyleSheet("QPushButton { border: none; }"); // Remove the button border
    topBarLayout->addWidget(collapseButton);

    // Add horizontal spacer to push the button to the right
    topBarLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    // Add top bar layout to main layout
    mainLayout->addLayout(topBarLayout);

    // Create a QHBoxLayout for the journal widgets
    auto journalLayout = new QHBoxLayout();

    // Sidebar with journal entries
    journalEntries = new QListWidget();
    journalEntries->setFixedWidth(200);
    journalEntries->setStyleSheet("QListWidget { border: none; }");
    journalLayout->addWidget(journalEntries);

    // Journal page area
    auto journalPageWidget = new QWidget();
    auto journalPageLayout = new QVBoxLayout(journalPageWidget);
    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    contentTextEdit = new QTextEdit();
    contentTextEdit->setStyleSheet("QTextEdit { border: none; }");
    journalPageLayout->addWidget(titleLabel);
    journalPageLayout->addWidget(contentTextEdit);
    journalLayout->addWidget(journalPageWidget);

    // Add the journal layout to the main layout
    mainLayout->addLayout(journalLayout);

    // Create and add menu bar
    QMenuBar *menuBar = this->menuBar();

    menuBar->setStyleSheet("QMenuBar { background-color: rgb(30, 30, 30); color: white; } "
                           "QMenuBar::item:selected { background-color: rgb(0, 120, 212); } "
                           "QMenu { background-color: rgb(53, 53, 53); color: white; border: none; } "
                           "QMenu::item:selected { background-color: rgb(42, 130, 218); color: black; }");


    QMenu *fileMenu = menuBar->addMenu("&File");

    QAction *newEntryAction = fileMenu->addAction("&New Entry");
    QAction* saveAction = fileMenu->addAction("&Save Entry");
    QAction* exitAction = fileMenu->addAction("&Exit");

    // Connect them to their handler functions
    connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
    connect(saveAction, &QAction::triggered, this, [this]() {
        // Retrieve the current entry title from the title label
        QString currentEntryTitle = titleLabel->text();

        // Check if the title exists in the entry map
        if (entryMap.contains(currentEntryTitle)) {
            // Retrieve the JournalEntry from the map
            JournalEntry entry = entryMap.value(currentEntryTitle);
            entry.setContent(contentTextEdit->toPlainText());

            // Call the saveEntry function with the retrieved JournalEntry
            saveEntry(entry);
        } else {
            qDebug() << "Error: Current entry not found in the map.";
        }
    });
    connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);

    // Connect the collapseButton to its handler function
    connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);

    // Change the behavior of the journal entries, when clicked on
    connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);

    QMenu *editMenu = menuBar->addMenu("&Edit");
    // Add edit actions as needed...

    // Cut, Copy, Duplicate, Paste
    editMenu->addAction("&Cut");
    editMenu->addAction("&Copy");
    editMenu->addAction("&Duplicate");
    editMenu->addAction("&Paste");

    initializeEntriesFromFolder();
}

void MainWindow::initializeEntriesFromFolder() {
    // Check if the folder exists
    QDir entriesDir(entriesFolderPath);
    if (!entriesDir.exists()) {
        return; // If the folder doesn't exist, there are no entries to populate
    }

    // Get the list of files in the "entries" folder
    QStringList entryFiles = entriesDir.entryList(QDir::Files);

    // Iterate over the list of entry files
    for (const QString &entryFile : entryFiles) {
        // Construct the file path for the JSON file
        QString jsonFilePath = entriesFolderPath + "/" + entryFile;

        // Read the JSON data from the file
        QFile file(jsonFilePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QString jsonData = file.readAll();
            file.close();

            // Create a new JournalEntry object and initialize it from the JSON data
            JournalEntry entry;
            entry = entry.fromJson(jsonData);

            // Add the entry to the entry map
            QString entryTitle = entry.getTitle();
            entryMap.insert(entryTitle, entry);

            // Add the entry title to the journalEntries list widget
            journalEntries->addItem(entryTitle);
        }
    }
}

void MainWindow::createNewEntry() {
    // Prompt the user to enter a title for the new entry
    //QString entryTitle = QInputDialog::getText(this, "New Entry", "Enter a title for the new entry:");

    /////////// Set Style for Dialog Box ////////////
    // Create an instance of QInputDialog
    QInputDialog dialog(this);

    // Set up the input dialog
    dialog.setWindowTitle("New Entry");
    dialog.setLabelText("Enter a title for the new entry:");

    // Apply style sheet to the input dialog
    dialog.setStyleSheet("QInputDialog { background-color: rgb(30, 30, 30); color: white; }"
                         "QLineEdit { background-color: rgb(53, 53, 53); color: white; border: none; }"
                         "QPushButton { background-color: rgb(53, 53, 53); color: white; }");

    // Show the input dialog and retrieve the string value
    QString entryTitle = "";
    if (dialog.exec() == QDialog::Accepted) {
        entryTitle = dialog.textValue();
    }
    /////////////////////////////////

    // Check if an entry with the specified title already exists
    if (entryMap.contains(entryTitle)) {
        QMessageBox::warning(this, "Entry Already Exists", "An entry with the specified title already exists. Please choose a different title.");
    } else {
        // Create a new JournalEntry
        JournalEntry newEntry;
        newEntry.setTitle(entryTitle);
        newEntry.setContent(""); // Set the content to empty

        // Add the entry to the map
        entryMap.insert(entryTitle, newEntry);

        // Add the entry title to the list widget
        journalEntries->addItem(entryTitle);

        // Clear the text editor
        contentTextEdit->clear();

        // Set the newly created entry as the current item in the list widget
        QListWidgetItem *newItem = journalEntries->findItems(entryTitle, Qt::MatchExactly).first();
        if (newItem) {
            journalEntries->setCurrentItem(newItem);
        }

        // Update the title label
        updateTitleLabel(entryTitle);

        // Save the new entry
        saveEntry(newEntry);
    }
}


void MainWindow::saveEntry(const JournalEntry& entry) {
    if (!entry.getTitle().isEmpty()) {
        // Serialize the entry to JSON
        QString jsonData = entry.toJson();

        // Ensure that the "entries" folder exists
        QDir entriesDir(entriesFolderPath);
        if (!entriesDir.exists()) {
            entriesDir.mkpath(".");
        }

        // Construct the file path within the "entries" folder
        QString filePath = entriesDir.absoluteFilePath(entry.getTitle() + ".json");

        // Save the JSON data to the file
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << jsonData;
            file.close();
        }
    }
}

void MainWindow::loadEntryContent(QListWidgetItem* listItem) {
    // Retrieve the title from the list item
    QString currentEntryTitle = titleLabel->text();

    // First we check if the titleLabel has been changed from it's initial state...
    if (currentEntryTitle != "Journal Entry Title") {
        // Before we do anything else, we want to save the contents of the current entry.
        // This way, we don't accidentally delete it by clicking on another entry.
        JournalEntry oldEntry = entryMap.value(currentEntryTitle);
        oldEntry.setContent(contentTextEdit->toPlainText());
        entryMap[currentEntryTitle] = oldEntry; // Update the value in the map as well
        saveEntry(oldEntry); // Save the current entry

    }

    QString nextEntry = listItem->text();

    // Check if the title exists in the entry map
    if (entryMap.contains(nextEntry)) {
        // Retrieve the JournalEntry from the map
        JournalEntry entry = entryMap.value(nextEntry);

        // Update the text editor window with the entry's content
        contentTextEdit->setPlainText(entry.getContent());
        updateTitleLabel(entry.getTitle()); // Update the title label
    } else {
        // If the entry does not exist in the map, clear the text editor window
        contentTextEdit->clear();
        updateTitleLabel(""); // Update the title label to empty
        qDebug() << " -- Something must have gone wrong. We clicked on an entry, but it does not exist in the map.";
    }
}

void MainWindow::updateTitleLabel(const QString &title) {
        titleLabel->setText(title);
}

void MainWindow::toggleSidebar() {
    if (journalEntries->isVisible()) {
        journalEntries->hide();
    } else {
        journalEntries->show();
    }
}
