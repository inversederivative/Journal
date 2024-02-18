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

//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create main window
//    setWindowTitle("Simple Journal App");
//    resize(800, 600);
//
//    QIcon appIcon("./images/icon.png");
//    setWindowIcon(appIcon);
//
//    // Create central widget and layout for main window
//    QWidget *centralWidget = new QWidget(this);
//    setCentralWidget(centralWidget);
//
//    // Create a splitter to manage the resizable layout
//    QSplitter *splitter = new QSplitter(Qt::Horizontal, centralWidget);
//
//    // Create layout for main window
//    //QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
//    QHBoxLayout* journalLayout = new QHBoxLayout();
//
//    // Sidebar with journal entries
//    journalEntries = new QListWidget(splitter);
//    journalEntries->setFixedWidth(200);
//    journalLayout->addWidget(journalEntries);
//
//    // Journal page area
//    QWidget* journalPageWidget = new QWidget(splitter);
//    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
//    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
//    contentTextEdit = new QTextEdit();
//    journalPageLayout->addWidget(titleLabel);
//    journalPageLayout->addWidget(contentTextEdit);
//
//    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
//    mainLayout->addWidget(splitter);
//
//    // Create and add menu bar
//    QMenuBar *menuBar = this->menuBar();
//    QMenu *fileMenu = menuBar->addMenu("&File");
//
//    // Create the File Menu actions
//    QAction *newEntryAction = fileMenu->addAction("&New Entry");
//    QAction* saveAction = fileMenu->addAction("&Save Entry");
//    QAction* exitAction = fileMenu->addAction("&Exit");
//
//    // Connect them to their handler functions
//    QObject::connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
//    QObject::connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
//    QObject::connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);
//
//    // Change the behavior of the journal entries, when clicked on
//    QObject::connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);
//
//    QMenu *editMenu = menuBar->addMenu("&Edit");
//    // Add edit actions as needed...
//
//    // Cut, Copy, Duplicate, Paste
//    editMenu->addAction("&Cut");
//    editMenu->addAction("&Copy");
//    editMenu->addAction("&Duplicate");
//    editMenu->addAction("&Paste");
//
//    populateEntriesFromFolder();
//}

//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create main window
//    setWindowTitle("Simple Journal App");
//    resize(800, 600);
//
//    QIcon appIcon("./images/icon.png");
//    setWindowIcon(appIcon);
//
//    // Create central widget
//    QWidget *centralWidget = new QWidget(this);
//    setCentralWidget(centralWidget);
//
//    // Create a QHBoxLayout to hold the main layout
//    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
//
//    // Sidebar with journal entries
//    QWidget* sidebar = new QWidget(this);
//    QVBoxLayout* sidebarVLayout = new QVBoxLayout(sidebar);
//    QPushButton *collapseButton = new QPushButton( this);
//    collapseButton->setFixedWidth(5); // Set a fixed width for the button
//    sidebarVLayout->addWidget(collapseButton);
//
//    journalEntries = new QListWidget();
//    journalEntries->setFixedWidth(200);
//    sidebarVLayout->addWidget(journalEntries);
//    //sidebarVLayout->addStretch(); // Add stretch to push the button to the bottom
//
//
//    // Journal page area
//    QWidget* journalPageWidget = new QWidget(this);
//    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
//    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
//    contentTextEdit = new QTextEdit();
//    journalPageLayout->addWidget(titleLabel);
//    journalPageLayout->addWidget(contentTextEdit);
//
//    // Add sidebar and journalPageWidget to the main layout
//    mainLayout->addWidget(sidebar);
//    mainLayout->addWidget(journalPageWidget);
//
//    // Create and add menu bar
//    QMenuBar *menuBar = this->menuBar();
//    QMenu *fileMenu = menuBar->addMenu("&File");
//
//    // Create the File Menu actions
//    QAction *newEntryAction = fileMenu->addAction("&New Entry");
//    QAction* saveAction = fileMenu->addAction("&Save Entry");
//    QAction* exitAction = fileMenu->addAction("&Exit");
//
//    // Connect them to their handler functions
//    QObject::connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
//    QObject::connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
//    QObject::connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);
//
//    // Connect the collapseButton to its handler function
//    QObject::connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
//
//    // Change the behavior of the journal entries, when clicked on
//    QObject::connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);
//
//    QMenu *editMenu = menuBar->addMenu("&Edit");
//    // Add edit actions as needed...
//
//    // Cut, Copy, Duplicate, Paste
//    editMenu->addAction("&Cut");
//    editMenu->addAction("&Copy");
//    editMenu->addAction("&Duplicate");
//    editMenu->addAction("&Paste");
//
//    // Populate entries from folder
//    populateEntriesFromFolder();
//}

