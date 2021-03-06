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

#include "Configuration.h"
#include "PlaceholderDialog.h"
#include "PreviewDelegate.h"
#include "FormatDelegate.h"
#include "FormatLineEdit.h"

#include <QtWebKit/QWebFrame>

#include <KMenu>
#include <KLocale>
#include <KMessageBox>
#include <KColorDialog>
#include <KInputDialog>

#include <Plasma/Theme>

#define PLACEHOLDERSTYLE " placeholder {background: rgba(252, 255, 225, 0.8); border-radius: 0.3em; box-shadow: 0 0 0 2px #F5C800;}"

namespace AdjustableClock
{

Configuration::Configuration(Applet *applet, KConfigDialog *parent) : QObject(parent),
    m_applet(applet),
    m_themesModel(new QStandardItemModel(this)),
    m_editedItem(NULL)
{
    QWidget *appearanceConfiguration = new QWidget;
    QWidget *clipboardActions = new QWidget;
    const QStringList clipboardFormats = m_applet->clipboardFormats();
    QString preview;
    int row;

    m_appearanceUi.setupUi(appearanceConfiguration);
    m_clipboardUi.setupUi(clipboardActions);

    const QList<Theme> themes = m_applet->themes();

    for (int i = 0; i < themes.count(); ++i) {
        QStandardItem *item = new QStandardItem();
        item->setData(themes.at(i).id, IdRole);
        item->setData(themes.at(i).title, TitleRole);
        item->setData(themes.at(i).description, DescriptionRole);
        item->setData(themes.at(i).author, AuthorRole);
        item->setData(themes.at(i).html, HtmlRole);
        item->setData(themes.at(i).css, CssRole);
        item->setData(themes.at(i).script, ScriptRole);
        item->setData(themes.at(i).background, BackgroundRole);
        item->setData(themes.at(i).bundled, BundledRole);
        item->setToolTip(QLatin1String("<b>") + (themes.at(i).author.isEmpty() ? themes.at(i).title : i18n("\"%1\" by %2").arg(themes.at(i).title).arg(themes.at(i).author)) + QLatin1String("</b>") + (themes.at(i).description.isEmpty() ? QString() : QLatin1String("<br />") + themes.at(i).description));

        m_themesModel->appendRow(item);
    }

    PreviewDelegate *delegate = new PreviewDelegate(m_appearanceUi.themesView);
    QPalette webViewPalette = m_appearanceUi.webView->page()->palette();
    webViewPalette.setBrush(QPalette::Base, Qt::transparent);

    m_appearanceUi.themesView->setModel(m_themesModel);
    m_appearanceUi.themesView->setItemDelegate(delegate);
    m_appearanceUi.webView->setAttribute(Qt::WA_OpaquePaintEvent, false);
    m_appearanceUi.webView->page()->setPalette(webViewPalette);
    m_appearanceUi.webView->page()->setContentEditable(true);
    m_appearanceUi.webView->page()->action(QWebPage::Undo)->setText(i18n("Undo"));
    m_appearanceUi.webView->page()->action(QWebPage::Undo)->setIcon(KIcon(QLatin1String("edit-undo")));
    m_appearanceUi.webView->page()->action(QWebPage::Redo)->setText(i18n("Redo"));
    m_appearanceUi.webView->page()->action(QWebPage::Redo)->setIcon(KIcon(QLatin1String("edit-redo")));
    m_appearanceUi.webView->page()->action(QWebPage::Cut)->setText(i18n("Cut"));
    m_appearanceUi.webView->page()->action(QWebPage::Cut)->setIcon(KIcon(QLatin1String("edit-cut")));
    m_appearanceUi.webView->page()->action(QWebPage::Copy)->setText(i18n("Copy"));
    m_appearanceUi.webView->page()->action(QWebPage::Copy)->setIcon(KIcon(QLatin1String("edit-copy")));
    m_appearanceUi.webView->page()->action(QWebPage::Paste)->setText(i18n("Paste"));
    m_appearanceUi.webView->page()->action(QWebPage::Paste)->setIcon(KIcon(QLatin1String("edit-paste")));
    m_appearanceUi.webView->page()->action(QWebPage::SelectAll)->setText(i18n("Select All"));
    m_appearanceUi.webView->page()->action(QWebPage::SelectAll)->setIcon(KIcon(QLatin1String("select-all")));
    m_appearanceUi.webView->page()->action(QWebPage::ToggleBold)->setText(i18n("Bold"));
    m_appearanceUi.webView->page()->action(QWebPage::ToggleBold)->setIcon(KIcon(QLatin1String("format-text-bold")));
    m_appearanceUi.webView->page()->action(QWebPage::ToggleItalic)->setText(i18n("Italic"));
    m_appearanceUi.webView->page()->action(QWebPage::ToggleItalic)->setIcon(KIcon(QLatin1String("format-text-italic")));
    m_appearanceUi.webView->page()->action(QWebPage::ToggleUnderline)->setText(i18n("Underline"));
    m_appearanceUi.webView->page()->action(QWebPage::ToggleUnderline)->setIcon(KIcon(QLatin1String("format-text-underline")));
    m_appearanceUi.webView->page()->action(QWebPage::AlignLeft)->setText(i18n("Justify Left"));
    m_appearanceUi.webView->page()->action(QWebPage::AlignLeft)->setIcon(KIcon(QLatin1String("format-justify-left")));
    m_appearanceUi.webView->page()->action(QWebPage::AlignCenter)->setText(i18n("Justify Center"));
    m_appearanceUi.webView->page()->action(QWebPage::AlignCenter)->setIcon(KIcon(QLatin1String("format-justify-center")));
    m_appearanceUi.webView->page()->action(QWebPage::AlignRight)->setText(i18n("Justify Right"));
    m_appearanceUi.webView->page()->action(QWebPage::AlignRight)->setIcon(KIcon(QLatin1String("format-justify-right")));
    m_appearanceUi.boldButton->setDefaultAction(m_appearanceUi.webView->page()->action(QWebPage::ToggleBold));
    m_appearanceUi.italicButton->setDefaultAction(m_appearanceUi.webView->page()->action(QWebPage::ToggleItalic));
    m_appearanceUi.underlineButton->setDefaultAction(m_appearanceUi.webView->page()->action(QWebPage::ToggleUnderline));
    m_appearanceUi.justifyLeftButton->setDefaultAction(m_appearanceUi.webView->page()->action(QWebPage::AlignLeft));
    m_appearanceUi.justifyCenterButton->setDefaultAction(m_appearanceUi.webView->page()->action(QWebPage::AlignCenter));
    m_appearanceUi.justifyRightButton->setDefaultAction(m_appearanceUi.webView->page()->action(QWebPage::AlignRight));
    m_appearanceUi.backgroundButton->setIcon(KIcon(QLatin1String("games-config-background")));
    m_appearanceUi.placeholdersButton->setIcon(KIcon(QLatin1String("chronometer")));

    m_clipboardUi.moveUpButton->setIcon(KIcon(QLatin1String("arrow-up")));
    m_clipboardUi.moveDownButton->setIcon(KIcon(QLatin1String("arrow-down")));
    m_clipboardUi.clipboardActionsTable->setItemDelegate(new FormatDelegate(this));
    m_clipboardUi.clipboardActionsTable->viewport()->installEventFilter(this);
    m_clipboardUi.fastCopyFormatEdit->setText(m_applet->config().readEntry("fastCopyFormat", "%Y-%M-%d %h:%m:%s"));

    for (int i = 0; i < clipboardFormats.count(); ++i) {
        row = m_clipboardUi.clipboardActionsTable->rowCount();

        m_clipboardUi.clipboardActionsTable->insertRow(row);
        m_clipboardUi.clipboardActionsTable->setItem(row, 0, new QTableWidgetItem(clipboardFormats.at(i)));

        preview = m_applet->evaluateFormat(clipboardFormats.at(i), QDateTime::currentDateTime());

        QTableWidgetItem *item = new QTableWidgetItem(preview);
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        item->setToolTip(preview);

        m_clipboardUi.clipboardActionsTable->setItem(row, 1, item);
    }

    itemSelectionChanged();

    QPalette buttonPalette = m_appearanceUi.colorButton->palette();
    buttonPalette.setBrush(QPalette::Button, Qt::black);

    m_appearanceUi.colorButton->setPalette(buttonPalette);

    parent->addPage(appearanceConfiguration, i18n("Appearance"), QLatin1String("preferences-desktop-theme"));
    parent->addPage(clipboardActions, i18n("Clipboard actions"), QLatin1String("edit-copy"));
    parent->resize(500, 400);

    connect(parent, SIGNAL(okClicked()), this, SLOT(save()));
    connect(parent, SIGNAL(finished()), this, SLOT(disableUpdates()));
    connect(m_appearanceUi.mainTabWidget, SIGNAL(currentChanged(int)), this, SLOT(updateView(int)));
    connect(m_appearanceUi.editorTabWidget, SIGNAL(currentChanged(int)), this, SLOT(updateEditor(int)));
    connect(m_appearanceUi.themesView, SIGNAL(clicked(QModelIndex)), this, SLOT(selectTheme(QModelIndex)));
    connect(m_appearanceUi.newButton, SIGNAL(clicked()), this, SLOT(newTheme()));
    connect(m_appearanceUi.deleteButton, SIGNAL(clicked()), this, SLOT(deleteTheme()));
    connect(m_appearanceUi.renameButton, SIGNAL(clicked()), this, SLOT(renameTheme()));
    connect(m_appearanceUi.webView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showEditorContextMenu(QPoint)));
    connect(m_appearanceUi.webView->page(), SIGNAL(selectionChanged()), this, SLOT(fixSelection()));
    connect(m_appearanceUi.zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setZoom(int)));
    connect(m_appearanceUi.boldButton, SIGNAL(clicked()), this, SLOT(triggerAction()));
    connect(m_appearanceUi.italicButton, SIGNAL(clicked()), this, SLOT(triggerAction()));
    connect(m_appearanceUi.underlineButton, SIGNAL(clicked()), this, SLOT(triggerAction()));
    connect(m_appearanceUi.justifyLeftButton, SIGNAL(clicked()), this, SLOT(triggerAction()));
    connect(m_appearanceUi.justifyCenterButton, SIGNAL(clicked()), this, SLOT(triggerAction()));
    connect(m_appearanceUi.justifyRightButton, SIGNAL(clicked()), this, SLOT(triggerAction()));
    connect(m_appearanceUi.colorButton, SIGNAL(clicked()), this, SLOT(selectColor()));
    connect(m_appearanceUi.fontSizeComboBox, SIGNAL(editTextChanged(QString)), this, SLOT(selectFontSize(QString)));
    connect(m_appearanceUi.fontFamilyComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(selectFontFamily(QFont)));
    connect(m_appearanceUi.placeholdersButton, SIGNAL(clicked()), this, SLOT(insertPlaceholder()));
    connect(m_clipboardUi.addButton, SIGNAL(clicked()), this, SLOT(insertRow()));
    connect(m_clipboardUi.deleteButton, SIGNAL(clicked()), this, SLOT(deleteRow()));
    connect(m_clipboardUi.editButton, SIGNAL(clicked()), this, SLOT(editRow()));
    connect(m_clipboardUi.moveUpButton, SIGNAL(clicked()), this, SLOT(moveRowUp()));
    connect(m_clipboardUi.moveDownButton, SIGNAL(clicked()), this, SLOT(moveRowDown()));
    connect(m_clipboardUi.clipboardActionsTable, SIGNAL(itemSelectionChanged()), this, SLOT(itemSelectionChanged()));
    connect(m_clipboardUi.clipboardActionsTable, SIGNAL(cellChanged(int,int)), this, SLOT(updateRow(int)));
    connect(m_clipboardUi.clipboardActionsTable, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(editRow(QTableWidgetItem*)));
    connect(m_clipboardUi.fastCopyFormatEdit, SIGNAL(textChanged(QString)), this, SLOT(modify()));
    connect(Plasma::Theme::defaultTheme(), SIGNAL(themeChanged()), delegate, SLOT(clear()));
    connect(Plasma::Theme::defaultTheme(), SIGNAL(themeChanged()), m_appearanceUi.themesView->viewport(), SLOT(repaint()));
    connect(this, SIGNAL(clearCache()), delegate, SLOT(clear()));

    const int currentTheme = qMax(findRow(m_applet->config().readEntry("format", "%default%"), IdRole), 0);

    m_appearanceUi.themesView->setCurrentIndex(m_themesModel->index(currentTheme, 0));
    m_appearanceUi.themesView->scrollTo(m_themesModel->index(currentTheme, 0));

    selectTheme(m_themesModel->index(currentTheme, 0));
}

