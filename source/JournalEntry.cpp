//
// Created by John on 2/20/2024.
//
#include <JournalEntry.hpp>
#include <QJsonObject>
#include <QJsonDocument>

QString JournalEntry::getTitle() const {
    return title;
}

void JournalEntry::setTitle(const QString &titleString) {
    title = titleString;
}

QString JournalEntry::getContent() const {
    return content;
}

void JournalEntry::setContent(const QString &contentString) {
    content = contentString;
}

QString JournalEntry::toJson() const {
    QJsonObject jsonObject;

    // Add title and content to the JSON object
    jsonObject["title"] = title;
    jsonObject["content"] = content;

    // Convert the JSON object to a string
    QJsonDocument jsonDoc(jsonObject);
    return jsonDoc.toJson();
}

JournalEntry JournalEntry::fromJson(const QString &jsonData) {
    JournalEntry entry;

    // Parse JSON data
    QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
    if (!doc.isNull() && doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("title") && obj.contains("content")) {
            entry.setTitle(obj["title"].toString());
            entry.setContent(obj["content"].toString());
        } else {
            qWarning() << "Invalid JSON format: missing title or content field";
        }
    } else {
        qWarning() << "Invalid JSON data";
    }

    return entry;
}