//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create main window
//    setWindowTitle("Simple Journal App");
//    resize(800, 600);
//
//    QIcon appIcon("./images/icon.png");
//    setWindowIcon(appIcon);
//
//    // Create central widget
//    QWidget *centralWidget = new QWidget(this);
//    setCentralWidget(centralWidget);
//
//    // Create a QHBoxLayout to hold the main layout
//    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
//
//    // Sidebar with journal entries
//    QWidget* sidebar = new QWidget(this);
//    QVBoxLayout* sidebarLayout = new QVBoxLayout(sidebar);
//
//    // Create a QPushButton with a hamburger icon
//    QPushButton *collapseButton = new QPushButton(this);
//    QIcon buttonIcon("./images/hamburger.png");
//    collapseButton->setIcon(buttonIcon);
//    collapseButton->setFixedSize(30, 30); // Set the size of the button
//    collapseButton->setStyleSheet("QPushButton { border: none; }"); // Remove the button border
//    sidebarLayout->addWidget(collapseButton);
//
//    // Initialize Journal Entries and set width
//    journalEntries = new QListWidget();
//    journalEntries->setFixedWidth(200);
//    sidebarLayout->addWidget(journalEntries);
//    sidebarLayout->setContentsMargins(0, 0, 0, 0); // Set margins to 0
//
//    // Journal page area
//    QWidget* journalPageWidget = new QWidget(this);
//    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
//    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
//    contentTextEdit = new QTextEdit();
//    journalPageLayout->addWidget(titleLabel);
//    journalPageLayout->addWidget(contentTextEdit);
//
//    // Create a QHBoxLayout for the main content
//    QHBoxLayout *contentLayout = new QHBoxLayout();
//    contentLayout->addWidget(sidebar);
//    contentLayout->addWidget(journalPageWidget);
//    mainLayout->addLayout(contentLayout);
//
//    // Create and add menu bar
//    QMenuBar *menuBar = this->menuBar();
//    QMenu *fileMenu = menuBar->addMenu("&File");
//
//    // Create the File Menu actions
//    QAction *newEntryAction = fileMenu->addAction("&New Entry");
//    QAction* saveAction = fileMenu->addAction("&Save Entry");
//    QAction* exitAction = fileMenu->addAction("&Exit");
//
//    // Connect them to their handler functions
//    QObject::connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
//    QObject::connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
//    QObject::connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);
//
//    // Connect the collapseButton to its handler function
//    QObject::connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
//
//    // Change the behavior of the journal entries, when clicked on
//    QObject::connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);
//
//    QMenu *editMenu = menuBar->addMenu("&Edit");
//    // Add edit actions as needed...
//
//    // Cut, Copy, Duplicate, Paste
//    editMenu->addAction("&Cut");
//    editMenu->addAction("&Copy");
//    editMenu->addAction("&Duplicate");
//    editMenu->addAction("&Paste");
//
//    // Populate entries from folder
//    populateEntriesFromFolder();
//}