void Configuration::save()
{
    QStringList clipboardFormats;

    updateEditor(m_appearanceUi.editorTabWidget->currentIndex() ? 0 : 1);

    if (m_editedItem) {
        m_clipboardUi.clipboardActionsTable->closePersistentEditor(m_editedItem);
    }

    m_applet->config().deleteGroup("Formats");

    KConfigGroup themesConfiguration = m_applet->config().group("Formats");

    for (int i = 0; i < m_themesModel->rowCount(); ++i) {
        QModelIndex index = m_themesModel->index(i, 0);

        if (index.data(BundledRole).toBool()) {
            continue;
        }

        Theme theme;
        theme.title = index.data(TitleRole).toString();
        theme.html = index.data(HtmlRole).toString();
        theme.css = index.data(CssRole).toString();
        theme.script = index.data(ScriptRole).toString();
        theme.background = index.data(BackgroundRole).toBool();

        KConfigGroup themeConfiguration = themesConfiguration.group(index.data(IdRole).toString());
        themeConfiguration.writeEntry("title", theme.title);
        themeConfiguration.writeEntry("html", theme.html);
        themeConfiguration.writeEntry("css", theme.css);
        themeConfiguration.writeEntry("script", theme.script);
        themeConfiguration.writeEntry("background", theme.background);
    }

    for (int i = 0; i < m_clipboardUi.clipboardActionsTable->rowCount(); ++i) {
        clipboardFormats.append(m_clipboardUi.clipboardActionsTable->item(i, 0)->text());
    }

    m_applet->config().writeEntry("format", m_appearanceUi.themesView->currentIndex().data(IdRole).toString());
    m_applet->config().writeEntry("clipboardFormats", clipboardFormats);
    m_applet->config().writeEntry("fastCopyFormat", m_clipboardUi.fastCopyFormatEdit->text());

    static_cast<KConfigDialog*>(parent())->enableButtonApply(false);

    emit accepted();
}

