#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'appearance.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPEARANCE_H
#define UI_APPEARANCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>
#include "kcombobox.h"
#include "ktabwidget.h"
#include "ktextedit.h"

QT_BEGIN_NAMESPACE

class Ui_appearance
{
public:
    QVBoxLayout *verticalLayout;
    KTabWidget *mainTabWidget;
    QWidget *themeTab;
    QVBoxLayout *verticalLayout_3;
    QListView *themesView;
    QHBoxLayout *buttonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *newButton;
    QPushButton *renameButton;
    QPushButton *deleteButton;
    QWidget *detailsTab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *controlslLayout;
    QToolButton *boldButton;
    QToolButton *italicButton;
    QToolButton *underlineButton;
    QFrame *line;
    QToolButton *justifyLeftButton;
    QToolButton *justifyCenterButton;
    QToolButton *justifyRightButton;
    QFrame *line_2;
    QToolButton *colorButton;
    QToolButton *backgroundButton;
    QFrame *line_3;
    KComboBox *fontSizeComboBox;
    QFontComboBox *fontFamilyComboBox;
    QFrame *line_4;
    QToolButton *placeholdersButton;
    KTabWidget *editorTabWidget;
    QWidget *richTextTab;
    QVBoxLayout *richTextLayout;
    QWebView *webView;
    QFrame *webViewLine;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *sliderSpacer;
    QSlider *zoomSlider;
    QWidget *sourceTab;
    QVBoxLayout *sourceLayout;
    QSplitter *splitter;
    KTextEdit *htmlTextEdit;
    KTextEdit *cssTextEdit;
    KTextEdit *scriptTextEdit;