//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create main window
//    setWindowTitle("Simple Journal App");
//    resize(800, 600);
//
//    QIcon appIcon("./images/icon.png");
//    setWindowIcon(appIcon);
//
//    // Create central widget and layout for main window
//    QWidget *centralWidget = new QWidget(this);
//    setCentralWidget(centralWidget);
//
//    // Create layout for main window
//    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
//
//    // Create layout for journal area
//    QVBoxLayout* journalLayout = new QVBoxLayout();
//
//    // Create the hamburger button
//    QPushButton *collapseButton = new QPushButton(this);
//    QIcon buttonIcon("./images/hamburger.png");
//    collapseButton->setIcon(buttonIcon);
//    collapseButton->setFixedSize(30, 30); // Set the size of the button
//    collapseButton->setStyleSheet("QPushButton { border: none; }"); // Remove the button border
//    journalLayout->addWidget(collapseButton, 0, Qt::AlignTop); // Add button to the top
//
//    // Sidebar with journal entries
//    journalEntries = new QListWidget();
//    journalEntries->setFixedWidth(200);
//    journalLayout->addWidget(journalEntries);
//
//    // Journal page area
//    QWidget* journalPageWidget = new QWidget();
//    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
//    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
//    contentTextEdit = new QTextEdit();
//    journalPageLayout->addWidget(titleLabel);
//    journalPageLayout->addWidget(contentTextEdit);
//    journalLayout->addWidget(journalPageWidget);
//
//    // Add journal layout to main layout
//    mainLayout->addLayout(journalLayout);
//
//    // Create and add menu bar
//    QMenuBar *menuBar = this->menuBar();
//    QMenu *fileMenu = menuBar->addMenu("&File");
//
//    // Create the File Menu actions
//    QAction *newEntryAction = fileMenu->addAction("&New Entry");
//    QAction* saveAction = fileMenu->addAction("&Save Entry");
//    QAction* exitAction = fileMenu->addAction("&Exit");
//
//    // Connect them to their handler functions
//    connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
//    connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
//    connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);
//
//    // Connect the collapseButton to its handler function
//    connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
//
//    // Change the behavior of the journal entries, when clicked on
//    connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);
//
//    QMenu *editMenu = menuBar->addMenu("&Edit");
//    // Add edit actions as needed...
//
//    // Cut, Copy, Duplicate, Paste
//    editMenu->addAction("&Cut");
//    editMenu->addAction("&Copy");
//    editMenu->addAction("&Duplicate");
//    editMenu->addAction("&Paste");
//
//    populateEntriesFromFolder();
//}

///////////////// NEARLY PERFECT!!!!

//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create main window
//    setWindowTitle("Simple Journal App");
//    resize(800, 600);
//
//    QIcon appIcon("./images/icon.png");
//    setWindowIcon(appIcon);
//
//    // Create central widget and layout for main window
//    QWidget *centralWidget = new QWidget(this);
//    setCentralWidget(centralWidget);
//
//    // Create layout for main window
//    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
//
//    // Create layout for journal area
//    QHBoxLayout* journalLayout = new QHBoxLayout();
//
//    // Create the hamburger button
//    QPushButton *collapseButton = new QPushButton(this);
//    QIcon buttonIcon("./images/hamburger.png");
//    collapseButton->setIcon(buttonIcon);
//    collapseButton->setFixedSize(30, 30); // Set the size of the button
//    collapseButton->setStyleSheet("QPushButton { border: none; }"); // Remove the button border
//    journalLayout->addWidget(collapseButton); // Add button to the left
//
//    // Sidebar with journal entries
//    journalEntries = new QListWidget();
//    journalEntries->setFixedWidth(200);
//    journalLayout->addWidget(journalEntries);
//
//    // Journal page area
//    QWidget* journalPageWidget = new QWidget();
//    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
//    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
//    contentTextEdit = new QTextEdit();
//    journalPageLayout->addWidget(titleLabel);
//    journalPageLayout->addWidget(contentTextEdit);
//
//    // Add journal page widget to journal layout
//    journalLayout->addWidget(journalPageWidget);
//
//    // Add journal layout to main layout
//    mainLayout->addLayout(journalLayout);
//
//    // Create and add menu bar
//    QMenuBar *menuBar = this->menuBar();
//    QMenu *fileMenu = menuBar->addMenu("&File");
//
//    // Create the File Menu actions
//    QAction *newEntryAction = fileMenu->addAction("&New Entry");
//    QAction* saveAction = fileMenu->addAction("&Save Entry");
//    QAction* exitAction = fileMenu->addAction("&Exit");
//
//    // Connect them to their handler functions
//    connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
//    connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
//    connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);
//
//    // Connect the collapseButton to its handler function
//    connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
//
//    // Change the behavior of the journal entries, when clicked on
//    connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);
//
//    QMenu *editMenu = menuBar->addMenu("&Edit");
//    // Add edit actions as needed...
//
//    // Cut, Copy, Duplicate, Paste
//    editMenu->addAction("&Cut");
//    editMenu->addAction("&Copy");
//    editMenu->addAction("&Duplicate");
//    editMenu->addAction("&Paste");
//
//    populateEntriesFromFolder();
//}