void Configuration::modify()
{
    static_cast<KConfigDialog*>(parent())->enableButtonApply(true);
}

void Configuration::enableUpdates()
{
    connect(m_appearanceUi.webView->page(), SIGNAL(contentsChanged()), this, SLOT(themeChanged()));
    connect(m_appearanceUi.htmlTextEdit, SIGNAL(textChanged()), this, SLOT(themeChanged()));
    connect(m_appearanceUi.cssTextEdit, SIGNAL(textChanged()), this, SLOT(themeChanged()));
    connect(m_appearanceUi.backgroundButton, SIGNAL(clicked()), this, SLOT(backgroundChanged()));
}

void Configuration::disableUpdates()
{
    disconnect(m_appearanceUi.webView->page(), SIGNAL(contentsChanged()), this, SLOT(themeChanged()));
    disconnect(m_appearanceUi.htmlTextEdit, SIGNAL(textChanged()), this, SLOT(themeChanged()));
    disconnect(m_appearanceUi.cssTextEdit, SIGNAL(textChanged()), this, SLOT(themeChanged()));
    disconnect(m_appearanceUi.backgroundButton, SIGNAL(clicked()), this, SLOT(backgroundChanged()));
}

void Configuration::insertPlaceholder()
{
    connect(new PlaceholderDialog(m_appearanceUi.placeholdersButton), SIGNAL(insertPlaceholder(QString)), this, SLOT(insertPlaceholder(QString)));
}