    void setupUi(QWidget *appearance)
    {
        if (appearance->objectName().isEmpty())
            appearance->setObjectName(QString::fromUtf8("appearance"));
        appearance->resize(597, 332);
        verticalLayout = new QVBoxLayout(appearance);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mainTabWidget = new KTabWidget(appearance);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        themeTab = new QWidget();
        themeTab->setObjectName(QString::fromUtf8("themeTab"));
        verticalLayout_3 = new QVBoxLayout(themeTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        themesView = new QListView(themeTab);
        themesView->setObjectName(QString::fromUtf8("themesView"));
        themesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        themesView->setProperty("showDropIndicator", QVariant(false));

        verticalLayout_3->addWidget(themesView);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonsLayout->addItem(horizontalSpacer);

        newButton = new QPushButton(themeTab);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        buttonsLayout->addWidget(newButton);

        renameButton = new QPushButton(themeTab);
        renameButton->setObjectName(QString::fromUtf8("renameButton"));

        buttonsLayout->addWidget(renameButton);

        deleteButton = new QPushButton(themeTab);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        buttonsLayout->addWidget(deleteButton);


        verticalLayout_3->addLayout(buttonsLayout);

        mainTabWidget->addTab(themeTab, QString());
        detailsTab = new QWidget();
        detailsTab->setObjectName(QString::fromUtf8("detailsTab"));
        verticalLayout_2 = new QVBoxLayout(detailsTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        controlslLayout = new QHBoxLayout();
        controlslLayout->setObjectName(QString::fromUtf8("controlslLayout"));
        boldButton = new QToolButton(detailsTab);
        boldButton->setObjectName(QString::fromUtf8("boldButton"));
        boldButton->setCheckable(true);

        controlslLayout->addWidget(boldButton);

        italicButton = new QToolButton(detailsTab);
        italicButton->setObjectName(QString::fromUtf8("italicButton"));
        italicButton->setCheckable(true);

        controlslLayout->addWidget(italicButton);

        underlineButton = new QToolButton(detailsTab);
        underlineButton->setObjectName(QString::fromUtf8("underlineButton"));
        underlineButton->setCheckable(true);

        controlslLayout->addWidget(underlineButton);

        line = new QFrame(detailsTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        controlslLayout->addWidget(line);

        justifyLeftButton = new QToolButton(detailsTab);
        justifyLeftButton->setObjectName(QString::fromUtf8("justifyLeftButton"));
        justifyLeftButton->setCheckable(false);

        controlslLayout->addWidget(justifyLeftButton);

        justifyCenterButton = new QToolButton(detailsTab);
        justifyCenterButton->setObjectName(QString::fromUtf8("justifyCenterButton"));
        justifyCenterButton->setCheckable(false);

        controlslLayout->addWidget(justifyCenterButton);

        justifyRightButton = new QToolButton(detailsTab);
        justifyRightButton->setObjectName(QString::fromUtf8("justifyRightButton"));
        justifyRightButton->setCheckable(false);

        controlslLayout->addWidget(justifyRightButton);

        line_2 = new QFrame(detailsTab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        controlslLayout->addWidget(line_2);

        colorButton = new QToolButton(detailsTab);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        controlslLayout->addWidget(colorButton);

        backgroundButton = new QToolButton(detailsTab);
        backgroundButton->setObjectName(QString::fromUtf8("backgroundButton"));
        backgroundButton->setCheckable(true);
        backgroundButton->setChecked(true);

        controlslLayout->addWidget(backgroundButton);

        line_3 = new QFrame(detailsTab);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        controlslLayout->addWidget(line_3);

        fontSizeComboBox = new KComboBox(detailsTab);
        fontSizeComboBox->insertItems(0, QStringList()
         << QString::fromUtf8("10")
         << QString::fromUtf8("13")
         << QString::fromUtf8("16")
         << QString::fromUtf8("18")
         << QString::fromUtf8("24")
         << QString::fromUtf8("32")
         << QString::fromUtf8("48")
        );
        fontSizeComboBox->setObjectName(QString::fromUtf8("fontSizeComboBox"));
        fontSizeComboBox->setMaximumSize(QSize(60, 16777215));
        fontSizeComboBox->setEditable(true);

        controlslLayout->addWidget(fontSizeComboBox);

        fontFamilyComboBox = new QFontComboBox(detailsTab);
        fontFamilyComboBox->setObjectName(QString::fromUtf8("fontFamilyComboBox"));

        controlslLayout->addWidget(fontFamilyComboBox);

        line_4 = new QFrame(detailsTab);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        controlslLayout->addWidget(line_4);

        placeholdersButton = new QToolButton(detailsTab);
        placeholdersButton->setObjectName(QString::fromUtf8("placeholdersButton"));
        placeholdersButton->setPopupMode(QToolButton::InstantPopup);

        controlslLayout->addWidget(placeholdersButton);


        verticalLayout_2->addLayout(controlslLayout);

        editorTabWidget = new KTabWidget(detailsTab);
        editorTabWidget->setObjectName(QString::fromUtf8("editorTabWidget"));
        editorTabWidget->setTabPosition(QTabWidget::West);
        richTextTab = new QWidget();
        richTextTab->setObjectName(QString::fromUtf8("richTextTab"));
        richTextLayout = new QVBoxLayout(richTextTab);
        richTextLayout->setSpacing(0);
        richTextLayout->setContentsMargins(0, 0, 0, 0);
        richTextLayout->setObjectName(QString::fromUtf8("richTextLayout"));
        webView = new QWebView(richTextTab);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setContextMenuPolicy(Qt::CustomContextMenu);
        webView->setRenderHints(QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        richTextLayout->addWidget(webView);

        webViewLine = new QFrame(richTextTab);
        webViewLine->setObjectName(QString::fromUtf8("webViewLine"));
        webViewLine->setFrameShape(QFrame::HLine);
        webViewLine->setFrameShadow(QFrame::Sunken);

        richTextLayout->addWidget(webViewLine);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sliderSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(sliderSpacer);

        zoomSlider = new QSlider(richTextTab);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setMinimum(5);
        zoomSlider->setMaximum(500);
        zoomSlider->setValue(100);
        zoomSlider->setOrientation(Qt::Horizontal);
        zoomSlider->setTickPosition(QSlider::TicksBelow);
        zoomSlider->setTickInterval(100);

        horizontalLayout->addWidget(zoomSlider);


        richTextLayout->addLayout(horizontalLayout);

        editorTabWidget->addTab(richTextTab, QString());
        sourceTab = new QWidget();
        sourceTab->setObjectName(QString::fromUtf8("sourceTab"));
        sourceLayout = new QVBoxLayout(sourceTab);
        sourceLayout->setObjectName(QString::fromUtf8("sourceLayout"));
        splitter = new QSplitter(sourceTab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        htmlTextEdit = new KTextEdit(splitter);
        htmlTextEdit->setObjectName(QString::fromUtf8("htmlTextEdit"));
        htmlTextEdit->setAcceptRichText(false);
        splitter->addWidget(htmlTextEdit);
        cssTextEdit = new KTextEdit(splitter);
        cssTextEdit->setObjectName(QString::fromUtf8("cssTextEdit"));
        cssTextEdit->setAcceptRichText(false);
        splitter->addWidget(cssTextEdit);
        scriptTextEdit = new KTextEdit(splitter);
        scriptTextEdit->setObjectName(QString::fromUtf8("scriptTextEdit"));
        scriptTextEdit->setAcceptRichText(false);
        splitter->addWidget(scriptTextEdit);

        sourceLayout->addWidget(splitter);

        editorTabWidget->addTab(sourceTab, QString());

        verticalLayout_2->addWidget(editorTabWidget);

        mainTabWidget->addTab(detailsTab, QString());

        verticalLayout->addWidget(mainTabWidget);


        retranslateUi(appearance);

        mainTabWidget->setCurrentIndex(0);
        editorTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(appearance);
    } // setupUi

    void retranslateUi(QWidget *appearance)
    {
        appearance->setWindowTitle(tr2i18n("Appearance", 0));
        newButton->setText(tr2i18n("New...", 0));
        renameButton->setText(tr2i18n("Rename...", 0));
        deleteButton->setText(tr2i18n("Delete...", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(themeTab), tr2i18n("Theme", 0));
#ifndef UI_QT_NO_TOOLTIP
        boldButton->setToolTip(tr2i18n("Bold", 0));
#endif // QT_NO_TOOLTIP
        boldButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        italicButton->setToolTip(tr2i18n("Italic", 0));
#endif // QT_NO_TOOLTIP
        italicButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        underlineButton->setToolTip(tr2i18n("Underline", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        justifyLeftButton->setToolTip(tr2i18n("Justify Left", 0));
#endif // QT_NO_TOOLTIP
        justifyLeftButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        justifyCenterButton->setToolTip(tr2i18n("Justify Center", 0));
#endif // QT_NO_TOOLTIP
        justifyCenterButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        justifyRightButton->setToolTip(tr2i18n("Justify Right", 0));
#endif // QT_NO_TOOLTIP
        justifyRightButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        colorButton->setToolTip(tr2i18n("Font Color", 0));
#endif // QT_NO_TOOLTIP
        colorButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        backgroundButton->setToolTip(tr2i18n("Use Standard Background", 0));
#endif // QT_NO_TOOLTIP
        backgroundButton->setText(QString());
#ifndef UI_QT_NO_TOOLTIP
        fontSizeComboBox->setToolTip(tr2i18n("Font Size", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        fontFamilyComboBox->setToolTip(tr2i18n("Font Family", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        placeholdersButton->setToolTip(tr2i18n("Insert Format Component...", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        zoomSlider->setToolTip(tr2i18n("Zoom: 100%", 0));
#endif // QT_NO_TOOLTIP
        editorTabWidget->setTabText(editorTabWidget->indexOf(richTextTab), tr2i18n("Rich text", 0));
#ifndef UI_QT_NO_TOOLTIP
        htmlTextEdit->setToolTip(tr2i18n("HTML", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        cssTextEdit->setToolTip(tr2i18n("CSS", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        scriptTextEdit->setToolTip(tr2i18n("JavaScript", 0));
#endif // QT_NO_TOOLTIP
        editorTabWidget->setTabText(editorTabWidget->indexOf(sourceTab), tr2i18n("Source", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(detailsTab), tr2i18n("Details", 0));
    } // retranslateUi

};

namespace Ui {
    class appearance: public Ui_appearance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // APPEARANCE_H