void MainWindow::toggleSidebar() {
    if (journalEntries->isVisible()) {
        journalEntries->hide();
    } else {
        journalEntries->show();
    }
}

/////////////////// EVEN MORE PERFECT, BUT NEEDS WORK!!!

//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create main window
//    setWindowTitle("Simple Journal App");
//    resize(800, 600);
//
//    QIcon appIcon("./images/icon.png");
//    setWindowIcon(appIcon);
//
//    // Create central widget and layout for main window
//    QWidget *centralWidget = new QWidget(this);
//    setCentralWidget(centralWidget);
//
//    // Create layout for main window
//    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
//
//    // Create layout for journal area
//    QHBoxLayout* journalLayout = new QHBoxLayout();
//
//    // Create the hamburger button
//    QPushButton *collapseButton = new QPushButton(this);
//    QIcon buttonIcon("./images/hamburger.png");
//    collapseButton->setIcon(buttonIcon);
//    collapseButton->setFixedSize(30, 30); // Set the size of the button
//    collapseButton->setStyleSheet("QPushButton { border: none; }"); // Remove the button border
//
//    // Add the hamburger button to the top of its widget
//    QVBoxLayout* buttonLayout = new QVBoxLayout();
//    buttonLayout->addWidget(collapseButton, 0, Qt::AlignTop); // Align button to the top
//    journalLayout->addLayout(buttonLayout); // Add button layout to journal layout
//
//    // Sidebar with journal entries
//    journalEntries = new QListWidget();
//    journalEntries->setFixedWidth(200);
//    journalLayout->addWidget(journalEntries);
//
//    // Journal page area
//    QWidget* journalPageWidget = new QWidget();
//    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
//    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
//    contentTextEdit = new QTextEdit();
//    journalPageLayout->addWidget(titleLabel);
//    journalPageLayout->addWidget(contentTextEdit);
//
//    // Add journal page widget to journal layout
//    journalLayout->addWidget(journalPageWidget);
//
//    // Add journal layout to main layout
//    mainLayout->addLayout(journalLayout);
//
//    // Create and add menu bar
//    QMenuBar *menuBar = this->menuBar();
//    QMenu *fileMenu = menuBar->addMenu("&File");
//
//    // Create the File Menu actions
//    QAction *newEntryAction = fileMenu->addAction("&New Entry");
//    QAction* saveAction = fileMenu->addAction("&Save Entry");
//    QAction* exitAction = fileMenu->addAction("&Exit");
//
//    // Connect them to their handler functions
//    connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
//    connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
//    connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);
//
//    // Connect the collapseButton to its handler function
//    connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
//
//    // Change the behavior of the journal entries, when clicked on
//    connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);
//
//    QMenu *editMenu = menuBar->addMenu("&Edit");
//    // Add edit actions as needed...
//
//    // Cut, Copy, Duplicate, Paste
//    editMenu->addAction("&Cut");
//    editMenu->addAction("&Copy");
//    editMenu->addAction("&Duplicate");
//    editMenu->addAction("&Paste");
//
//    populateEntriesFromFolder();
//}

//////////////// Backwards progress. Journal page is now below journal entries, but hamburger is right!