void Configuration::insertPlaceholder(const QString &placeholder)
{
    if (m_appearanceUi.editorTabWidget->currentIndex() > 0) {
        m_appearanceUi.htmlTextEdit->insertPlainText(placeholder);
    } else {
        m_appearanceUi.webView->page()->mainFrame()->evaluateJavaScript(QLatin1String("document.execCommand('inserthtml', false, '") + Applet::evaluateFormat(placeholder, QDateTime(QDate(2000, 1, 1), QTime(12, 30, 15)), true) + QLatin1String("')"));
    }
}

void Configuration::selectTheme(const QModelIndex &index)
{
    if (m_appearanceUi.themesView->selectionModel()->hasSelection()) {
        modify();
    }

    disableUpdates();

    m_appearanceUi.htmlTextEdit->setPlainText(index.data(HtmlRole).toString());
    m_appearanceUi.cssTextEdit->setPlainText(index.data(CssRole).toString());
    m_appearanceUi.scriptTextEdit->setPlainText(index.data(ScriptRole).toString());
    m_appearanceUi.backgroundButton->setChecked(index.data(BackgroundRole).toBool());
    m_appearanceUi.deleteButton->setEnabled(!index.data(BundledRole).toBool());
    m_appearanceUi.renameButton->setEnabled(!index.data(BundledRole).toBool());

    sourceChanged();
    enableUpdates();
}

void Configuration::newTheme(bool automatically)
{
    QString title = m_appearanceUi.themesView->currentIndex().data(TitleRole).toString();

    if (automatically) {
        int i = 2;

        while (findRow(QString(QLatin1String("%1 %2")).arg(title).arg(i)) >= 0) {
            ++i;
        }

        title = QString(QLatin1String("%1 %2")).arg(title).arg(i);
    } else {
        bool ok;

        title = KInputDialog::getText(i18n("Add new theme"), i18n("Theme name:"), title, &ok);

        if (!ok) {
            return;
        }
    }

    if (findRow(title) >= 0) {
        KMessageBox::error(m_appearanceUi.themesView, i18n("A theme with this name already exists."));

        return;
    }

    if (title.startsWith(QLatin1Char('%')) && title.endsWith(QLatin1Char('%'))) {
        KMessageBox::error(m_appearanceUi.themesView, i18n("Invalid theme name."));

        return;
    }

    if (title.isEmpty()) {
        return;
    }

    disconnect(m_appearanceUi.themesView, SIGNAL(clicked(QModelIndex)), this, SLOT(selectTheme(QModelIndex)));

    m_themesModel->insertRow(m_themesModel->rowCount());

    const QModelIndex index = m_themesModel->index((m_themesModel->rowCount() - 1), 0);

    m_themesModel->setData(index, title, IdRole);
    m_themesModel->setData(index, title, TitleRole);
    m_themesModel->setData(index, (QLatin1String("<b>") + title + QLatin1String("</b>")), Qt::ToolTipRole);
    m_themesModel->setData(index, m_appearanceUi.htmlTextEdit->toPlainText(), HtmlRole);
    m_themesModel->setData(index, m_appearanceUi.cssTextEdit->toPlainText(), CssRole);
    m_themesModel->setData(index, m_appearanceUi.scriptTextEdit->toPlainText(), ScriptRole);
    m_themesModel->setData(index, m_appearanceUi.backgroundButton->isChecked(), BackgroundRole);
    m_themesModel->setData(index, false, BundledRole);

    m_appearanceUi.themesView->setCurrentIndex(index);

    modify();

    connect(m_appearanceUi.themesView, SIGNAL(clicked(QModelIndex)), this, SLOT(selectTheme(QModelIndex)));
}

