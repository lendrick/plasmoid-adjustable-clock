/***********************************************************************************
* Adjustable Clock: Plasmoid to show date and time in adjustable format.
* Copyright (C) 2008 - 2012 Michal Dutkiewicz aka Emdek <emdeck@gmail.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
***********************************************************************************/

#ifndef ADJUSTABLECLOCK_HEADER
#define ADJUSTABLECLOCK_HEADER

#include <QtCore/QList>
#include <QtCore/QDateTime>
#include <QtWebKit/QWebPage>

#include <Plasma/Applet>
#include <Plasma/DataEngine>

#include <plasmaclock/clockapplet.h>

#include "ui_appearance.h"
#include "ui_clipboard.h"

enum ClockFeature { NoFeatures = 0, SecondsClockFeature = 1, SecondsToolTipFeature = 2, HolidaysFeature = 4, EventsFeature = 8, SunsetFeature = 16, SunriseFeature = 32 };

class AdjustableClock : public ClockApplet
{
    Q_OBJECT

public:
    AdjustableClock(QObject *parent, const QVariantList &args);

    void init();
    void paintInterface(QPainter *painter, const QStyleOptionGraphicsItem *option, const QRect &contentsRect);

protected:
    void constraintsEvent(Plasma::Constraints constraints);
    void resizeEvent(QGraphicsSceneResizeEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    void createClockConfigurationInterface(KConfigDialog *parent);
    void changeEngineTimezone(const QString &oldTimezone, const QString &newTimezone);
    void connectSource(const QString &timezone);
    void setText(const QString &text);
    QDateTime currentDateTime() const;
    QString holiday() const;
    QString formatDateTime(const QDateTime dateTime, const QString &format) const;
    QList<QAction*> contextualActions();

protected slots:
    void dataUpdated(const QString &name, const Plasma::DataEngine::Data &data);
    void clockConfigChanged();
    void clockConfigAccepted();
    void copyToClipboard();
    void insertPlaceholder(QAction *action);
    void loadFormat(int index);
    void addFormat(bool automatically = false);
    void removeFormat();
    void changeFormat();
    void updateControls();
    void toggleState();
    void selectColor();
    void selectFontSize(const QString &size);
    void selectFontFamily(const QFont &font);
    void setColor(const QString &color);
    void setFontSize(const QString &size);
    void setFontFamily(const QString &font);
    void selectionChanged();
    void itemSelectionChanged();
    void insertRow();
    void deleteRow();
    void moveRow(bool up);
    void moveRowUp();
    void moveRowDown();
    void updateRow(int row, int column);
    void toolTipAboutToShow();
    void toolTipHidden();
    void copyToClipboard(QAction *action);
    void updateClipboardMenu();
    void updateToolTipContent();
    void updateSize();
    void updateTheme();

private:
    QWebPage m_page;
    QString m_timeFormat;
    QString m_dateTimeString;
    QString m_timeZoneAbbreviation;
    QString m_timeZoneOffset;
    QString m_holiday;
    QString m_currentText;
    QStringList m_clipboardFormats;
    QStringList m_timeFormatStrings;
    QStringList m_timeFormatNames;
    QDateTime m_dateTime;
    QTime m_sunrise;
    QTime m_sunset;
    QAction *m_clipboardAction;
    QFlags<ClockFeature> m_features;
    int m_controlsTimer;
    int m_fontSize;
    Ui::appearance m_appearanceUi;
    Ui::clipboard m_clipboardUi;

    Q_DECLARE_FLAGS(ClockFeatures, ClockFeature)
};

#endif
