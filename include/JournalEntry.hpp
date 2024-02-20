//
// Created by John on 2/20/2024.
//
#include <QString>

#ifndef JOURNAL_JOURNALENTRY_HPP
#define JOURNAL_JOURNALENTRY_HPP

/*
 * TODO: Implement creationDate and lastEditedDate fields.
 * Then populate the JSON properly.
 *
 * Once that's all done, we want to modify the init function, so it
 * populates the values in descending order, with the newest entries
 * on top.
 *
 * Also, when we create a new entry, we'll have to handle this change as well
 * so that the newest entry is on top of the list of entries.
 */

class JournalEntry {
private:
    QString title;
    QString content;

public:
    QString getTitle() const;

    void setTitle(const QString& titleString);

    QString getContent() const;

    void setContent(const QString& contentString);

    QString toJson() const;

    JournalEntry fromJson(const QString &jsonData);


};

#endif //JOURNAL_JOURNALENTRY_HPP