void Configuration::deleteTheme()
{
    if (!m_appearanceUi.themesView->currentIndex().data(BundledRole).toBool() && KMessageBox::questionYesNo(m_appearanceUi.themesView, i18n("Do you really want to delete theme \"%1\"?").arg(m_appearanceUi.themesView->currentIndex().data(TitleRole).toString()), i18n("Delete Theme")) == KMessageBox::Yes) {
        const int row = m_appearanceUi.themesView->currentIndex().row();

        m_themesModel->removeRow(row);

        selectTheme(m_themesModel->index(qMax((row - 1), 0), 0));
    }
}

void Configuration::renameTheme()
{
    bool ok;
    const QString title = KInputDialog::getText(i18n("Add new theme"), i18n("Theme name:"), m_appearanceUi.themesView->currentIndex().data(TitleRole).toString(), &ok);

    if (!ok) {
        return;
    }

    if (findRow(title) >= 0) {
        KMessageBox::error(m_appearanceUi.themesView, i18n("A theme with this name already exists."));

        return;
    }

    m_themesModel->setData(m_appearanceUi.themesView->currentIndex(), title, TitleRole);

    modify();

    emit clearCache();
}

void Configuration::updateTheme(const Theme &theme)
{
    const QModelIndex index = m_appearanceUi.themesView->currentIndex();

    m_themesModel->setData(index, theme.html, HtmlRole);
    m_themesModel->setData(index, theme.css, CssRole);
    m_themesModel->setData(index, theme.script, ScriptRole);
    m_themesModel->setData(index, theme.background, BackgroundRole);

    emit clearCache();
}

void Configuration::updateView(int tab)
{
    if (tab == 1 && m_appearanceUi.editorTabWidget->currentIndex() == 0) {
        QMouseEvent event(QEvent::MouseButtonPress, QPoint(5, 5), Qt::LeftButton, Qt::LeftButton, 0);

        QCoreApplication::sendEvent(m_appearanceUi.webView, &event);

        m_appearanceUi.webView->setFocus(Qt::OtherFocusReason);
    }

    updateEditor(m_appearanceUi.editorTabWidget->currentIndex() ? 0 : 1);
}

void Configuration::updateEditor(int tab)
{
    if (tab) {
        richTextChanged();
    } else {
        sourceChanged();
    }
}

void Configuration::triggerAction()
{
    if (m_appearanceUi.editorTabWidget->currentIndex() == 0) {
        return;
    }

    QString actionName = sender()->objectName().remove(QLatin1String("Button")).toLower();
    QHash<QString, QWebPage::WebAction> actions;
    actions[QLatin1String("bold")] = QWebPage::ToggleBold;
    actions[QLatin1String("italic")] = QWebPage::ToggleItalic;
    actions[QLatin1String("underline")] = QWebPage::ToggleUnderline;
    actions[QLatin1String("justifyLeft")] = QWebPage::AlignLeft;
    actions[QLatin1String("justifyCenter")] = QWebPage::AlignCenter;
    actions[QLatin1String("justifyRight")] = QWebPage::AlignRight;

    if (!actions.contains(actionName)) {
        return;
    }

    QTextCursor cursor = m_appearanceUi.htmlTextEdit->textCursor();

    switch (actions[actionName]) {
    case QWebPage::ToggleBold:
        cursor.insertText(QLatin1String("<b>") + cursor.selectedText() + QLatin1String("</b>"));

        break;
    case QWebPage::ToggleItalic:
        cursor.insertText(QLatin1String("<i>") + cursor.selectedText() + QLatin1String("</i>"));

        break;
    case QWebPage::ToggleUnderline:
        cursor.insertText(QLatin1String("<u>") + cursor.selectedText() + QLatin1String("</u>"));

        break;
    case QWebPage::AlignLeft:
        cursor.insertText(QLatin1String("<div style=\"text-align:left;\">") + cursor.selectedText() + QLatin1String("</div>"));

        break;
    case QWebPage::AlignCenter:
        cursor.insertText(QLatin1String("<div style=\"text-align:center;\">") + cursor.selectedText() + QLatin1String("</div>"));

        break;
    case QWebPage::AlignRight:
        cursor.insertText(QLatin1String("<div style=\"text-align:right;\">") + cursor.selectedText() + QLatin1String("</div>"));

        break;
    default:
        return;
    }

    m_appearanceUi.htmlTextEdit->setTextCursor(cursor);
}

