/*
 * Copyright (c) 2014-2024 Patrizio Bekerle -- <patrizio@bekerle.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 */

#pragma once

#include <QHash>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QVariant>

class SettingsService : public QObject {
    Q_OBJECT

   public:
    static SettingsService &instance();

    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;
    void setValue(const QString &key, const QVariant &value);
    void remove(const QString &key);
    bool contains(const QString &key) const;
    void sync();
    QStringList allKeys() const;
    void clear();

    void beginGroup(const QString &prefix);
    void endGroup();
    QString group() const;

    // Delete copy constructor and assignment operator
    SettingsService(const SettingsService &) = delete;
    SettingsService &operator=(const SettingsService &) = delete;

   private:
    SettingsService(QObject *parent = nullptr);
    ~SettingsService() = default;

    QSettings m_settings;
    mutable QHash<QString, QVariant> m_cache;
    QString m_group;
};
