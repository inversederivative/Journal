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
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create layout for main window
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);


    // Create top bar layout
    QHBoxLayout* topBarLayout = new QHBoxLayout();

    // Create the hamburger button
    QPushButton *collapseButton = new QPushButton(this);
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
    QHBoxLayout *journalLayout = new QHBoxLayout();

    // Sidebar with journal entries
    journalEntries = new QListWidget();
    journalEntries->setFixedWidth(200);
    journalEntries->setStyleSheet("QListWidget { border: none; }");
    journalLayout->addWidget(journalEntries);

    // Journal page area
    QWidget* journalPageWidget = new QWidget();
    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
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
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
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

    populateEntriesFromFolder();
}


void MainWindow::createNewEntry() {
    // Prompt the user to enter a title for the new entry
    QString entryTitle = QInputDialog::getText(this, "New Entry", "Enter a title for the new entry:");

    // Check if an entry with the specified title already exists
    bool entryExists = false;
    for (int i = 0; i < journalEntries->count(); ++i) {
        if (journalEntries->item(i)->text() == entryTitle) {
            entryExists = true;
            break;
        }
    }

    if (entryExists) {
        QMessageBox::warning(this, "Entry Already Exists", "An entry with the specified title already exists. Please choose a different title.");
    } else {
        // Add the entry title to the list widget
        journalEntries->addItem(entryTitle);
        currentEntry.setTitle(entryTitle);

        // Clear the text editor
        contentTextEdit->clear();
        currentEntry.setContent("");

        // Set the newly created entry as the current item in the list widget
        QListWidgetItem *newItem = journalEntries->findItems(entryTitle, Qt::MatchExactly).first();
        if (newItem) {
            journalEntries->setCurrentItem(newItem);
        }
        updateTitleLabel(entryTitle);
    }
    saveEntry(); // Note, this will overwrite any existing files with same name.
}

void MainWindow::saveEntry() {
    if (!currentEntry.getTitle().isEmpty()) {
        currentEntry.setContent(contentTextEdit->toPlainText());

        // Ensure that the "entries" folder exists
        QDir entriesDir(entriesFolderPath);
        if (!entriesDir.exists()) {
            entriesDir.mkpath(".");
        }

        // Construct the file path within the "entries" folder
        QString filePath = entriesDir.absoluteFilePath(currentEntry.getTitle() + ".txt");

        // Save the entry content to the file
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << currentEntry.getContent();
            file.close();
        }
    }
}


void MainWindow::loadEntryContent(QListWidgetItem* listItem) {
    // Before we do anything else, we want to save the contents of the current entry.
    // This way, we don't accidentally delete, by clicking on another entry.
    saveEntry();
    currentEntry.setTitle(listItem->text());
    QString filePath = entriesFolderPath + "/" + currentEntry.getTitle().trimmed() + ".txt";

    // Open the file and load its content into the text editor
    QFile file(filePath);

    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            currentEntry.setContent(in.readAll()); // Update the current entry's content
            contentTextEdit->setPlainText(currentEntry.getContent());
            file.close();
        }
    }
    else
    {
        currentEntry.setContent("");
        contentTextEdit->clear(); // Clear the text editor content
    }
    updateTitleLabel(currentEntry.getTitle());
}


void MainWindow::populateEntriesFromFolder() {

    // Check if the folder exists
    QDir entriesDir(entriesFolderPath);
    if (!entriesDir.exists()) {
        return; // If the folder doesn't exist, there are no entries to populate
    }

    // Get the list of files in the "entries" folder
    QStringList entryFiles = entriesDir.entryList(QDir::Files);

    // Iterate over the list of entry files
    for (const QString &entryFile : entryFiles) {
        // Extract the entry title from the file name (remove the ".txt" extension)
        QString entryTitle = entryFile.left(entryFile.length() - 4);

        // Add the entry title to the list widget
        journalEntries->addItem(entryTitle);
    }

    // If there are files in the folder, load the content of the first file into the text editor window
    if (!entryFiles.isEmpty()) {
        QString firstEntryFilePath = entriesFolderPath + "/" + entryFiles.first();
        QFile firstEntryFile(firstEntryFilePath);
        if (firstEntryFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&firstEntryFile);
            QString firstEntryContent = in.readAll();
            contentTextEdit->setPlainText(firstEntryContent);
            firstEntryFile.close();

            // Extract the title of the first entry (remove the ".txt" extension)
            QString firstEntryTitle = entryFiles.first().left(entryFiles.first().length() - 4);

            // Update the title label with the title of the first entry
            updateTitleLabel(firstEntryTitle);
        }
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