void Configuration::fixSelection()
{
    m_appearanceUi.webView->page()->mainFrame()->evaluateJavaScript(QLatin1String("fixSelection()"));
}

void Configuration::selectColor()
{
    KColorDialog colorDialog;
    colorDialog.setAlphaChannelEnabled(true);
    colorDialog.setColor(m_appearanceUi.colorButton->palette().button().color());
    colorDialog.setButtons(KDialog::Ok | KDialog::Cancel);

    if (colorDialog.exec() == QDialog::Accepted) {
        QPalette palette = m_appearanceUi.colorButton->palette();
        palette.setBrush(QPalette::Button, colorDialog.color());

        m_appearanceUi.colorButton->setPalette(palette);

        if (m_appearanceUi.editorTabWidget->currentIndex() > 0) {
            QTextCursor cursor = m_appearanceUi.htmlTextEdit->textCursor();
            cursor.insertText(QLatin1String("<span style=\"color:") + colorDialog.color().name() + QLatin1String(";\">") + cursor.selectedText() + QLatin1String("</span>"));

            m_appearanceUi.htmlTextEdit->setTextCursor(cursor);
        } else {
            m_appearanceUi.webView->page()->mainFrame()->evaluateJavaScript(QLatin1String("document.execCommand('forecolor', false, '") + colorDialog.color().name() + QLatin1String("')"));
        }
    }
}

void Configuration::selectFontSize(const QString &size)
{
    if (m_appearanceUi.editorTabWidget->currentIndex() > 0) {
        QTextCursor cursor = m_appearanceUi.htmlTextEdit->textCursor();
        cursor.insertText(QLatin1String("<span style=\"font-size:") + QString::number(size.toInt()) + QLatin1String("px;\">") + cursor.selectedText() + QLatin1String("</span>"));

        m_appearanceUi.htmlTextEdit->setTextCursor(cursor);
    } else {
        m_appearanceUi.webView->page()->mainFrame()->evaluateJavaScript(QLatin1String("document.execCommand('fontsizedelta', false, ") + QString::number(size.toInt() - m_fontSize) + QLatin1String(")"));
    }

    m_fontSize = size.toInt();
}

void Configuration::selectFontFamily(const QFont &font)
{
    if (m_appearanceUi.editorTabWidget->currentIndex() > 0) {
        QTextCursor cursor = m_appearanceUi.htmlTextEdit->textCursor();
        cursor.insertText(QLatin1String("<span style=\"font-family:'") + font.family()+ QLatin1String("';\">") + cursor.selectedText() + QLatin1String("</span>"));

        m_appearanceUi.htmlTextEdit->setTextCursor(cursor);
    } else {
        m_appearanceUi.webView->page()->mainFrame()->evaluateJavaScript(QLatin1String("document.execCommand('fontname', false, '") + font.family() + QLatin1String("')"));
    }
}

void Configuration::setColor(const QString &color)
{
    if (color == QLatin1String("false")) {
        return;
    }

    QRegExp expression = QRegExp(QLatin1String("rgb\\((\\d+), (\\d+), (\\d+)\\)"));
    expression.indexIn(color);

    const QStringList rgb = expression.capturedTexts();

    QPalette palette = m_appearanceUi.colorButton->palette();
    palette.setBrush(QPalette::Button, QColor(rgb.at(1).toInt(), rgb.at(2).toInt(), rgb.at(3).toInt()));

    m_appearanceUi.colorButton->setPalette(palette);
}

void Configuration::setFontSize(const QString &size)
{
    if (!m_appearanceUi.fontSizeComboBox->hasFocus()) {
        m_appearanceUi.fontSizeComboBox->setEditText(size);
    }

    m_fontSize = size.toInt();
}

void Configuration::setFontFamily(const QString &font)
{
    m_appearanceUi.fontFamilyComboBox->setCurrentFont(QFont(font));
}

void Configuration::setZoom(int zoom)
{
    m_appearanceUi.webView->setZoomFactor((qreal) zoom / 100);
    m_appearanceUi.zoomSlider->setToolTip(i18n("Zoom: %1%").arg(zoom));
}

