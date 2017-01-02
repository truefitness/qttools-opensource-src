/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Assistant of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class QLabel;
class QPushButton;
class QGridLayout;

class AboutLabel : public QTextBrowser
{
    Q_OBJECT

public:
    AboutLabel(QWidget *parent = 0);
    void setText(const QString &text, const QByteArray &resources);
    QSize minimumSizeHint() const;

private:
    QVariant loadResource(int type, const QUrl &name);
    void setSource(const QUrl &url);

    QMap<QString, QByteArray> m_resourceMap;
};

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget *parent = 0);
    void setText(const QString &text, const QByteArray &resources);
    void setPixmap(const QPixmap &pixmap);
    QString documentTitle() const;

private:
    void updateSize();

    QLabel *m_pixmapLabel;
    AboutLabel *m_aboutLabel;
    QPushButton *m_closeButton;
    QGridLayout *m_layout;
};

QT_END_NAMESPACE

#endif