//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
//    // Create main window
//    setWindowTitle("Simple Journal App");
//    resize(800, 600);
//
//    QIcon appIcon("./images/icon.png");
//    setWindowIcon(appIcon);
//
//    // Create central widget and layout for main window
//    QWidget *centralWidget = new QWidget(this);
//    setCentralWidget(centralWidget);
//
//    // Create layout for main window
//    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
//
//    // Create top bar layout
//    QHBoxLayout* topBarLayout = new QHBoxLayout();
//
//    // Create the hamburger button
//    QPushButton *collapseButton = new QPushButton(this);
//    QIcon buttonIcon("./images/hamburger.png");
//    collapseButton->setIcon(buttonIcon);
//    collapseButton->setFixedSize(30, 30); // Set the size of the button
//    collapseButton->setStyleSheet("QPushButton { border: none; }"); // Remove the button border
//    topBarLayout->addWidget(collapseButton);
//
//    // Add horizontal spacer to push the button to the right
//    topBarLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
//
//    // Add top bar layout to main layout
//    mainLayout->addLayout(topBarLayout);
//
//    // Sidebar with journal entries
//    journalEntries = new QListWidget();
//    journalEntries->setFixedWidth(200);
//    mainLayout->addWidget(journalEntries);
//
//    // Journal page area
//    QWidget* journalPageWidget = new QWidget();
//    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
//    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
//    contentTextEdit = new QTextEdit();
//    journalPageLayout->addWidget(titleLabel);
//    journalPageLayout->addWidget(contentTextEdit);
//    mainLayout->addWidget(journalPageWidget);
//
//    // Create and add menu bar
//    QMenuBar *menuBar = this->menuBar();
//    QMenu *fileMenu = menuBar->addMenu("&File");
//
//    // Create the File Menu actions
//    QAction *newEntryAction = fileMenu->addAction("&New Entry");
//    QAction* saveAction = fileMenu->addAction("&Save Entry");
//    QAction* exitAction = fileMenu->addAction("&Exit");
//
//    // Connect them to their handler functions
//    connect(newEntryAction, &QAction::triggered, this, &MainWindow::createNewEntry);
//    connect(saveAction, &QAction::triggered, this, &MainWindow::saveEntry);
//    connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);
//
//    // Connect the collapseButton to its handler function
//    connect(collapseButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
//
//    // Change the behavior of the journal entries, when clicked on
//    connect(journalEntries, &QListWidget::itemClicked, this, &MainWindow::loadEntryContent);
//
//    QMenu *editMenu = menuBar->addMenu("&Edit");
//    // Add edit actions as needed...
//
//    // Cut, Copy, Duplicate, Paste
//    editMenu->addAction("&Cut");
//    editMenu->addAction("&Copy");
//    editMenu->addAction("&Duplicate");
//    editMenu->addAction("&Paste");
//
//    populateEntriesFromFolder();
//}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create main window
    setWindowTitle("Simple Journal App");
    resize(800, 600);

    QIcon appIcon("./images/icon.png");
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
    QIcon buttonIcon("./images/hamburger.png");
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
    journalLayout->addWidget(journalEntries);

    // Journal page area
    QWidget* journalPageWidget = new QWidget();
    QVBoxLayout* journalPageLayout = new QVBoxLayout(journalPageWidget);
    titleLabel = new QLabel("Journal Entry Title"); // Initialize titleLabel
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    contentTextEdit = new QTextEdit();
    journalPageLayout->addWidget(titleLabel);
    journalPageLayout->addWidget(contentTextEdit);
    journalLayout->addWidget(journalPageWidget);

    // Add the journal layout to the main layout
    mainLayout->addLayout(journalLayout);

    // Create and add menu bar
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = menuBar->addMenu("&File");

    // Create the File Menu actions
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


//void MainWindow::saveEntry() {
//    // Get the content from the text edit widget
//    QString content = contentTextEdit->toPlainText();
//
//    // Open a file dialog to choose the file path
//    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Entry"), "", tr("Text Files (*.txt)"));
//
//    // If the file path is not empty, proceed with saving
//    if (!filePath.isEmpty()) {
//        QFile file(filePath);
//
//        // Try to open the file in WriteOnly and Text mode
//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            QTextStream out(&file);
//            // Write the content to the file
//            out << content;
//            // Close the file
//            file.close();
//        }
//    }
//}

void MainWindow::saveEntry() {
    if (!currentEntry.getTitle().isEmpty()) {
        currentEntry.setContent(contentTextEdit->toPlainText());

        // Ensure that the "entries" folder exists
        QDir entriesDir(QCoreApplication::applicationDirPath() + "/entries");
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
    QString filePath = QCoreApplication::applicationDirPath() + "/entries/" + currentEntry.getTitle().trimmed() + ".txt";

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
    // Get the path to the "entries" folder
    QString entriesFolderPath = QCoreApplication::applicationDirPath() + "/entries";

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