void Configuration::showEditorContextMenu(const QPoint &position)
{
    KMenu menu(m_appearanceUi.webView);
    menu.addAction(m_appearanceUi.webView->page()->action(QWebPage::Undo));
    menu.addAction(m_appearanceUi.webView->page()->action(QWebPage::Redo));
    menu.addSeparator();
    menu.addAction(m_appearanceUi.webView->page()->action(QWebPage::Cut));
    menu.addAction(m_appearanceUi.webView->page()->action(QWebPage::Copy));
    menu.addAction(m_appearanceUi.webView->page()->action(QWebPage::Paste));
    menu.addAction(m_appearanceUi.webView->page()->action(QWebPage::SelectAll));
    menu.addSeparator();
    menu.addAction(m_appearanceUi.boldButton->defaultAction());
    menu.addAction(m_appearanceUi.italicButton->defaultAction());
    menu.addAction(m_appearanceUi.underlineButton->defaultAction());
    menu.addSeparator();
    menu.addAction(m_appearanceUi.justifyLeftButton->defaultAction());
    menu.addAction(m_appearanceUi.justifyCenterButton->defaultAction());
    menu.addAction(m_appearanceUi.justifyRightButton->defaultAction());
    menu.exec(m_appearanceUi.webView->mapToGlobal(position));
}

void Configuration::themeChanged()
{
    modify();

    if (m_appearanceUi.themesView->currentIndex().data(BundledRole).toBool()) {
        newTheme(true);
    }
}

void Configuration::backgroundChanged()
{
    Theme theme;
    theme.html = m_appearanceUi.htmlTextEdit->toPlainText();
    theme.css = m_appearanceUi.cssTextEdit->toPlainText();
    theme.background = m_appearanceUi.backgroundButton->isChecked();

    themeChanged();
    updateTheme(theme);
}

void Configuration::richTextChanged()
{
    QRegExp fontColor = QRegExp(QLatin1String("<font color=\"(#?[\\w\\s]+)\">(.+)</font>"));
    fontColor.setMinimal(true);

    QRegExp fontFamily = QRegExp(QLatin1String("<font face=\"'?([\\w\\s]+)'?\">(.+)</font>"));
    fontFamily.setMinimal(true);

    QRegExp placeholder = QRegExp(QLatin1String("<placeholder.+alt=\"([^\"]+)\">.*((?=<).*>)?.*<fix>.+</fix>.*((?=<).*>)?.*</placeholder>"));
    placeholder.setMinimal(true);

    QRegExp page = QRegExp(QLatin1String("<!DOCTYPE html><html><head>.+</head><body><div>(.+)</div></body></html>"));
    page.setMinimal(true);

    QRegExp css = QRegExp(QLatin1String("<style type=\"text/css\">(.+)</style>"));
    css.setMinimal(true);
    css.indexIn(m_appearanceUi.webView->page()->mainFrame()->toHtml());

    QRegExp script = QRegExp(QLatin1String("<script type=\"text/javascript\">(.*)</script><script"));
    script.setMinimal(true);
    script.indexIn(m_appearanceUi.webView->page()->mainFrame()->toHtml());

    Theme theme;
    theme.html = m_appearanceUi.webView->page()->mainFrame()->toHtml().remove(QRegExp(QLatin1String(" class=\"Apple-style-span\""))).replace(page, QLatin1String("\\1")).replace(placeholder, QLatin1String("\\2\\1\\3")).replace(fontColor, QLatin1String("<span style=\"color:\\1;\">\\2</span>")).replace(fontFamily, QLatin1String("<span style=\"font-family:'\\1';\">\\2</span>"));
    theme.css = css.cap(1).remove(QLatin1String("* {font-family: sans, '") + Plasma::Theme::defaultTheme()->font(Plasma::Theme::DefaultFont).family() + QLatin1String("'; color: ") + Plasma::Theme::defaultTheme()->color(Plasma::Theme::TextColor).name() + QLatin1String(";} html, body, body > div {margin: 0; padding: 0; height: 100%; width: 100%; vertical-align: middle;} body {display: table;} body > div {display: table-cell;}") + QLatin1String(PLACEHOLDERSTYLE));
    theme.script = script.cap(1).replace(placeholder, QLatin1String("\\2\\1\\3"));
    theme.background = m_appearanceUi.backgroundButton->isChecked();

    disableUpdates();

    m_appearanceUi.htmlTextEdit->setPlainText(theme.html);
    m_appearanceUi.cssTextEdit->setPlainText(theme.css);
    m_appearanceUi.scriptTextEdit->setPlainText(theme.script);

    enableUpdates();
    updateTheme(theme);
}

void Configuration::sourceChanged()
{
    Theme theme;
    theme.html = m_appearanceUi.htmlTextEdit->toPlainText();
    theme.css = m_appearanceUi.cssTextEdit->toPlainText();
    theme.script = m_appearanceUi.scriptTextEdit->toPlainText();
    theme.background = m_appearanceUi.backgroundButton->isChecked();

    disableUpdates();

    m_appearanceUi.webView->page()->mainFrame()->setHtml(Applet::pageLayout(Applet::evaluateFormat(theme.html, QDateTime(QDate(2000, 1, 1), QTime(12, 30, 15)), true), (QLatin1String(PLACEHOLDERSTYLE) + theme.css), theme.script, QLatin1String("<script type=\"text/javascript\" src=\"qrc:/editor.js\"></script>")));

    enableUpdates();
    updateTheme(theme);
}

void Configuration::itemSelectionChanged()
{
    const QList<QTableWidgetItem*> selectedItems = m_clipboardUi.clipboardActionsTable->selectedItems();

    m_clipboardUi.moveUpButton->setEnabled(!selectedItems.isEmpty() && m_clipboardUi.clipboardActionsTable->row(selectedItems.first()) != 0);
    m_clipboardUi.moveDownButton->setEnabled(!selectedItems.isEmpty() && m_clipboardUi.clipboardActionsTable->row(selectedItems.last()) != (m_clipboardUi.clipboardActionsTable->rowCount() - 1));
    m_clipboardUi.editButton->setEnabled(!selectedItems.isEmpty());
    m_clipboardUi.deleteButton->setEnabled(!selectedItems.isEmpty());
}

void Configuration::editRow(QTableWidgetItem *item)
{
    if (m_editedItem) {
        m_clipboardUi.clipboardActionsTable->closePersistentEditor(m_editedItem);
    }

    if (!item) {
        item = m_clipboardUi.clipboardActionsTable->currentItem();
    }

    if (!item) {
        return;
    }

    if (item->column() == 1) {
        item = m_clipboardUi.clipboardActionsTable->item(item->row(), 0);
    }

    m_editedItem = item;

    modify();

    m_clipboardUi.clipboardActionsTable->openPersistentEditor(m_editedItem);
}

void Configuration::insertRow()
{
    const int row = ((m_clipboardUi.clipboardActionsTable->rowCount() && m_clipboardUi.clipboardActionsTable->currentRow() >= 0) ? m_clipboardUi.clipboardActionsTable->currentRow() : 0);
    QTableWidgetItem *item = new QTableWidgetItem(QString());
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled);

    m_clipboardUi.clipboardActionsTable->insertRow(row);
    m_clipboardUi.clipboardActionsTable->setItem(row, 0, item);

    editRow(item);

    item = new QTableWidgetItem(QString());
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    m_clipboardUi.clipboardActionsTable->setItem(row, 1, item);
    m_clipboardUi.clipboardActionsTable->setCurrentCell(row, 0);

    modify();
}

void Configuration::deleteRow()
{
    m_clipboardUi.clipboardActionsTable->removeRow(m_clipboardUi.clipboardActionsTable->row(m_clipboardUi.clipboardActionsTable->selectedItems().at(0)));

    modify();
}

void Configuration::moveRow(bool up)
{
    int sourceRow = m_clipboardUi.clipboardActionsTable->row(m_clipboardUi.clipboardActionsTable->selectedItems().at(0));
    int destinationRow = (up ? (sourceRow - 1) : (sourceRow + 1));

    QList<QTableWidgetItem*> sourceItems;
    QList<QTableWidgetItem*> destinationItems;

    for (int i = 0; i < 2; ++i) {
        sourceItems.append(m_clipboardUi.clipboardActionsTable->takeItem(sourceRow, i));

        destinationItems.append(m_clipboardUi.clipboardActionsTable->takeItem(destinationRow, i));
    }

    for (int i = 0; i < 2; ++i) {
        m_clipboardUi.clipboardActionsTable->setItem(sourceRow, i, destinationItems.at(i));
        m_clipboardUi.clipboardActionsTable->setItem(destinationRow, i, sourceItems.at(i));
    }

    m_clipboardUi.clipboardActionsTable->setCurrentCell(destinationRow, 0);

    modify();
}

void Configuration::moveRowUp()
{
    moveRow(true);
}

void Configuration::moveRowDown()
{
    moveRow(false);
}

void Configuration::updateRow(int row)
{
    if (!m_clipboardUi.clipboardActionsTable->item(row, 1)) {
        return;
    }

    const QString preview = m_applet->evaluateFormat(m_clipboardUi.clipboardActionsTable->item(row, 0)->text(), QDateTime::currentDateTime());

    m_clipboardUi.clipboardActionsTable->item(row, 1)->setText(preview);
    m_clipboardUi.clipboardActionsTable->item(row, 1)->setToolTip(preview);
}

int Configuration::findRow(const QString &text, int role)
{
    for (int i = 0; i < m_themesModel->rowCount(); ++i) {
        if (m_themesModel->index(i, 0).data(role).toString() == text) {
            return i;
        }
    }

    return -1;
}

bool Configuration::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && m_editedItem) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        if (m_clipboardUi.clipboardActionsTable->itemAt(mouseEvent->pos()) != m_editedItem) {
            m_clipboardUi.clipboardActionsTable->closePersistentEditor(m_editedItem);
        }
    } else if (event->type() == QEvent::MouseButtonDblClick) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        if (!m_clipboardUi.clipboardActionsTable->itemAt(mouseEvent->pos())) {
            insertRow();
        }
    }

    return QObject::eventFilter(object, event);
}

}